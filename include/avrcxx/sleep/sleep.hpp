#pragma once

namespace avrcxx::sleep {

[[gnu::always_inline]] inline void sleep() noexcept
{ asm("sleep"); }

}
