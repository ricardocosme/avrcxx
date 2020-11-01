#pragma once

#include "avrcxx/interrupt/interrupt.hpp"

#include <avr/io.h>

namespace avrcxx::watchdog {

[[gnu::always_inline]] inline void off() noexcept {
    avrcxx::interrupt::atomic atomic;
    WDTCR = WDTCR | (1<<WDCE) | (1<<WDE); 
    asm("out 0x21, __zero_reg__");
}

[[gnu::always_inline]] inline void reset() noexcept
{ asm("wdr"); }

}
