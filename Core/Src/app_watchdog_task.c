#include "app_watchdog_task.h"
#include "main.h"
#include <stdint.h>

#define MAX_TASK_CHECK 8

typedef struct {
    TaskHandle_t handle;
    TickType_t last_alive_tick;
} task_watchdog_entry_t;

task_watchdog_entry_t g_watchdog_table[MAX_TASK_CHECK];

void Watchdog_Init(void){
    for (int i = 0; i < MAX_TASK_CHECK; i++) {
        g_watchdog_table[i].handle = NULL;
        g_watchdog_table[i].last_alive_tick = 0;
    }
}

void Watchdog_ReportAlive(TaskHandle_t handle) {
    for (int i = 0; i < MAX_TASK_CHECK; i++) {
        if (g_watchdog_table[i].handle == handle) {
            g_watchdog_table[i].last_alive_tick = xTaskGetTickCount();
            break;
        }
    }
}

static uint8_t Watchdog_CheckAlive(void) {
    uint8_t all_alive = 1;
    for (int i = 0; i < MAX_TASK_CHECK; i++) {
        if (g_watchdog_table[i].handle == NULL) 
            continue; // 跳过未注册的任务

        TickType_t current_tick = xTaskGetTickCount();
        if ((current_tick - g_watchdog_table[i].last_alive_tick) > pdMS_TO_TICKS(2000)) {
            all_alive = 0; // 任务超过2秒没有报告还活着
            break;
        }
    }
    return all_alive;
}

void vStartWatchdogTask(void *argument) {
    // 定义看门狗任务的代码，例如：
    for(;;) {
        if (Watchdog_CheckAlive() == 0) {
            // 如果有任务没有报告还活着，可以选择重置系统或执行其他操作
            NVIC_SystemReset();
        }

        LL_IWDG_ReloadCounter(IWDG);
        osDelay(500); // 每500ms喂狗一次
    }
}
