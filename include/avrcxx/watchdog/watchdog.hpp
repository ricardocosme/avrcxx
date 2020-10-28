#pragma once

#include "avrcxx/interrupt/interrupt.hpp"

#include <avr/io.h>

namespace avrcxx::watchdog {

[[gnu::always_inline]] inline void off() noexcept {
    avrcxx::interrupt::atomic atomic;
    WDTCR = WDTCR | (1<<WDCE) | (1<<WDE); 
    WDTCR = 0x00;
}

[[gnu::always_inline]] inline void reset() noexcept
{ asm("wdr"); }

}
