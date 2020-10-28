#pragma once

#include <stdint.h>

namespace avrcxx::sleep::power_down::detail {

constexpr inline uint32_t prescaler(uint32_t Duration) {
    if (!(Duration % 8000) && ((Duration / 8000) > 0))
        return 8000;
    else if (!(Duration % 4000) && ((Duration / 4000) > 0))
        return 4000;
    else if (!(Duration % 2000) && ((Duration / 2000) > 0))
        return 2000;
    else if (!(Duration % 1000) && ((Duration / 1000) > 0))
        return 1000;
    else if (!(Duration % 500) && ((Duration / 500) > 0))
        return 500;
    else if (!(Duration % 250) && ((Duration / 250) > 0))
        return 250;
    else if (!(Duration % 125) && ((Duration / 125) > 0))
        return 125;
    else if (!(Duration % 64) && ((Duration / 64) > 0))
        return 64;
    else if (!(Duration % 32) && ((Duration / 32) > 0))
        return 32;
    return 16;
}

}
