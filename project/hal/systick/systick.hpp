#pragma once

#include <cstdint>

#include "hal/register.hpp"
#include "hal/CMSIS/Device/ST/STM32F0xx/Include/stm32f030xc.h"

namespace hal {
namespace systick {

enum class tick_frequencies : std::uint32_t {
    freq_10Hz = 100,
    freq_100Hz = 10,
    freq_1kHz = 1
};

template <tick_frequencies freq>
concept is_valid_frequency = (
    (freq == tick_frequencies::freq_10Hz)  ||
    (freq == tick_frequencies::freq_100Hz) ||
    (freq == tick_frequencies::freq_1kHz)
);

struct SystickConfig {
    uint32_t prio { 0 };
    uint32_t core_clock_freq { 8000000 };
    tick_frequencies systick_freq { tick_frequencies::freq_1kHz };
};

class CSysTick {
private:
    static constexpr std::uint32_t m_address = SCS_BASE;
    using m_reg_t = SysTick_Type;

    static consteval std::uint32_t calculate_ticks (uint32_t core_clock_freq, tick_frequencies systick_freq) {
        return core_clock_freq / (1000U / static_cast<std::uint32_t>(systick_freq));
    }
public:
    template <SystickConfig config>
    requires (is_valid_frequency<config.systick_freq>)
    static inline void init () {
        constexpr std::uint32_t ticks = calculate_ticks(config.core_clock_freq, config.systick_freq);
        // period of N -> use a reload value of N-1
        static_assert((ticks - 1) <= SysTick_LOAD_RELOAD_Msk, "impossible reload value");
        // init
        CRegister::set(&reinterpret_cast<m_reg_t*>(m_address)->LOAD, ticks - 1, SysTick_LOAD_RELOAD_Msk);
        __NVIC_SetPriority(SysTick_IRQn, config.prio);
        CRegister::set(&reinterpret_cast<m_reg_t*>(m_address)->VAL, 0, SysTick_VAL_CURRENT_Msk);
        CRegister::set_bits(&reinterpret_cast<m_reg_t*>(m_address)->CTRL, SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_TICKINT_Msk | SysTick_CTRL_ENABLE_Msk);
    }
};

} /* namespace systick */
} /* namespace hal */