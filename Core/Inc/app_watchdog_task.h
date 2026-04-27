#ifndef APP_WATCHDOG_TASK_H
#define APP_WATCHDOG_TASK_H

#include "cmsis_os2.h"
#include <stdint.h>

void vStartWatchdogTask(void *argument);
void Watchdog_ReportAlive(osThreadId_t handle);
void Watchdog_Init(void);
#endif //APP_WATCHDOG_TASK_H
