/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

#include "stm32f4xx_ll_adc.h"
#include "stm32f4xx_ll_crc.h"
#include "stm32f4xx_ll_dma.h"
#include "stm32f4xx_ll_i2c.h"
#include "stm32f4xx_ll_iwdg.h"
#include "stm32f4xx_ll_rcc.h"
#include "stm32f4xx_ll_bus.h"
#include "stm32f4xx_ll_system.h"
#include "stm32f4xx_ll_exti.h"
#include "stm32f4xx_ll_cortex.h"
#include "stm32f4xx_ll_utils.h"
#include "stm32f4xx_ll_pwr.h"
#include "stm32f4xx_ll_rtc.h"
#include "stm32f4xx_ll_spi.h"
#include "stm32f4xx_ll_tim.h"
#include "stm32f4xx_ll_usart.h"
#include "stm32f4xx_ll_gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define MTS_GPIO1_Pin LL_GPIO_PIN_3
#define MTS_GPIO1_GPIO_Port GPIOE
#define MTS_GPIO3_Pin LL_GPIO_PIN_2
#define MTS_GPIO3_GPIO_Port GPIOE
#define MTS_GPIO5_Pin LL_GPIO_PIN_1
#define MTS_GPIO5_GPIO_Port GPIOE
#define MTS_GPIO7_Pin LL_GPIO_PIN_0
#define MTS_GPIO7_GPIO_Port GPIOE
#define MTS_IO_DIR2_Pin LL_GPIO_PIN_8
#define MTS_IO_DIR2_GPIO_Port GPIOB
#define MTS_LEAK_TEST_SEL2_Pin LL_GPIO_PIN_14
#define MTS_LEAK_TEST_SEL2_GPIO_Port GPIOG
#define MTS_LEAK_TEST_1_Pin LL_GPIO_PIN_13
#define MTS_LEAK_TEST_1_GPIO_Port GPIOG
#define MTS_SPI1_MISO_Pin LL_GPIO_PIN_4
#define MTS_SPI1_MISO_GPIO_Port GPIOB
#define MTS_SPI1_CLK_Pin LL_GPIO_PIN_3
#define MTS_SPI1_CLK_GPIO_Port GPIOB
#define MTS_GPIO0_Pin LL_GPIO_PIN_4
#define MTS_GPIO0_GPIO_Port GPIOE
#define MTS_GPIO2_Pin LL_GPIO_PIN_5
#define MTS_GPIO2_GPIO_Port GPIOE
#define MTS_GPIO4_Pin LL_GPIO_PIN_6
#define MTS_GPIO4_GPIO_Port GPIOE
#define MTS_GPIO6_Pin LL_GPIO_PIN_9
#define MTS_GPIO6_GPIO_Port GPIOB
#define MTS_BID0_Pin LL_GPIO_PIN_15
#define MTS_BID0_GPIO_Port GPIOG
#define MTS_BID1_Pin LL_GPIO_PIN_12
#define MTS_BID1_GPIO_Port GPIOG
#define MTS_BID2_Pin LL_GPIO_PIN_11
#define MTS_BID2_GPIO_Port GPIOG
#define MTS_IO_DIR4_Pin LL_GPIO_PIN_10
#define MTS_IO_DIR4_GPIO_Port GPIOG
#define MTS_USART3_RX_Pin LL_GPIO_PIN_11
#define MTS_USART3_RX_GPIO_Port GPIOC
#define MTS_USART3_TX_Pin LL_GPIO_PIN_10
#define MTS_USART3_TX_GPIO_Port GPIOC
#define MTS_TIM8_CH3_Pin LL_GPIO_PIN_7
#define MTS_TIM8_CH3_GPIO_Port GPIOI
#define MTS_TIM8_CH2_Pin LL_GPIO_PIN_6
#define MTS_TIM8_CH2_GPIO_Port GPIOI
#define MTS_TIM8_CH1_Pin LL_GPIO_PIN_5
#define MTS_TIM8_CH1_GPIO_Port GPIOI
#define MTS_Flash_SPI_CS_Pin LL_GPIO_PIN_9
#define MTS_Flash_SPI_CS_GPIO_Port GPIOG
#define MTS_SPI2_MOSI_Pin LL_GPIO_PIN_3
#define MTS_SPI2_MOSI_GPIO_Port GPIOI
#define MTS_TIM8_CH4_Pin LL_GPIO_PIN_2
#define MTS_TIM8_CH4_GPIO_Port GPIOI
#define MTS_HID0_Pin LL_GPIO_PIN_13
#define MTS_HID0_GPIO_Port GPIOC
#define MTS_IO_DIR0_Pin LL_GPIO_PIN_8
#define MTS_IO_DIR0_GPIO_Port GPIOI
#define MTS_IO_DIR1_Pin LL_GPIO_PIN_9
#define MTS_IO_DIR1_GPIO_Port GPIOI
#define MTS_IO_DIR3_Pin LL_GPIO_PIN_4
#define MTS_IO_DIR3_GPIO_Port GPIOI
#define MTS_IO_EN_Pin LL_GPIO_PIN_4
#define MTS_IO_EN_GPIO_Port GPIOD
#define MTS_LPC_nRST_Pin LL_GPIO_PIN_15
#define MTS_LPC_nRST_GPIO_Port GPIOH
#define MTS_SPI2_CLK_Pin LL_GPIO_PIN_1
#define MTS_SPI2_CLK_GPIO_Port GPIOI
#define MTS_TIM1_CH3_Pin LL_GPIO_PIN_10
#define MTS_TIM1_CH3_GPIO_Port GPIOA
#define MTS_HID1_Pin LL_GPIO_PIN_14
#define MTS_HID1_GPIO_Port GPIOC
#define MTS_I2C2_SDA_Pin LL_GPIO_PIN_0
#define MTS_I2C2_SDA_GPIO_Port GPIOF
#define MTS_IO_VCCB_DVDD_Pin LL_GPIO_PIN_10
#define MTS_IO_VCCB_DVDD_GPIO_Port GPIOI
#define MTS_LED_R_Pin LL_GPIO_PIN_13
#define MTS_LED_R_GPIO_Port GPIOH
#define MTS_LED_G_Pin LL_GPIO_PIN_14
#define MTS_LED_G_GPIO_Port GPIOH
#define MTS_SPI2_CS_Pin LL_GPIO_PIN_0
#define MTS_SPI2_CS_GPIO_Port GPIOI
#define MTS_HID2_Pin LL_GPIO_PIN_15
#define MTS_HID2_GPIO_Port GPIOC
#define MTS_I2C3_SDA_Pin LL_GPIO_PIN_9
#define MTS_I2C3_SDA_GPIO_Port GPIOC
#define MTS_I2C3_SCL_Pin LL_GPIO_PIN_8
#define MTS_I2C3_SCL_GPIO_Port GPIOA
#define MTS_RST_USB_HS_PHY_Pin LL_GPIO_PIN_3
#define MTS_RST_USB_HS_PHY_GPIO_Port GPIOH
#define MTS_DUT_RST_EN_Pin LL_GPIO_PIN_8
#define MTS_DUT_RST_EN_GPIO_Port GPIOC
#define MTS_VPP_OUT_Pin LL_GPIO_PIN_2
#define MTS_VPP_OUT_GPIO_Port GPIOF
#define MTS_I2C2_SCL_Pin LL_GPIO_PIN_1
#define MTS_I2C2_SCL_GPIO_Port GPIOF
#define MTS_DUT_SPI_CLK_DIR_Pin LL_GPIO_PIN_8
#define MTS_DUT_SPI_CLK_DIR_GPIO_Port GPIOG
#define MTS_EN_VPP_IN_Pin LL_GPIO_PIN_5
#define MTS_EN_VPP_IN_GPIO_Port GPIOH
#define MTS_DUT_SPI_SI_DIR_Pin LL_GPIO_PIN_7
#define MTS_DUT_SPI_SI_DIR_GPIO_Port GPIOG
#define MTS_MODULE_INT_Pin LL_GPIO_PIN_6
#define MTS_MODULE_INT_GPIO_Port GPIOG
#define MTS_LPC86_CS_Pin LL_GPIO_PIN_12
#define MTS_LPC86_CS_GPIO_Port GPIOH
#define MTS_LPC86_INT_Pin LL_GPIO_PIN_5
#define MTS_LPC86_INT_GPIO_Port GPIOG
#define MTS_DUT_SPI_SO_DIR_Pin LL_GPIO_PIN_4
#define MTS_DUT_SPI_SO_DIR_GPIO_Port GPIOG
#define MTS_MODULE_RST_Pin LL_GPIO_PIN_3
#define MTS_MODULE_RST_GPIO_Port GPIOG
#define MTS_LEAK_TEST_SEL3_Pin LL_GPIO_PIN_11
#define MTS_LEAK_TEST_SEL3_GPIO_Port GPIOH
#define MTS_LEAK_TEST_SEL4_Pin LL_GPIO_PIN_10
#define MTS_LEAK_TEST_SEL4_GPIO_Port GPIOH
#define MTS_SHIFTER1_VCCB_SW_Pin LL_GPIO_PIN_15
#define MTS_SHIFTER1_VCCB_SW_GPIO_Port GPIOD
#define MTS_IO_VCCB_VDDIO_Pin LL_GPIO_PIN_2
#define MTS_IO_VCCB_VDDIO_GPIO_Port GPIOG
#define MTS_VDDIO_I_READ_1_2_Pin LL_GPIO_PIN_1
#define MTS_VDDIO_I_READ_1_2_GPIO_Port GPIOG
#define MTS_VDDIO_I_SEL_2_Pin LL_GPIO_PIN_6
#define MTS_VDDIO_I_SEL_2_GPIO_Port GPIOH
#define MTS_VDDIO_I_SEL_1_Pin LL_GPIO_PIN_8
#define MTS_VDDIO_I_SEL_1_GPIO_Port GPIOH
#define MTS_VDDIIO_I_READ_3_Pin LL_GPIO_PIN_9
#define MTS_VDDIIO_I_READ_3_GPIO_Port GPIOH
#define MTS_DAC_BSY_Pin LL_GPIO_PIN_14
#define MTS_DAC_BSY_GPIO_Port GPIOD
#define MTS_DAC_LDAC_Pin LL_GPIO_PIN_13
#define MTS_DAC_LDAC_GPIO_Port GPIOD
#define MTS_SPI3_CS_Pin LL_GPIO_PIN_4
#define MTS_SPI3_CS_GPIO_Port GPIOA
#define MTS_AVDD_I_SEL_1_Pin LL_GPIO_PIN_13
#define MTS_AVDD_I_SEL_1_GPIO_Port GPIOF
#define MTS_DVDD_SW_Pin LL_GPIO_PIN_0
#define MTS_DVDD_SW_GPIO_Port GPIOG
#define MTS_VDDIO_SW_Pin LL_GPIO_PIN_13
#define MTS_VDDIO_SW_GPIO_Port GPIOE
#define MTS_DUT_SPI_EN__Pin LL_GPIO_PIN_7
#define MTS_DUT_SPI_EN__GPIO_Port GPIOH
#define MTS_I2C_EN_Pin LL_GPIO_PIN_12
#define MTS_I2C_EN_GPIO_Port GPIOD
#define MTS_REV_IO_0_Pin LL_GPIO_PIN_10
#define MTS_REV_IO_0_GPIO_Port GPIOD
#define MTS_AVDD_I_SEL_2_Pin LL_GPIO_PIN_12
#define MTS_AVDD_I_SEL_2_GPIO_Port GPIOF
#define MTS_AVDD_I_READ_1_2_Pin LL_GPIO_PIN_15
#define MTS_AVDD_I_READ_1_2_GPIO_Port GPIOF
#define MTS_AVDD_I_SEL_1E8_Pin LL_GPIO_PIN_8
#define MTS_AVDD_I_SEL_1E8_GPIO_Port GPIOE
#define MTS_TIM1_CH1_Pin LL_GPIO_PIN_9
#define MTS_TIM1_CH1_GPIO_Port GPIOE
#define MTS_TIM1_CH2_Pin LL_GPIO_PIN_11
#define MTS_TIM1_CH2_GPIO_Port GPIOE
#define MTS_TIM1_CH4_Pin LL_GPIO_PIN_14
#define MTS_TIM1_CH4_GPIO_Port GPIOE
#define MTS_DVDD_I_READ_1_2_Pin LL_GPIO_PIN_9
#define MTS_DVDD_I_READ_1_2_GPIO_Port GPIOD
#define MTS_REV_IO_1_Pin LL_GPIO_PIN_8
#define MTS_REV_IO_1_GPIO_Port GPIOD
#define MTS_SPI1_MOSI_Pin LL_GPIO_PIN_7
#define MTS_SPI1_MOSI_GPIO_Port GPIOA
#define MTS_AVDD_SW_Pin LL_GPIO_PIN_11
#define MTS_AVDD_SW_GPIO_Port GPIOF
#define MTS_AVDD_I_READ_3_Pin LL_GPIO_PIN_14
#define MTS_AVDD_I_READ_3_GPIO_Port GPIOF
#define MTS_DVDD_I_READ_3_Pin LL_GPIO_PIN_7
#define MTS_DVDD_I_READ_3_GPIO_Port GPIOE
#define MTS_DVDD_I_SEL_2_Pin LL_GPIO_PIN_10
#define MTS_DVDD_I_SEL_2_GPIO_Port GPIOE
#define MTS_VEN_ID_0_Pin LL_GPIO_PIN_12
#define MTS_VEN_ID_0_GPIO_Port GPIOE
#define MTS_VEN_ID_1_Pin LL_GPIO_PIN_15
#define MTS_VEN_ID_1_GPIO_Port GPIOE
#define MTS_SPI2_MISO_Pin LL_GPIO_PIN_14
#define MTS_SPI2_MISO_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
