#pragma once

#include "hal/common.hpp"

namespace hal {
namespace rcc {

constexpr std::uint32_t RCC_PLLSOURCE_HSE = RCC_CFGR_PLLSRC_HSE_PREDIV;

// oscillator types

enum class oscillator_types : std::uint32_t {
    none  = 0x00000000U,
    hse   = 0x00000001U,
    hsi   = 0x00000002U,
    lse   = 0x00000004U,
    lsi   = 0x00000008U,
    hsi14 = 0x00000010U,
    hsi_and_hsi14 = 0x00000002U | 0x00000010U
};

template <oscillator_types type>
concept is_valid_oscillator_type = (
    (type == oscillator_types::hse) ||
    (type == oscillator_types::hsi) ||
    (type == oscillator_types::lse) ||
    (type == oscillator_types::lsi) ||
    (type == oscillator_types::hsi14) ||
    (type == oscillator_types::hsi_and_hsi14)
);

// HSE

enum class hse_states : std::uint32_t {
    off    = 0x00000000U,
    on     = 0x00000001U,
    bypass = 0x00000005U
};

template <hse_states state>
concept is_valid_hse_state = (
    (state == hse_states::off) ||
    (state == hse_states::on)  ||
    (state == hse_states::bypass)
);

// LSE

enum class lse_states : std::uint32_t {
    off    = 0x00000000U,
    on     = 0x00000001U,
    bypass = 0x00000005U
};

template <lse_states state>
concept is_valid_lse_state = (
    (state == lse_states::off) ||
    (state == lse_states::on)  ||
    (state == lse_states::bypass)
);

// HSI

enum class hsi_states : std::uint32_t {
    off    = 0x00000000U,
    on     = RCC_CR_HSION
};

template <hsi_states state>
concept is_valid_hsi_state = (
    (state == hsi_states::off) ||
    (state == hsi_states::on)
);

constexpr std::uint32_t hsi_calibration_default { 0x10U };

// HSI14

enum class hsi14_states : std::uint32_t {
    off         = 0x00000000U,
    on          = RCC_CR2_HSI14ON,
    adc_control = (~RCC_CR2_HSI14DIS)
};

template <hsi14_states state>
concept is_valid_hsi14_state = (
    (state == hsi14_states::off) ||
    (state == hsi14_states::on)  ||
    (state == hsi14_states::adc_control)
);

constexpr std::uint32_t hsi14_calibration_default { 0x10U };

// LSI

enum class lsi_states : std::uint32_t {
    off    = 0x00000000U,
    on     = RCC_CSR_LSION
};

template <lsi_states state>
concept is_valid_lsi_state = (
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
    oscillator_types oscillator_type { oscillator_types::none };
    hse_states hse_state { hse_states::off };
    lse_states lse_state { lse_states::off };
    hsi_states hsi_state { hsi_states::off };
    uint32_t hsi_calib_value { hsi_calibration_default };
    hsi14_states hsi14_state { hsi14_states::off };
    uint32_t hs14_calib_value { hsi14_calibration_default };
    lsi_states lsi_state { lsi_states::off };
    PllInitConfig PLL;        
};

template <OscInitConfig conf>
concept is_valid_osc_init_conf = (
    is_valid_oscillator_type<conf.oscillator_type> &&
    is_valid_hse_state<conf.hse_state> &&
    is_valid_lse_state<conf.lse_state> &&
    is_valid_hsi_state<conf.hsi_state> &&
    is_valid_hsi14_state<conf.hsi14_state> &&
    is_valid_lsi_state<conf.lsi_state>
);

} /* namespace rcc */
} /* namespace hal */