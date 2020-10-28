#pragma once

#include "avrcxx/sleep/detail/watchdog_on.hpp"

namespace avrcxx::sleep::power_down::detail {

inline void sleep(uint16_t duration) noexcept {
    detail::watchdog_on(duration);
    enable();
    sleep::sleep();
}

}
