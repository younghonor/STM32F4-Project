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
#include "cmsis_os.h"
#include "task.h"
#include "main.h"
#include "app_watchdog_task.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

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
osThreadId_t LedTaskHandle;
const osThreadAttr_t LedTask_attributes = {
  .name = "LedTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};

/* USER CODE END Variables */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

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
  /* Infinite loop */
  for (;;) {
    Watchdog_ReportAlive(xTaskGetCurrentTaskHandle());//提示找不到osGetThreadId函数，可能需要包含FreeRTOS.h头文件或者使用其他方式获取当前线程ID
    LL_GPIO_TogglePin(MTS_LED_G_GPIO_Port, MTS_LED_G_Pin);
    osDelay(1000);//HAL_Delay(1000);
    LL_GPIO_TogglePin(MTS_LED_R_GPIO_Port, MTS_LED_R_Pin);
    osDelay(1000);
    //HAL_Delay(10000);
  }
  /* USER CODE END 5 */
}


void MX_FREERTOS_Init(void)
{
    /* creation of LedTask */
    LedTaskHandle = osThreadNew(vStartLedTask, NULL, &LedTask_attributes);

    osThreadId_t watchdogTaskHandle = osThreadNew(vStartWatchdogTask, NULL, &(osThreadAttr_t){
      .name = "watchdogTask",
      .priority = osPriorityBelowNormal,
      .stack_size = 128
    });
}

/* USER CODE END Application */

