#pragma once

#include <cstdint>

namespace hal {

/* Peripheral base address in the alias region */
constexpr std::uint32_t PERIPH_BASE_ADDR = UINT32_C(0x40000000);

/* Peripheral memory map */
constexpr std::uint32_t AHB1PERIPH_BASE_ADDR = PERIPH_BASE_ADDR + UINT32_C(0x00020000);
constexpr std::uint32_t AHB2PERIPH_BASE_ADDR = PERIPH_BASE_ADDR + UINT32_C(0x08000000);

} /* namespace hal */