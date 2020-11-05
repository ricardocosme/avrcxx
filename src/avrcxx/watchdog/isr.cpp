#include "avrcxx/watchdog/isr.hpp"

#include <avr/io.h>

#ifndef AVRCXX_WATCHDOG_ELLIDE_COUNTER
#  if (AVRCXX_WATCHDOG_COUNTER_RESOLUTION == 8)
     [[gnu::section(".noinit")]] uint8_t avrcxx_watchdog_cnt;
#  else
     [[gnu::section(".noinit")]] uint16_t avrcxx_watchdog_cnt;
#  endif
#endif

extern "C" {
    [[using gnu: signal, used, externally_visible]] void WDT_vect() {
#ifndef AVRCXX_WATCHDOG_ELLIDE_COUNTER
        ++avrcxx_watchdog_cnt;
#endif
    }
}

