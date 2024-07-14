#pragma once

#include <cstdint>
#include <concepts>

#include "hal/base/constants.hpp"

namespace hal {

constexpr std::uint32_t RCC_BASE_ADDR = AHB1PERIPH_BASE_ADDR + UINT32_C(0x1000);

constexpr std::uint32_t RCC_AHBENR_OFFSET = UINT32_C(0x14);

constexpr std::uint32_t RCC_AHBENR_ADDR = RCC_BASE_ADDR + RCC_AHBENR_OFFSET;

} /* namespace hal */