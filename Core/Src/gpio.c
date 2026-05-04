/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    gpio.c
  * @brief   This file provides code for the configuration
  *          of all used GPIO pins.
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
#include "gpio.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/** Configure pins as
        * Analog
        * Input
        * Output
        * EVENT_OUT
        * EXTI
        * Free pins are configured automatically as Analog (this feature is enabled through
        * the Code Generation settings)
*/
void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOG_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOI_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOE, MTS_GPIO1_Pin|MTS_GPIO3_Pin|MTS_GPIO5_Pin|MTS_GPIO7_Pin
                          |MTS_GPIO0_Pin|MTS_GPIO2_Pin|MTS_GPIO4_Pin|MTS_VDDIO_SW_Pin
                          |MTS_AVDD_I_SEL_1E8_Pin|MTS_DVDD_I_READ_3_Pin|MTS_DVDD_I_SEL_2_Pin|MTS_VEN_ID_0_Pin
                          |MTS_VEN_ID_1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, MTS_IO_DIR2_Pin|MTS_GPIO6_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOG, MTS_LEAK_TEST_SEL2_Pin|MTS_LEAK_TEST_1_Pin|MTS_IO_DIR4_Pin|MTS_Flash_SPI_CS_Pin
                          |MTS_DUT_SPI_CLK_DIR_Pin|MTS_DUT_SPI_SI_DIR_Pin|MTS_DUT_SPI_SO_DIR_Pin|MTS_MODULE_RST_Pin
                          |MTS_IO_VCCB_VDDIO_Pin|MTS_VDDIO_I_READ_1_2_Pin|MTS_DVDD_SW_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOI, MTS_IO_DIR0_Pin|MTS_IO_DIR1_Pin|MTS_IO_DIR3_Pin|MTS_IO_VCCB_DVDD_Pin
                          |MTS_SPI2_CS_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, MTS_IO_EN_Pin|MTS_SHIFTER1_VCCB_SW_Pin|MTS_DAC_BSY_Pin|MTS_DAC_LDAC_Pin
                          |MTS_I2C_EN_Pin|MTS_REV_IO_0_Pin|MTS_DVDD_I_READ_1_2_Pin|MTS_REV_IO_1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOH, MTS_LPC_nRST_Pin|MTS_LED_R_Pin|MTS_LED_G_Pin|MTS_RST_USB_HS_PHY_Pin
                          |MTS_EN_VPP_IN_Pin|MTS_LPC86_CS_Pin|MTS_LEAK_TEST_SEL3_Pin|MTS_LEAK_TEST_SEL4_Pin
                          |MTS_VDDIO_I_SEL_2_Pin|MTS_VDDIO_I_SEL_1_Pin|MTS_VDDIIO_I_READ_3_Pin|MTS_DUT_SPI_EN__Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(MTS_DUT_RST_EN_GPIO_Port, MTS_DUT_RST_EN_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOF, MTS_VPP_OUT_Pin|MTS_AVDD_I_SEL_1_Pin|MTS_AVDD_I_SEL_2_Pin|MTS_AVDD_I_READ_1_2_Pin
                          |MTS_AVDD_SW_Pin|MTS_AVDD_I_READ_3_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(MTS_SPI3_CS_GPIO_Port, MTS_SPI3_CS_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : MTS_GPIO1_Pin MTS_GPIO3_Pin MTS_GPIO5_Pin MTS_GPIO7_Pin
                           MTS_GPIO0_Pin MTS_GPIO2_Pin MTS_GPIO4_Pin MTS_VDDIO_SW_Pin
                           MTS_AVDD_I_SEL_1E8_Pin MTS_DVDD_I_READ_3_Pin MTS_DVDD_I_SEL_2_Pin MTS_VEN_ID_0_Pin
                           MTS_VEN_ID_1_Pin */
  GPIO_InitStruct.Pin = MTS_GPIO1_Pin|MTS_GPIO3_Pin|MTS_GPIO5_Pin|MTS_GPIO7_Pin
                          |MTS_GPIO0_Pin|MTS_GPIO2_Pin|MTS_GPIO4_Pin|MTS_VDDIO_SW_Pin
                          |MTS_AVDD_I_SEL_1E8_Pin|MTS_DVDD_I_READ_3_Pin|MTS_DVDD_I_SEL_2_Pin|MTS_VEN_ID_0_Pin
                          |MTS_VEN_ID_1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pins : MTS_IO_DIR2_Pin MTS_GPIO6_Pin */
  GPIO_InitStruct.Pin = MTS_IO_DIR2_Pin|MTS_GPIO6_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : MTS_LEAK_TEST_SEL2_Pin MTS_LEAK_TEST_1_Pin MTS_IO_DIR4_Pin MTS_Flash_SPI_CS_Pin
                           MTS_DUT_SPI_CLK_DIR_Pin MTS_DUT_SPI_SI_DIR_Pin MTS_DUT_SPI_SO_DIR_Pin MTS_MODULE_RST_Pin
                           MTS_IO_VCCB_VDDIO_Pin MTS_VDDIO_I_READ_1_2_Pin MTS_DVDD_SW_Pin */
  GPIO_InitStruct.Pin = MTS_LEAK_TEST_SEL2_Pin|MTS_LEAK_TEST_1_Pin|MTS_IO_DIR4_Pin|MTS_Flash_SPI_CS_Pin
                          |MTS_DUT_SPI_CLK_DIR_Pin|MTS_DUT_SPI_SI_DIR_Pin|MTS_DUT_SPI_SO_DIR_Pin|MTS_MODULE_RST_Pin
                          |MTS_IO_VCCB_VDDIO_Pin|MTS_VDDIO_I_READ_1_2_Pin|MTS_DVDD_SW_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

  /*Configure GPIO pins : PD7 PD6 PD0 PD5
                           PD1 PD3 PD2 PD11 */
  GPIO_InitStruct.Pin = GPIO_PIN_7|GPIO_PIN_6|GPIO_PIN_0|GPIO_PIN_5
                          |GPIO_PIN_1|GPIO_PIN_3|GPIO_PIN_2|GPIO_PIN_11;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pins : PC12 PC7 PC6 */
  GPIO_InitStruct.Pin = GPIO_PIN_12|GPIO_PIN_7|GPIO_PIN_6;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PA15 PA12 PA11 PA9 */
  GPIO_InitStruct.Pin = GPIO_PIN_15|GPIO_PIN_12|GPIO_PIN_11|GPIO_PIN_9;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB7 PB6 PB2 PB15 */
  GPIO_InitStruct.Pin = GPIO_PIN_7|GPIO_PIN_6|GPIO_PIN_2|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : MTS_BID0_Pin MTS_BID1_Pin MTS_BID2_Pin MTS_MODULE_INT_Pin
                           MTS_LPC86_INT_Pin */
  GPIO_InitStruct.Pin = MTS_BID0_Pin|MTS_BID1_Pin|MTS_BID2_Pin|MTS_MODULE_INT_Pin
                          |MTS_LPC86_INT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

  /*Configure GPIO pins : MTS_HID0_Pin MTS_HID1_Pin MTS_HID2_Pin */
  GPIO_InitStruct.Pin = MTS_HID0_Pin|MTS_HID1_Pin|MTS_HID2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : MTS_IO_DIR0_Pin MTS_IO_DIR1_Pin MTS_IO_DIR3_Pin MTS_IO_VCCB_DVDD_Pin
                           MTS_SPI2_CS_Pin */
  GPIO_InitStruct.Pin = MTS_IO_DIR0_Pin|MTS_IO_DIR1_Pin|MTS_IO_DIR3_Pin|MTS_IO_VCCB_DVDD_Pin
                          |MTS_SPI2_CS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOI, &GPIO_InitStruct);

  /*Configure GPIO pins : MTS_IO_EN_Pin MTS_SHIFTER1_VCCB_SW_Pin MTS_DAC_BSY_Pin MTS_DAC_LDAC_Pin
                           MTS_I2C_EN_Pin MTS_REV_IO_0_Pin MTS_DVDD_I_READ_1_2_Pin MTS_REV_IO_1_Pin */
  GPIO_InitStruct.Pin = MTS_IO_EN_Pin|MTS_SHIFTER1_VCCB_SW_Pin|MTS_DAC_BSY_Pin|MTS_DAC_LDAC_Pin
                          |MTS_I2C_EN_Pin|MTS_REV_IO_0_Pin|MTS_DVDD_I_READ_1_2_Pin|MTS_REV_IO_1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pins : MTS_LPC_nRST_Pin MTS_LED_R_Pin MTS_LED_G_Pin MTS_RST_USB_HS_PHY_Pin
                           MTS_EN_VPP_IN_Pin MTS_LPC86_CS_Pin MTS_LEAK_TEST_SEL3_Pin MTS_LEAK_TEST_SEL4_Pin
                           MTS_VDDIO_I_SEL_2_Pin MTS_VDDIO_I_SEL_1_Pin MTS_VDDIIO_I_READ_3_Pin MTS_DUT_SPI_EN__Pin */
  GPIO_InitStruct.Pin = MTS_LPC_nRST_Pin|MTS_LED_R_Pin|MTS_LED_G_Pin|MTS_RST_USB_HS_PHY_Pin
                          |MTS_EN_VPP_IN_Pin|MTS_LPC86_CS_Pin|MTS_LEAK_TEST_SEL3_Pin|MTS_LEAK_TEST_SEL4_Pin
                          |MTS_VDDIO_I_SEL_2_Pin|MTS_VDDIO_I_SEL_1_Pin|MTS_VDDIIO_I_READ_3_Pin|MTS_DUT_SPI_EN__Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOH, &GPIO_InitStruct);

  /*Configure GPIO pin : PH2 */
  GPIO_InitStruct.Pin = GPIO_PIN_2;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOH, &GPIO_InitStruct);

  /*Configure GPIO pin : MTS_DUT_RST_EN_Pin */
  GPIO_InitStruct.Pin = MTS_DUT_RST_EN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(MTS_DUT_RST_EN_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : MTS_VPP_OUT_Pin MTS_AVDD_I_SEL_1_Pin MTS_AVDD_I_SEL_2_Pin MTS_AVDD_I_READ_1_2_Pin
                           MTS_AVDD_SW_Pin MTS_AVDD_I_READ_3_Pin */
  GPIO_InitStruct.Pin = MTS_VPP_OUT_Pin|MTS_AVDD_I_SEL_1_Pin|MTS_AVDD_I_SEL_2_Pin|MTS_AVDD_I_READ_1_2_Pin
                          |MTS_AVDD_SW_Pin|MTS_AVDD_I_READ_3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

  /*Configure GPIO pin : MTS_SPI3_CS_Pin */
  GPIO_InitStruct.Pin = MTS_SPI3_CS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(MTS_SPI3_CS_GPIO_Port, &GPIO_InitStruct);

}

/* USER CODE BEGIN 2 */

/* USER CODE END 2 */
