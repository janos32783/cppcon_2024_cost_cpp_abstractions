#pragma once

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

} /* namespace systick */
} /* namespace hal */