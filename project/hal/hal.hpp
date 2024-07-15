#pragma once

#include <cstdint>

#include "hal/systick/constants.hpp"

namespace hal {

consteval calculate_ticks

template <uint32_t prio, uint32_t core_clock_freq, tick_frequencies systick_freq>
requires (is_valid_frequency<systick_freq>)
void init () {

}

} /* namespace hal */