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
constexpr std::chrono::milliseconds CLOCKSWITCH_TIMEOUT_VALUE { 5000 };

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

enum class lse_states {
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

enum class hsi_states {
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

enum class hsi14_states {
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

enum class lsi_states {
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

enum class pll_states {
    noconf,
    off,
    on
};

template <pll_states state>
concept is_valid_pll_state = (
    (state == pll_states::noconf) ||
    (state == pll_states::off) ||
    (state == pll_states::on)
);

enum class pll_sources {
    hsi,
    hse
};

template <pll_sources source>
concept is_valid_pll_source = (
    (source == pll_sources::hsi) ||
    (source == pll_sources::hse)
);

enum class pll_mul_factors : std::uint32_t {
    mul2  = RCC_CFGR_PLLMUL2,
    mul3  = RCC_CFGR_PLLMUL3,
    mul4  = RCC_CFGR_PLLMUL4,
    mul5  = RCC_CFGR_PLLMUL5,
    mul6  = RCC_CFGR_PLLMUL6,
    mul7  = RCC_CFGR_PLLMUL7,
    mul8  = RCC_CFGR_PLLMUL8,
    mul9  = RCC_CFGR_PLLMUL9,
    mul10 = RCC_CFGR_PLLMUL10,
    mul11 = RCC_CFGR_PLLMUL11,
    mul12 = RCC_CFGR_PLLMUL12,
    mul13 = RCC_CFGR_PLLMUL13,
    mul14 = RCC_CFGR_PLLMUL14,
    mul15 = RCC_CFGR_PLLMUL15,
    mul16 = RCC_CFGR_PLLMUL16
};

template <pll_mul_factors mul>
concept is_valid_pll_mul_factor = (
    (mul == pll_mul_factors::mul2) ||
    (mul == pll_mul_factors::mul3) ||
    (mul == pll_mul_factors::mul4) ||
    (mul == pll_mul_factors::mul5) ||
    (mul == pll_mul_factors::mul6) ||
    (mul == pll_mul_factors::mul7) ||
    (mul == pll_mul_factors::mul8) ||
    (mul == pll_mul_factors::mul9) ||
    (mul == pll_mul_factors::mul10) ||
    (mul == pll_mul_factors::mul11) ||
    (mul == pll_mul_factors::mul12) ||
    (mul == pll_mul_factors::mul13) ||
    (mul == pll_mul_factors::mul14) ||
    (mul == pll_mul_factors::mul15) ||
    (mul == pll_mul_factors::mul16)
);

enum class pll_predic_factors : std::uint32_t {
    div1  = RCC_CFGR2_PREDIV_DIV1,
    div2  = RCC_CFGR2_PREDIV_DIV2,
    div3  = RCC_CFGR2_PREDIV_DIV3,
    div4  = RCC_CFGR2_PREDIV_DIV4,
    div5  = RCC_CFGR2_PREDIV_DIV5,
    div6  = RCC_CFGR2_PREDIV_DIV6,
    div7  = RCC_CFGR2_PREDIV_DIV7,
    div8  = RCC_CFGR2_PREDIV_DIV8,
    div9  = RCC_CFGR2_PREDIV_DIV9,
    div10 = RCC_CFGR2_PREDIV_DIV10,
    div11 = RCC_CFGR2_PREDIV_DIV11,
    div12 = RCC_CFGR2_PREDIV_DIV12,
    div13 = RCC_CFGR2_PREDIV_DIV13,
    div14 = RCC_CFGR2_PREDIV_DIV14,
    div15 = RCC_CFGR2_PREDIV_DIV15,
    div16 = RCC_CFGR2_PREDIV_DIV16
};

template <pll_predic_factors div>
concept is_valid_pll_prediv_factor = (
    (div == pll_predic_factors::div1) ||
    (div == pll_predic_factors::div2) ||
    (div == pll_predic_factors::div3) ||
    (div == pll_predic_factors::div4) ||
    (div == pll_predic_factors::div5) ||
    (div == pll_predic_factors::div6) ||
    (div == pll_predic_factors::div7) ||
    (div == pll_predic_factors::div8) ||
    (div == pll_predic_factors::div9) ||
    (div == pll_predic_factors::div10) ||
    (div == pll_predic_factors::div11) ||
    (div == pll_predic_factors::div12) ||
    (div == pll_predic_factors::div13) ||
    (div == pll_predic_factors::div14) ||
    (div == pll_predic_factors::div15) ||
    (div == pll_predic_factors::div16)
);

struct PllInitConfig {
    pll_states pll_state { pll_states::noconf };
    pll_sources pll_source { pll_sources::hsi };
    pll_mul_factors pll_mul { pll_mul_factors::mul2 };
    pll_predic_factors pll_div { pll_predic_factors::div1 };
};

template <PllInitConfig conf>
concept is_valid_pll_init_conf = (
    is_valid_pll_state<conf.pll_state> &&
    is_valid_pll_source<conf.pll_source> &&
    is_valid_pll_mul_factor<conf.pll_mul> &&
    is_valid_pll_prediv_factor<conf.pll_div>
);

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
    is_valid_lsi_state<conf.lsi_state> &&
    is_valid_pll_init_conf<conf.pll>
);

// system clock sources

enum class system_clock_sources {
    hsi,
    hse,
    pll
};

template <system_clock_sources src>
concept is_valid_system_clock_source = (
    (src == system_clock_sources::hsi) ||
    (src == system_clock_sources::hse) ||
    (src == system_clock_sources::pll)
);

enum class ahb_clk_dividers : std::uint32_t {
    div1   = RCC_CFGR_HPRE_DIV1,
    div2   = RCC_CFGR_HPRE_DIV2,
    div4   = RCC_CFGR_HPRE_DIV4,
    div8   = RCC_CFGR_HPRE_DIV8,
    div16  = RCC_CFGR_HPRE_DIV16,
    div64  = RCC_CFGR_HPRE_DIV64,
    div128 = RCC_CFGR_HPRE_DIV128,
    div256 = RCC_CFGR_HPRE_DIV256,
    div512 = RCC_CFGR_HPRE_DIV512
};

template <ahb_clk_dividers div>
concept is_valid_ahb_clk_divider = (
    (div == ahb_clk_dividers::div1) ||
    (div == ahb_clk_dividers::div2) ||
    (div == ahb_clk_dividers::div4) ||
    (div == ahb_clk_dividers::div8) ||
    (div == ahb_clk_dividers::div16) ||
    (div == ahb_clk_dividers::div64) ||
    (div == ahb_clk_dividers::div128) ||
    (div == ahb_clk_dividers::div256) ||
    (div == ahb_clk_dividers::div512)
);

enum class hclk_dividers : std::uint32_t {
    div1  = RCC_CFGR_PPRE_DIV1,
    div2  = RCC_CFGR_PPRE_DIV2,
    div4  = RCC_CFGR_PPRE_DIV4,
    div8  = RCC_CFGR_PPRE_DIV8,
    div16 = RCC_CFGR_PPRE_DIV16
};

template <hclk_dividers div>
concept is_valid_hclk_divider = (
    (div == hclk_dividers::div1) ||
    (div == hclk_dividers::div2) ||
    (div == hclk_dividers::div4) ||
    (div == hclk_dividers::div8) ||
    (div == hclk_dividers::div16)
);

struct ClkInitConfig {
    bool is_sysclk { false };
    bool is_hclk { false };
    bool is_pclk1 { false };
    system_clock_sources system_clock_source { system_clock_sources::hsi };
    ahb_clk_dividers ahb_clk_div { ahb_clk_dividers::div1 };
    hclk_dividers hclk_div { hclk_dividers::div1 };
};

template <ClkInitConfig conf>
concept is_valid_clk_init_conf = (
    is_valid_system_clock_source<conf.system_clock_source> &&
    is_valid_ahb_clk_divider<conf.ahb_clk_div> &&
    is_valid_hclk_divider<conf.hclk_div>
);

} /* namespace rcc */
} /* namespace hal */