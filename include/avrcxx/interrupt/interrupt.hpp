#pragma once

namespace avrcxx::interrupt {

[[gnu::always_inline]] inline void enable() noexcept
{ asm("sei"); }

[[gnu::always_inline]] inline void disable() noexcept
{ asm("cli"); }

struct atomic {
    atomic(){ disable(); }
    ~atomic(){ enable(); }
};
    
}
