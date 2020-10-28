#pragma once

#include <stdint.h>

#ifndef AVRCXX_WATCHDOG_COUNTER_RESOLUTION
#define AVRCXX_WATCHDOG_COUNTER_RESOLUTION 8
#endif

#if (AVRCXX_WATCHDOG_COUNTER_RESOLUTION == 8)
extern uint8_t cnt;
#else
extern uint16_t cnt;
#endif

