#pragma once

#include "avrcxx/chrono/duration.hpp"
#include "avrcxx/sleep/detail/prescaler.hpp"
#include "avrcxx/sleep/sleep.hpp"
#include "avrcxx/watchdog/isr.hpp"
#include "avrcxx/watchdog/watchdog.hpp"

#include <stdint.h>

namespace avrcxx::sleep::power_down {

[[gnu::always_inline]] inline void enable() noexcept
{ MCUCR = MCUCR | (((1<<SE) | (1<<SM1)) & ~(1<<SM0)); }

[[gnu::always_inline]] inline void disable() noexcept
{ MCUCR = MCUCR & ~((1<<SE) | (1<<SM1) | (1<<SM0)); } 

}

#include "avrcxx/sleep/detail/sleep.hpp"

namespace avrcxx::sleep::power_down {

template<auto Duration>
inline void sleep() noexcept {
    static_assert(AVRCXX_WATCHDOG_COUNTER_RESOLUTION == 8 ||
                  AVRCXX_WATCHDOG_COUNTER_RESOLUTION == 16,
                  "AVRCXX_WATCHDOG_COUNTER_RESOLUTION must be 8 or 16.");
    static_assert(
        !(Duration % 16)   ||
        !(Duration % 32)   ||
        !(Duration % 64)   ||
        !(Duration % 125)  ||
        !(Duration % 250)  ||
        !(Duration % 500)  ||
        !(Duration % 1000) ||
        !(Duration % 2000) ||
        !(Duration % 4000) ||
        !(Duration % 8000),
        "Duration should be multiple of 16ms, 32ms, 64ms, 125ms, 500ms, "
        "1000ms, 2000ms, 4000ms or 8000ms.");

    constexpr auto duration_equal_to_prescaler =
        Duration == 16   || Duration == 32   || Duration == 64   ||
        Duration == 125  || Duration == 250  || Duration == 500  ||
        Duration == 1000 || Duration == 2000 || Duration == 4000 ||
        Duration == 8000;
    
    if constexpr(duration_equal_to_prescaler)
    {
        detail::sleep(Duration);
        watchdog::off();
    } else {
#if   AVRCXX_WATCHDOG_HAS_COUNTER
        constexpr auto prescaler = detail::prescaler(Duration);
        if constexpr(AVRCXX_WATCHDOG_COUNTER_RESOLUTION == 8)
            static_assert(Duration / prescaler <= 255,
                          "The duration is too high to be used with "
                          "the selected prescaler. The macro "
                          "AVRCXX_WATCHDOG_COUNTER_RESOLUTION can be defined "
                          " to 16 to allow a 16bits software counter.");
        else
            static_assert(Duration / prescaler <= 65536,
                          "The duration is too high to be used with "
                          "the selected prescaler.");
        avrcxx_watchdog_cnt = 0;
        while(avrcxx_watchdog_cnt < (Duration / prescaler))
            detail::sleep(prescaler);
        watchdog::off();
#     else
        static_assert(duration_equal_to_prescaler,
                      "You can't sleep with a duration that isn't equal to any "
                      "prescaler without the software counter, which means that "
                      "you can't execute this sleep if the macro "
                      "AVRCXX_WATCHDOG_ELLIDE_COUNTER is defined.");
#     endif
    }
}

}
