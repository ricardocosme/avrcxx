#pragma once

#include "avrcxx/watchdog/interrupt.hpp"

namespace avrcxx::sleep::power_down::detail {

constexpr inline void watchdog_on(uint16_t duration) noexcept {
    if(duration == 16)
        watchdog::interrupt::at_16ms.on();
    else if(duration == 32)
        watchdog::interrupt::at_32ms.on();
    else if(duration == 64)
        watchdog::interrupt::at_64ms.on();
    else if(duration == 125)
        watchdog::interrupt::at_125ms.on();
    else if(duration == 250)
        watchdog::interrupt::at_250ms.on();
    else if(duration == 500)
        watchdog::interrupt::at_500ms.on();
    else if(duration == 1000)
        watchdog::interrupt::at_1s.on();
    else if(duration == 2000)
        watchdog::interrupt::at_2s.on();
    else if(duration == 4000)
        watchdog::interrupt::at_4s.on();
    else if(duration == 8000)
        watchdog::interrupt::at_8s.on();
}

}
