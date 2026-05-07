/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "semphr.h"
#include "app_watchdog_task.h"
#include "board_access_task.h"
#define LOG_TAG "FreeRTOS"
#include "elog.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
typedef StaticTask_t osStaticThreadDef_t;

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */
/* Definitions for LedTask */
const osThreadAttr_t LedTask_attributes = {
  .name = "LedTask",
  .stack_size = 512 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for elog */
osThreadId_t elogHandle;
uint32_t elogBuffer[ 256 ];//ELOG_LINE_BUF_SIZE*2*4 bytes
osStaticThreadDef_t elogControlBlock;
const osThreadAttr_t elog_attributes = {
  .name = "elog",
  .stack_mem = &elogBuffer[0],
  .stack_size = sizeof(elogBuffer),
  .cb_mem = &elogControlBlock,
  .cb_size = sizeof(elogControlBlock),
  .priority = (osPriority_t) osPriorityLow,
};
/* Definitions for BoardAccessTask */
osThreadId_t BoardAccessTaskHandle;
const osThreadAttr_t BoardAccessTask_attributes = {
  .name = "BoardAccess",
  .stack_size = 256 * 4,
  .priority = (osPriority_t) osPriorityAboveNormal,
};
/* Definitions for elog_lock */
osSemaphoreId_t elog_lockHandle;
const osSemaphoreAttr_t elog_lock_attributes = {
  .name = "elog_lock"
};
/* Definitions for elog_async */
osSemaphoreId_t elog_asyncHandle;
const osSemaphoreAttr_t elog_async_attributes = {
  .name = "elog_async"
};
/* Definitions for elog_dma_lock */
osSemaphoreId_t elog_dma_lockHandle;
const osSemaphoreAttr_t elog_dma_lock_attributes = {
  .name = "elog_dma_lock"
};
/* freertos.c */

/* USER CODE END Variables */
/* Definitions for DefaultTask */
osThreadId_t DefaultTaskHandle;
const osThreadAttr_t DefaultTask_attributes = {
  .name = "DefaultTask",
  .stack_size = 512 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
extern void elog_entry(void *argument);
void vStartLedTask(void *argument);

/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* Hook prototypes */
void vApplicationIdleHook(void);

/* USER CODE BEGIN 2 */
void vApplicationIdleHook( void )
{
   /* vApplicationIdleHook() will only be called if configUSE_IDLE_HOOK is set
   to 1 in FreeRTOSConfig.h. It will be called on each iteration of the idle
   task. It is essential that code added to this hook function never attempts
   to block in any way (for example, call xQueueReceive() with a block time
   specified, or call vTaskDelay()). If the application makes use of the
   vTaskDelete() API function (as this demo application does) then it is also
   important that vApplicationIdleHook() is permitted to return to its calling
   function, because it is the responsibility of the idle task to clean up
   memory allocated by the kernel to any task that has since been deleted. */
}
/* USER CODE END 2 */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* Create the semaphores(s) */
  /* creation of elog_lock */
  elog_lockHandle = osSemaphoreNew(1, 1, &elog_lock_attributes);

  /* creation of elog_async */
  elog_asyncHandle = osSemaphoreNew(1, 1, &elog_async_attributes);

  /* creation of elog_dma_lock */
  elog_dma_lockHandle = osSemaphoreNew(1, 1, &elog_dma_lock_attributes);

  Watchdog_Init();
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of DefaultTask */
  DefaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &DefaultTask_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* creation of LedTask */
  osThreadId_t LedTaskHandle = osThreadNew(vStartLedTask, NULL, &LedTask_attributes);

  /* creation of BoardAccessTask */
  BoardAccessTaskHandle = osThreadNew(vBoardAccessTask, NULL, &BoardAccessTask_attributes);

  osThreadId_t watchdogTaskHandle = osThreadNew(vStartWatchdogTask, NULL, &(osThreadAttr_t){
      .name = "watchdogTask",
      .priority = osPriorityBelowNormal,
      .stack_size = 512*4
    });

  /* creation of elog */
  elogHandle = osThreadNew(elog_entry, NULL, &elog_attributes);

  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the DefaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument)
{
  /* USER CODE BEGIN StartDefaultTask */
  Watchdog_RegisterTask(xTaskGetCurrentTaskHandle(),pcTaskGetTaskName(xTaskGetCurrentTaskHandle()));
  /* Infinite loop */
  for(;;)
  {
    Watchdog_ReportAlive(xTaskGetCurrentTaskHandle());
    osDelay(1000);
    log_e("running: default task");
  }
  /* USER CODE END StartDefaultTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */
/* USER CODE BEGIN Header_StartLedTask */
/**
  * @brief  Function implementing the LedTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartLedTask */
void vStartLedTask(void *argument)
{
  /* USER CODE BEGIN 5 */
  Watchdog_RegisterTask(xTaskGetCurrentTaskHandle(), pcTaskGetTaskName(xTaskGetCurrentTaskHandle()));
  /* Infinite loop */
  for (;;) {
    HAL_GPIO_TogglePin(MTS_LED_G_GPIO_Port, MTS_LED_G_Pin);
    Watchdog_ReportAlive(xTaskGetCurrentTaskHandle());
    osDelay(1000);//HAL_Delay(1000);
    HAL_GPIO_TogglePin(MTS_LED_R_GPIO_Port, MTS_LED_R_Pin);
    Watchdog_ReportAlive(xTaskGetCurrentTaskHandle());
    osDelay(1000);
	  log_i("running: led task");
  }
  /* USER CODE END 5 */
}



/* USER CODE END Application */

