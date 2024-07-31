#pragma once

#include "hal/register.hpp"
#include "hal/systick/constants.hpp"

namespace hal {
namespace systick {

class CSysTick {
private:
    static volatile inline std::uint32_t m_time { 0 };
    static constexpr std::uint32_t m_address = SCS_BASE;
    using m_reg_t = SysTick_Type;
    static inline std::uint32_t m_core_clock_freq { 8000000 };

    static consteval std::uint32_t calculate_ticks (std::uint32_t core_clock_freq, tick_frequencies systick_freq) {
        return core_clock_freq / (1000U / static_cast<std::uint32_t>(systick_freq));
    }
public:
    static inline void tick () { m_time = m_time + 1; }
    static inline std::uint32_t now() noexcept { return m_time; }

    template <SystickConfig config>
    requires (is_valid_frequency<config.systick_freq> && is_preemptive_prio<config.prio>)
    static inline void init () {
        constexpr std::uint32_t ticks = calculate_ticks(config.core_clock_freq, config.systick_freq);
        // period of N -> use a reload value of N-1
        static_assert((ticks - 1) <= SysTick_LOAD_RELOAD_Msk, "impossible reload value");
        m_time = 0;
        SysTick_Config(ticks);
        m_core_clock_freq = config.core_clock_freq;

        static_assert(config.prio < (1UL << __NVIC_PRIO_BITS), "invalid systick priority");
        NVIC_SetPriority(SysTick_IRQn, config.prio);
    }

    static inline void delay_ms (std::uint32_t delay) {
        auto start = m_time;
        while ((m_time - start) < delay) {}
    }

    static inline void delay_us (std::uint32_t delay) {
        volatile std::uint32_t wait_loop_index = (delay * (m_core_clock_freq / 1000000U));
        while(wait_loop_index != 0U) {
            wait_loop_index--;
        }
    }
};

extern "C" {
// function set in the startup file as interrupt handler for the systick interrupt
void SysTick_Handler(void) {
    CSysTick::tick();
}
}

} /* namespace systick */
} /* namespace hal */