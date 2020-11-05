#pragma once

#include <stdint.h>

#ifndef AVRCXX_WATCHDOG_COUNTER_RESOLUTION
#define AVRCXX_WATCHDOG_COUNTER_RESOLUTION 8
#endif

#ifndef AVRCXX_WATCHDOG_ELLIDE_COUNTER
#  if (AVRCXX_WATCHDOG_COUNTER_RESOLUTION == 8)
     extern uint8_t avrcxx_watchdog_cnt;
#  else
     extern uint16_t avrcxx_watchdog_cnt;
#  endif
#  define AVRCXX_WATCHDOG_HAS_COUNTER 1
#else
#  define AVRCXX_WATCHDOG_HAS_COUNTER 0
#endif

