#pragma once

#include "hal/common.hpp"

#include <chrono>

namespace hal {
namespace rcc {

constexpr std::chrono::milliseconds RCC_DBP_TIMEOUT_VALUE { 100 };
constexpr std::chrono::milliseconds HSE_TIMEOUT_VALUE { 100 };
constexpr std::chrono::milliseconds HSI_TIMEOUT_VALUE { 2 };
constexpr std::chrono::milliseconds LSI_TIMEOUT_VALUE { 2 };
constexpr std::chrono::milliseconds PLL_TIMEOUT_VALUE { 2 };
constexpr std::chrono::milliseconds HSI14_TIMEOUT_VALUE { 2 };
constexpr std::chrono::milliseconds LSE_STARTUP_TIMEOUT { 5000 };

constexpr std::uint32_t RCC_PLLSOURCE_HSE = RCC_CFGR_PLLSRC_HSE_PREDIV;
constexpr std::uint32_t RCC_PLLSOURCE_HSI = RCC_CFGR_PLLSRC_HSI_PREDIV;

template <std::uint32_t calib>
concept is_valid_calibration_value = (
    calib <= 0x1FU
);

// HSE

enum class hse_states {
    noconf,
    off,
    on,
    bypass
};

template <hse_states state>
concept is_valid_hse_state = (
    (state == hse_states::noconf) ||
    (state == hse_states::off) ||
    (state == hse_states::on)  ||
    (state == hse_states::bypass)
);

// LSE

enum class lse_states : std::uint32_t {
    noconf,
    off,
    on,
    bypass
};

template <lse_states state>
concept is_valid_lse_state = (
    (state == lse_states::noconf) ||
    (state == lse_states::off) ||
    (state == lse_states::on)  ||
    (state == lse_states::bypass)
);

// HSI

enum class hsi_states : std::uint32_t {
    noconf,
    off,
    on
};

template <hsi_states state>
concept is_valid_hsi_state = (
    (state == hsi_states::noconf) ||
    (state == hsi_states::off) ||
    (state == hsi_states::on)
);

constexpr std::uint32_t hsi_calibration_default { 0x10U };

// HSI14

enum class hsi14_states : std::uint32_t {
    noconf,
    off,
    on,
    adc_control
};

template <hsi14_states state>
concept is_valid_hsi14_state = (
    (state == hsi14_states::noconf) ||
    (state == hsi14_states::off) ||
    (state == hsi14_states::on)  ||
    (state == hsi14_states::adc_control)
);

constexpr std::uint32_t hsi14_calibration_default { 0x10U };

// LSI

enum class lsi_states : std::uint32_t {
    noconf,
    off,
    on
};

template <lsi_states state>
concept is_valid_lsi_state = (
    (state == lsi_states::noconf) ||
    (state == lsi_states::off) ||
    (state == lsi_states::on)
);

// PLL

enum class pll_states : std::uint32_t {
    none = 0x00000000U,
    off  = 0x00000001U,
    on   = 0x00000002U
};

template <pll_states state>
concept is_valid_pll_state = (
    (state == pll_states::none) ||
    (state == pll_states::off) ||
    (state == pll_states::on)
);









struct PllInitConfig {
  pll_states pll_state { pll_states::none };
  uint32_t PLLSource; /* TODO */
  uint32_t PLLMUL;    /* TODO */
  uint32_t PREDIV;    /* TODO */
};

struct OscInitConfig {
    hse_states hse_state { hse_states::noconf };
    lse_states lse_state { lse_states::noconf };
    hsi_states hsi_state { hsi_states::noconf };
    uint32_t hsi_calib_value { hsi_calibration_default };
    hsi14_states hsi14_state { hsi14_states::noconf };
    uint32_t hsi14_calib_value { hsi14_calibration_default };
    lsi_states lsi_state { lsi_states::noconf };
    PllInitConfig pll;        
};

template <OscInitConfig conf>
concept is_valid_osc_init_conf = (
    is_valid_hse_state<conf.hse_state> &&
    is_valid_lse_state<conf.lse_state> &&
    is_valid_hsi_state<conf.hsi_state> &&
    is_valid_calibration_value<conf.hsi_calib_value> &&
    is_valid_hsi14_state<conf.hsi14_state> &&
    is_valid_calibration_value<conf.hsi14_calib_value> &&
    is_valid_lsi_state<conf.lsi_state>
);

} /* namespace rcc */
} /* namespace hal */