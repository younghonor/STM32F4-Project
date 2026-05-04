#include "app_watchdog_task.h"
#include "main.h"
#include <stdint.h>
#include "FreeRTOS.h" // Ensure this line exists
#include "semphr.h"
#define MAX_TASK_CHECK 8

#define LOG_TAG "watchdog-task"
#include "elog.h"

typedef struct {
    osThreadId_t handle;
    TickType_t last_alive_tick;
    char *pcTaskName;
} task_watchdog_entry_t;

task_watchdog_entry_t g_watchdog_table[MAX_TASK_CHECK];

SemaphoreHandle_t watchdog_lockHandle; // Ensure you include this line if using semaphores
const osSemaphoreAttr_t watchdog_lock_attributes = {
  .name = "reg_watchdog_lock"
};

void Watchdog_Init(void){
    for (int i = 0; i < MAX_TASK_CHECK; i++) {
        g_watchdog_table[i].handle = NULL;
        g_watchdog_table[i].last_alive_tick = 0;
    }
    //watchdog_lockHandle = osSemaphoreCreate(osSemaphore, 1);
    watchdog_lockHandle = osSemaphoreNew(1, 1, &watchdog_lock_attributes);

}

void Watchdog_RegisterTask(osThreadId_t handle, char *pcTaskName) {
    //add mutex lock
    osSemaphoreAcquire(watchdog_lockHandle, osWaitForever);

    for (int i = 0; i < MAX_TASK_CHECK; i++) {
        if (g_watchdog_table[i].handle == NULL) {
            g_watchdog_table[i].handle = handle;
            g_watchdog_table[i].last_alive_tick = xTaskGetTickCount();
            g_watchdog_table[i].pcTaskName = pcTaskName;
            break;
        }
    }
    osSemaphoreRelease(watchdog_lockHandle);
}

void Watchdog_ReportAlive(osThreadId_t handle) {
    //osSemaphoreAcquire(watchdog_lockHandle, osWaitForever);
    for (int i = 0; i < MAX_TASK_CHECK; i++) {
        if (g_watchdog_table[i].handle == handle) {
            g_watchdog_table[i].last_alive_tick = xTaskGetTickCount();
            break;
        }
    }
    //osSemaphoreRelease(watchdog_lockHandle);
}

static uint8_t Watchdog_CheckAlive(void) {
    uint8_t all_alive = 1;
    for (int i = 0; i < MAX_TASK_CHECK; i++) {
        if (g_watchdog_table[i].handle == NULL)
            continue; // 跳过未注册的任务

        TickType_t current_tick = xTaskGetTickCount();
        if ((current_tick - g_watchdog_table[i].last_alive_tick) > pdMS_TO_TICKS(2000)) {
            log_e("Task '%s' is not alive! Last alive tick: %lu", g_watchdog_table[i].pcTaskName, g_watchdog_table[i].last_alive_tick);
            all_alive = 0; // 任务超过2秒没有报告还活着
            break;
        }
    }
    return all_alive;
}
extern IWDG_HandleTypeDef hiwdg;
void vStartWatchdogTask(void *argument) {

    for(;;) {
        //log_i("watchdog task running...");
        if (Watchdog_CheckAlive() == 0) {
            // 如果有任务没有报告还活着，可以选择重置系统或执行其他操作
            NVIC_SystemReset();
        }

        //LL_IWDG_ReloadCounter(IWDG);
        HAL_IWDG_Refresh(&hiwdg);
        osDelay(500); // 每500ms喂狗一次
    }
}