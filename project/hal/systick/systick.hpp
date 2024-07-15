#pragma once

#include <cstdint>

#include "hal/systick/constants.hpp"
#include "hal/systick/registers.hpp"

namespace hal {
namespace systick {

consteval std::uint32_t calculate_ticks (uint32_t core_clock_freq, tick_frequencies systick_freq) {
    return core_clock_freq / (1000U / static_cast<std::uint32_t>(systick_freq));
}

struct SystickConfig {
    uint32_t prio { 0 };
    uint32_t core_clock_freq { 8000000 };
    tick_frequencies systick_freq { tick_frequencies::freq_1kHz };
};

template <SystickConfig config>
requires (is_valid_frequency<config.systick_freq>)
void init () {
    constexpr std::uint32_t ticks = calculate_ticks(config.core_clock_freq, config.systick_freq);
    // period of N -> use a reload value of N-1
    static_assert((ticks - 1) <= STK_RVR_RELOAD_MSK, "impossible reload value");
    // necessary registers
    CControlAndStatusRegister stk_csr {};
    CReloadValueRegister stk_rvr {};
    CCurrentValueRegister stk_cvr {};
    // init
    stk_rvr.set_reload_value(ticks - 1);
    // nvic : TODO
    stk_cvr.set_current_value(0);
    stk_csr.set_bits(STK_CSR_CLKSOURCE_MSK | STK_CSR_TICKINT_MSK | STK_CSR_ENABLE_MSK);
}

} /* namespace systick */
} /* namespace hal */