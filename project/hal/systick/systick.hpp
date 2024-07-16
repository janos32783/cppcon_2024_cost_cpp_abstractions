#pragma once

#include <chrono>

#include "hal/register.hpp"
#include "hal/common.hpp"

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
public:
    typedef std::chrono::milliseconds         duration;
    typedef duration::rep                     rep;
    typedef duration::period                  period;
    typedef std::chrono::time_point<CSysTick> time_point;
    static const bool is_steady =             true;
private:
    static inline time_point m_time { std::chrono::milliseconds{ 0 } };
public:
    static inline void tick () { m_time += std::chrono::milliseconds{ 1 }; }
    static inline time_point now() noexcept { return m_time; }
private:
    static constexpr std::uint32_t m_address = SCS_BASE;
    using m_reg_t = SysTick_Type;

    static consteval std::uint32_t calculate_ticks (uint32_t core_clock_freq, tick_frequencies systick_freq) {
        return core_clock_freq / (1000U / static_cast<std::uint32_t>(systick_freq));
    }
public:
    template <SystickConfig config>
    requires (is_valid_frequency<config.systick_freq> && is_preemptive_prio<config.prio>)
    static inline void init () {
        constexpr std::uint32_t ticks = calculate_ticks(config.core_clock_freq, config.systick_freq);
        // period of N -> use a reload value of N-1
        static_assert((ticks - 1) <= SysTick_LOAD_RELOAD_Msk, "impossible reload value");
        m_time = time_point { std::chrono::milliseconds{ 0 } };
        SysTick_Config(ticks);

        static_assert(config.prio < (1UL << __NVIC_PRIO_BITS), "invalid systick priority");
        NVIC_SetPriority(SysTick_IRQn, config.prio);
    }
};

// function set in the startup file as interrupt handler for the systick interrupt
void SysTick_Handler(void) {
    CSysTick::tick();
}

} /* namespace systick */
} /* namespace hal */