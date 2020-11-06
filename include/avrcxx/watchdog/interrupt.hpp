#pragma once

#include "avrcxx/interrupt/interrupt.hpp"

#include <avr/io.h>

namespace avrcxx::watchdog::interrupt {

#ifdef __AVR_ATtiny85__
inline constexpr auto wdie = WDIE;
#elif __AVR_ATtiny13A__
inline constexpr auto wdie = WDTIE;
#else
#error "AVR device doesn't supported"
#endif

struct at_16ms_t {
    constexpr static uint16_t period{16};
    static void on() noexcept {
        WDTCR = (1<<wdie);
        avrcxx::interrupt::enable();
    }
};
inline constexpr at_16ms_t at_16ms;

struct at_32ms_t {
    constexpr static uint16_t period{32};
    static void on() noexcept {
        WDTCR = (1<<wdie) | (1<<WDP0);
        avrcxx::interrupt::enable();
    }
};
inline constexpr at_32ms_t at_32ms;

struct at_64ms_t {
    constexpr static uint16_t period{64};
    static void on() noexcept {
        WDTCR = (1<<wdie) | (1<<WDP1);
        avrcxx::interrupt::enable();
    }
};
inline constexpr at_64ms_t at_64ms;

struct at_125ms_t {
    constexpr static uint16_t period{125};
    static void on() noexcept {
        WDTCR = (1<<wdie) | (1<<WDP1) | (1<<WDP0);
        avrcxx::interrupt::enable();
    }
};
inline constexpr at_125ms_t at_125ms;

struct at_250ms_t {
    constexpr static uint16_t period{250};
    static void on() noexcept {
        WDTCR = (1<<wdie) | (1<<WDP2);
        avrcxx::interrupt::enable();
    }
};
inline constexpr at_250ms_t at_250ms;
struct at_500ms_t {
    constexpr static uint16_t period{500};
    static void on() noexcept {
        WDTCR = (1<<wdie) | (1<<WDP2) | (1<<WDP0);
        avrcxx::interrupt::enable();
    }
};
inline constexpr at_500ms_t at_500ms;

struct at_1s_t {
    constexpr static uint16_t period{1000};
    static void on() noexcept {
        WDTCR = (1<<wdie) | (1<<WDP2) | (1<<WDP1);
        avrcxx::interrupt::enable();
    }
};
inline constexpr at_1s_t at_1s;

struct at_2s_t {
    constexpr static uint16_t period{2000};
    static void on() noexcept {
        WDTCR = (1<<wdie) | (1<<WDP2) | (1<<WDP1) | (1<<WDP0);
        avrcxx::interrupt::enable();
    }
};
inline constexpr at_2s_t at_2s;

struct at_4s_t {
    constexpr static uint16_t period{4000};
    static void on() noexcept {
        WDTCR = (1<<wdie) | (1<<WDP3);
        avrcxx::interrupt::enable();
    }
};
inline constexpr at_4s_t at_4s;

struct at_8s_t {
    constexpr static uint16_t period{8000};
    static void on() noexcept {
        WDTCR = (1<<wdie) | (1<<WDP3) | (1<<WDP0);
        avrcxx::interrupt::enable();
    }
};
inline constexpr at_8s_t at_8s;

}
