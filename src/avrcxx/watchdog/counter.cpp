#include "avrcxx/watchdog/counter.hpp"

#include <avr/io.h>

#if (AVRCXX_WATCHDOG_COUNTER_RESOLUTION == 8)
[[gnu::section(".noinit")]] uint8_t avrcxx_watchdog_cnt;
#else
[[gnu::section(".noinit")]] uint16_t avrcxx_watchdog_cnt;
#endif

extern "C" {
    [[using gnu: signal, used, externally_visible]] void WDT_vect()
    { ++avrcxx_watchdog_cnt; }
}
