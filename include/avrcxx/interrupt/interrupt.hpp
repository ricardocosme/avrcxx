#pragma once

namespace avrcxx::interrupt {

[[gnu::always_inline]] inline void enable() noexcept
{ asm("sei" ::: "memory"); }

[[gnu::always_inline]] inline void disable() noexcept
{ asm("cli" ::: "memory"); }

struct atomic {
    atomic(){ disable(); }
    ~atomic(){ enable(); }
};
    
}
