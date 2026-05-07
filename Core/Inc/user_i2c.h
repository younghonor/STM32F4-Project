/**
  * @file user_i2c.h
  * @brief User I2C interface for I2C3
  */

#ifndef __USER_I2C_H__
#define __USER_I2C_H__

#include <stdint.h>
#include <stdbool.h>

bool USER_I2C_IsDeviceReady(uint8_t dev_addr);
bool USER_I2C_Read(uint8_t dev_addr, uint8_t reg_addr, uint8_t *data, uint16_t len);
bool USER_I2C_Write(uint8_t dev_addr, uint8_t reg_addr, uint8_t *data, uint16_t len);

#endif /* __USER_I2C_H__ */