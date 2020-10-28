#pragma once

namespace avrcxx {

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wliteral-suffix"
constexpr auto operator "" ms(unsigned long long ms)
{ return ms; }

constexpr auto operator "" s(unsigned long long s)
{ return s * 1000; }

constexpr auto operator "" min(unsigned long long min)
{ return min * 1000 * 60; }

constexpr auto operator "" h(unsigned long long h)
{ return h * 1000 * 60 * 60; }

#pragma GCC diagnostic pop

}
