/**
  * @file user_spi.h
  * @brief User SPI interface for SPI1
  */

#ifndef __USER_SPI_H__
#define __USER_SPI_H__

#include <stdint.h>
#include <stdbool.h>

bool USER_SPI_IsDeviceReady(void);
bool USER_SPI_Read(uint8_t *data, uint16_t len);
bool USER_SPI_Write(uint8_t *data, uint16_t len);
bool USER_SPI_ReadWrite(uint8_t *tx_data, uint8_t *rx_data, uint16_t len);

#endif /* __USER_SPI_H__ */