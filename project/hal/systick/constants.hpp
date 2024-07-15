#pragma once

#include <cstdint>
#include <concepts>

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

// SysTick register base addresses
constexpr std::uint32_t STK_BASE_ADDR = UINT32_C(0xe000e010);

template <std::uint32_t base_addr>
concept is_valid_base_address = (
    base_addr == STK_BASE_ADDR
);
constexpr std::uint32_t STK_CSR_OFFSET          = UINT32_C(0x0);
constexpr std::uint32_t STK_RVR_OFFSET          = UINT32_C(0x4);
constexpr std::uint32_t STK_CVR_OFFSET          = UINT32_C(0x8);
constexpr std::uint32_t STK_CALIB_OFFSET        = UINT32_C(0xC);
// SysTick control and status register
constexpr std::uint32_t STK_CSR_ENABLE_MSK     = UINT32_C(0b00000000000000000000000000000001);
constexpr std::uint32_t STK_CSR_ENABLE_POS     = UINT32_C(0);
constexpr std::uint32_t STK_CSR_TICKINT_MSK    = UINT32_C(0b00000000000000000000000000000010);
constexpr std::uint32_t STK_CSR_TICKINT_POS    = UINT32_C(1);
constexpr std::uint32_t STK_CSR_CLKSOURCE_MSK  = UINT32_C(0b00000000000000000000000000000100);
constexpr std::uint32_t STK_CSR_CLKSOURCE_POS  = UINT32_C(2);
constexpr std::uint32_t STK_CSR_COUNTFLAG_MSK  = UINT32_C(0b00000000000000010000000000000000);
constexpr std::uint32_t STK_CSR_COUNTFLAG_POS  = UINT32_C(16);
// SysTick reload value register
constexpr std::uint32_t STK_RVR_RELOAD_MSK     = UINT32_C(0b00000000111111111111111111111111);
constexpr std::uint32_t STK_RVR_RELOAD_POS     = UINT32_C(0);
// SysTick current value register
constexpr std::uint32_t STK_CVR_CURRENT_MSK    = UINT32_C(0b00000000111111111111111111111111);
constexpr std::uint32_t STK_CVR_CURRENT_POS    = UINT32_C(0);
// SysTick calibration value register
constexpr std::uint32_t STK_CALIB_TENMS_MSK      = UINT32_C(0b00000000111111111111111111111111);
constexpr std::uint32_t STK_CALIB_TENMS_POS      = UINT32_C(0);
constexpr std::uint32_t STK_CALIB_SKEW_MSK       = UINT32_C(0b01000000000000000000000000000000);
constexpr std::uint32_t STK_CALIB_SKEW_POS       = UINT32_C(30);
constexpr std::uint32_t STK_CALIB_NOREF_MSK      = UINT32_C(0b10000000000000000000000000000000);
constexpr std::uint32_t STK_CALIB_NOREF_POS      = UINT32_C(31);

} /* namespace systick */
} /* namespace hal */