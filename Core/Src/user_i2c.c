/**
  * @file user_i2c.c
  * @brief User I2C interface implementation for I2C3
  */

#include "user_i2c.h"
#include "i2c.h"

#define I2C_TIMEOUT 10000

bool USER_I2C_IsDeviceReady(uint8_t dev_addr)
{
  if (HAL_I2C_GetState(&hi2c3) != HAL_I2C_STATE_READY) {
    return false;
  }

  return (HAL_I2C_IsDeviceReady(&hi2c3, (uint16_t)(dev_addr << 1), 3, I2C_TIMEOUT) == HAL_OK);
}

bool USER_I2C_Read(uint8_t dev_addr, uint8_t reg_addr, uint8_t *data, uint16_t len)
{
  if (len == 0 || HAL_I2C_GetState(&hi2c3) != HAL_I2C_STATE_READY) {
    return false;
  }

  return (HAL_I2C_Mem_Read(&hi2c3,
                           (uint16_t)(dev_addr << 1),
                           reg_addr,
                           I2C_MEMADD_SIZE_8BIT,
                           data,
                           len,
                           I2C_TIMEOUT) == HAL_OK);
}

bool USER_I2C_Write(uint8_t dev_addr, uint8_t reg_addr, uint8_t *data, uint16_t len)
{
  if (len == 0 || HAL_I2C_GetState(&hi2c3) != HAL_I2C_STATE_READY) {
    return false;
  }

  return (HAL_I2C_Mem_Write(&hi2c3,
                            (uint16_t)(dev_addr << 1),
                            reg_addr,
                            I2C_MEMADD_SIZE_8BIT,
                            data,
                            len,
                            I2C_TIMEOUT) == HAL_OK);
}