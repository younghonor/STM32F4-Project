/**
  * @file user_spi.c
  * @brief User SPI interface implementation for SPI1
  */

#include "user_spi.h"
#include "spi.h"

#define SPI_TIMEOUT 100

bool USER_SPI_IsDeviceReady(void)
{
  return (HAL_SPI_GetState(&hspi1) == HAL_SPI_STATE_READY) &&
         (__HAL_SPI_GET_FLAG(&hspi1, SPI_FLAG_BSY) == RESET);
}

bool USER_SPI_Read(uint8_t *data, uint16_t len)
{
  if (!USER_SPI_IsDeviceReady() || len == 0) {
    return false;
  }

  uint8_t dummy = 0xFF;
  for (uint16_t i = 0; i < len; i++) {
    if (HAL_SPI_TransmitReceive(&hspi1, &dummy, &data[i], 1, SPI_TIMEOUT) != HAL_OK) {
      return false;
    }
  }

  return true;
}

bool USER_SPI_Write(uint8_t *data, uint16_t len)
{
  if (!USER_SPI_IsDeviceReady() || len == 0) {
    return false;
  }

  uint8_t dummy;
  for (uint16_t i = 0; i < len; i++) {
    if (HAL_SPI_TransmitReceive(&hspi1, &data[i], &dummy, 1, SPI_TIMEOUT) != HAL_OK) {
      return false;
    }
  }

  return true;
}

bool USER_SPI_ReadWrite(uint8_t *tx_data, uint8_t *rx_data, uint16_t len)
{
  if (!USER_SPI_IsDeviceReady() || len == 0) {
    return false;
  }

  if (HAL_SPI_TransmitReceive(&hspi1, tx_data, rx_data, len, SPI_TIMEOUT) != HAL_OK) {
    return false;
  }

  return true;
}