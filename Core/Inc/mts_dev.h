/**
  * @file mts_dev.h
  * @brief MTS device structure definitions
  */

#ifndef __MTS_DEV_H__
#define __MTS_DEV_H__

#include <stdint.h>
#include <stdbool.h>

typedef enum {
  MTS_COMM_TYPE_NONE = 0,
  MTS_COMM_TYPE_I2C3,
  MTS_COMM_TYPE_SPI1,
} mts_comm_type_t;

struct stMtsCommAttr {
  uint32_t spi_rate;
  uint8_t dummy;
  uint8_t dummycnt;
  uint32_t i2c_speed;
  uint8_t dev_addr[4];
  uint8_t statch_flag;
  mts_comm_type_t active_comm;
};

struct stMtsPowerAttr {
  float avdd_set;
  float avdd_actual;
  float vddio_set;
  float vddio_actual;
  float dvdd_set;
  float dvdd_actual;
  float vpp_set;
  float vpp_actual;
};

struct stMtsDev {
  struct stMtsCommAttr comm;
  struct stMtsPowerAttr power;
};

extern struct stMtsDev g_mtsDev;

#endif /* __MTS_DEV_H__ */