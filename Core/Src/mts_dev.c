/**
  * @file mts_dev.c
  * @brief MTS device global variables
  */

#include "mts_dev.h"

struct stMtsDev g_mtsDev = {
  .comm = {
    .spi_rate = 1000000,
    .dummy = 0xFF,
    .dummycnt = 1,
    .i2c_speed = 400000,
    .dev_addr = {0x50, 0x00, 0x00, 0x00},
    .statch_flag = 0,
    .active_comm = MTS_COMM_TYPE_I2C3,
  },
  .power = {
    .avdd_set = 0.0f,
    .avdd_actual = 0.0f,
    .vddio_set = 0.0f,
    .vddio_actual = 0.0f,
    .dvdd_set = 0.0f,
    .dvdd_actual = 0.0f,
    .vpp_set = 0.0f,
    .vpp_actual = 0.0f,
  },
};