/**
  * @file board_access_task.c
  * @brief Board access task implementation
  */

#include "board_access_task.h"
#include "mts_dev.h"
#include "user_i2c.h"
#include "user_spi.h"
#include "cmsis_os.h"
#include "app_watchdog_task.h"
#define LOG_TAG "BoardAccess"
#include "elog.h"

static bool MTS_CheckDeviceI2C3(uint8_t dev_addr)
{
  return USER_I2C_IsDeviceReady(dev_addr);
}

static bool MTS_CheckDeviceSPI1(void)
{
  uint8_t dummy_tx = g_mtsDev.comm.dummy;
  uint8_t dummy_rx;

  return USER_SPI_ReadWrite(&dummy_tx, &dummy_rx, 1);
}

void vBoardAccessTask(void *argument)
{
  const TickType_t check_interval = pdMS_TO_TICKS(2000);
  uint8_t addr = g_mtsDev.comm.dev_addr[0] ? g_mtsDev.comm.dev_addr[0] : 0x50;

  Watchdog_RegisterTask(xTaskGetCurrentTaskHandle(), pcTaskGetTaskName(xTaskGetCurrentTaskHandle()));

  for (;;) {
    bool connected = false;

    if (g_mtsDev.comm.active_comm == MTS_COMM_TYPE_I2C3) {
      connected = MTS_CheckDeviceI2C3(addr);
    } else if (g_mtsDev.comm.active_comm == MTS_COMM_TYPE_SPI1) {
      connected = MTS_CheckDeviceSPI1();
    }

    if (connected) {
      g_mtsDev.comm.statch_flag = 1;
      log_i("device access OK, connection normal");
    } else {
      g_mtsDev.comm.statch_flag = 0;
      log_e("device access failed, connection lost");
    }

    Watchdog_ReportAlive(xTaskGetCurrentTaskHandle());
    osDelay(check_interval);
  }
}