#pragma once

#include "hal/register.hpp"
#include "hal/rcc/constants.hpp"
#include "hal/gpio/constants.hpp"
#include "hal/flash/flash.hpp"
#include "hal/systick/systick.hpp"
#include "hal/common.hpp"

namespace hal {
namespace rcc {

template <OscInitConfig osc_conf, ClkInitConfig clk_conf, std::uint32_t HSE_FREQ>
requires (is_valid_osc_init_conf<osc_conf> && is_valid_clk_init_conf<clk_conf>)
consteval std::uint32_t calculate_core_frequency () {
    std::uint32_t core_freq = 0;
    if constexpr (clk_conf.system_clock_source == system_clock_sources::hsi) {
        core_freq = HSI_FREQ;
    }
    else if constexpr (clk_conf.system_clock_source == system_clock_sources::hse) {
        core_freq = HSE_FREQ;
    }
    else if constexpr (clk_conf.system_clock_source == system_clock_sources::pll) {
        std::uint32_t pllmull = (static_cast<std::uint32_t>(osc_conf.pll.pll_mul) >> RCC_CFGR_PLLMUL_Pos) + 2;
        std::uint32_t predivfactor = static_cast<std::uint32_t>(osc_conf.pll.pll_div) + 1;
        if constexpr (osc_conf.pll.pll_source == pll_sources::hse) {
            // HSE used as PLL clock source : SystemCoreClock = HSE/PREDIV * PLLMUL
            core_freq = (HSE_FREQ / predivfactor) * pllmull;
        }
        else {
            // HSI used as PLL clock source : SystemCoreClock = HSI/2 * PLLMUL
            core_freq = (HSI_FREQ / 2) * pllmull;
        }
    }
    else {
        core_freq = HSI_FREQ;
    }
    std::uint8_t hclk_prescaler = 0;
    switch (clk_conf.ahb_clk_div) {
        case ahb_clk_dividers::div1   : { hclk_prescaler = 0; break; }
        case ahb_clk_dividers::div2   : { hclk_prescaler = 1; break; }
        case ahb_clk_dividers::div4   : { hclk_prescaler = 2; break; }
        case ahb_clk_dividers::div8   : { hclk_prescaler = 3; break; }
        case ahb_clk_dividers::div16  : { hclk_prescaler = 4; break; }
        case ahb_clk_dividers::div64  : { hclk_prescaler = 6; break; }
        case ahb_clk_dividers::div128 : { hclk_prescaler = 7; break; }
        case ahb_clk_dividers::div256 : { hclk_prescaler = 8; break; }
        case ahb_clk_dividers::div512 : { hclk_prescaler = 9; break; }
    }
    core_freq >>= hclk_prescaler;
    return core_freq;
}

class CRcc {
private:
    static constexpr std::uint32_t m_address = RCC_BASE;
    using m_reg_t = RCC_TypeDef;
    static inline void delay () {
        __asm("NOP");
    }

    static inline bool is_hse_ready () {
        return CRegister::is_set(&reinterpret_cast<m_reg_t*>(m_address)->CR, RCC_CR_HSERDY);
    }
    static inline bool is_hsi_ready () {
        return CRegister::is_set(&reinterpret_cast<m_reg_t*>(m_address)->CR, RCC_CR_HSIRDY);
    }
    static inline bool is_lsi_ready () {
        return CRegister::is_set(&reinterpret_cast<m_reg_t*>(m_address)->CSR, RCC_CSR_LSIRDY);
    }
    static inline bool is_lse_ready () {
        return CRegister::is_set(&reinterpret_cast<m_reg_t*>(m_address)->BDCR, RCC_BDCR_LSERDY);
    }
    static inline bool is_hsi14_ready () {
        return CRegister::is_set(&reinterpret_cast<m_reg_t*>(m_address)->CR2, RCC_CR2_HSI14RDY);
    }
    static inline bool is_pll_ready () {
        return CRegister::is_set(&reinterpret_cast<m_reg_t*>(m_address)->CR, RCC_CR_PLLRDY);
    }
    static inline std::uint32_t get_sysclk_source () {
        return CRegister::get_bits(&reinterpret_cast<m_reg_t*>(m_address)->CFGR, RCC_CFGR_SWS);
    }
    static inline std::uint32_t get_pll_source () {
        return CRegister::get_bits(&reinterpret_cast<m_reg_t*>(m_address)->CFGR, RCC_CFGR_PLLSRC);
    }
    template <std::uint32_t calib>
    static inline void calibrate_hsi () {
        CRegister::set(&reinterpret_cast<m_reg_t*>(m_address)->CR, calib << RCC_CR_HSITRIM_Pos, RCC_CR_HSITRIM);
    }
    template <std::uint32_t calib>
    static inline void calibrate_hsi14 () {
        CRegister::set(&reinterpret_cast<m_reg_t*>(m_address)->CR2, calib << RCC_CR2_HSI14TRIM_Pos, RCC_CR2_HSI14TRIM);
    }
public:
    template<gpio::ports port>
    requires (gpio::is_valid_port<port>)
    static inline void enable_gpio_clock () {
        if constexpr (port == gpio::ports::port_a) { CRegister::set_bits(&reinterpret_cast<m_reg_t*>(m_address)->AHBENR, RCC_AHBENR_GPIOAEN); }
        else if constexpr (port == gpio::ports::port_b) { CRegister::set_bits(&reinterpret_cast<m_reg_t*>(m_address)->AHBENR, RCC_AHBENR_GPIOBEN); }
        else if constexpr (port == gpio::ports::port_c) { CRegister::set_bits(&reinterpret_cast<m_reg_t*>(m_address)->AHBENR, RCC_AHBENR_GPIOCEN); }
        else if constexpr (port == gpio::ports::port_d) { CRegister::set_bits(&reinterpret_cast<m_reg_t*>(m_address)->AHBENR, RCC_AHBENR_GPIODEN); }
        else { CRegister::set_bits(&reinterpret_cast<m_reg_t*>(m_address)->AHBENR, RCC_AHBENR_GPIOFEN); }
        // delay after an RCC peripheral clock enabling
        delay();
    }

    static inline void enable_syscfg_clock () {
        CRegister::set_bits(&reinterpret_cast<m_reg_t*>(m_address)->APB2ENR, RCC_APB2ENR_SYSCFGEN);
        // delay after an RCC peripheral clock enabling
        delay();
    }

    static inline void enable_pwr_clock () {
        CRegister::set_bits(&reinterpret_cast<m_reg_t*>(m_address)->APB1ENR, RCC_APB1ENR_PWREN);
        // delay after an RCC peripheral clock enabling
        delay();
    }

    static inline void disable_pwr_clock () {
        CRegister::clear_bits(&reinterpret_cast<m_reg_t*>(m_address)->APB1ENR, RCC_APB1ENR_PWREN);
        // delay after an RCC peripheral clock enabling
        delay();
    }

    template <ClkInitConfig conf, std::uint32_t flash_latency>
    requires (is_valid_clk_init_conf<conf> && flash::is_valid_flash_latency<flash_latency>)
    static inline hal_error configure_clock () {
        if (flash_latency > flash::CFlash::get_latency()) {
            flash::CFlash::set_latency<flash_latency>();
            if (flash::CFlash::get_latency() != flash_latency) {
                return hal_error::error;
            }
        }
        if constexpr (conf.is_hclk) {
            if constexpr (conf.is_pclk1) {
                CRegister::set(&reinterpret_cast<m_reg_t*>(m_address)->CFGR, static_cast<std::uint32_t>(hclk_dividers::div16), RCC_CFGR_PPRE);
            }
            CRegister::set(&reinterpret_cast<m_reg_t*>(m_address)->CFGR, static_cast<std::uint32_t>(conf.ahb_clk_div), RCC_CFGR_HPRE);
        }
        if constexpr (conf.is_sysclk) {
            std::uint32_t bitmask = 0;
            std::uint32_t expected = 0;
            if constexpr (conf.system_clock_source == system_clock_sources::hse) {
                if (!is_hse_ready()) {
                    return hal_error::error;
                }
                bitmask = RCC_CFGR_SW_HSE;
                expected = RCC_CFGR_SWS_HSE;
            }
            else if constexpr (conf.system_clock_source == system_clock_sources::pll) {
                if (!is_pll_ready()) {
                    return hal_error::error;
                }
                bitmask = RCC_CFGR_SW_PLL;
                expected = RCC_CFGR_SWS_PLL;
            }
            else {
                if (!is_hsi_ready()) {
                    return hal_error::error;
                }
                bitmask = RCC_CFGR_SW_HSI;
                expected = RCC_CFGR_SWS_HSI;
            }
            CRegister::set_bits(&reinterpret_cast<m_reg_t*>(m_address)->CFGR, bitmask);
            auto tickstart = systick::CSysTick::now();
            while (get_sysclk_source() != expected) {
                if ((systick::CSysTick::now() - tickstart) > CLOCKSWITCH_TIMEOUT_VALUE) {
                    return hal_error::timeout;
                }
            }
        }
        if (flash_latency < flash::CFlash::get_latency()) {
            flash::CFlash::set_latency<flash_latency>();
            if (flash::CFlash::get_latency() != flash_latency) {
                return hal_error::error;
            }
        }
        if constexpr (conf.is_pclk1) {
            CRegister::set(&reinterpret_cast<m_reg_t*>(m_address)->CFGR, static_cast<std::uint32_t>(conf.hclk_div), RCC_CFGR_PPRE);
        }
  
        /* Update the SystemCoreClock global variable */
        //SystemCoreClock = HAL_RCC_GetSysClockFreq() >> AHBPrescTable[(RCC->CFGR & RCC_CFGR_HPRE)>> RCC_CFGR_HPRE_BITNUMBER];

        /* Configure the source of time base considering new system clocks settings*/
        //HAL_InitTick (TICK_INT_PRIORITY);
  
        return hal_error::ok;
    }

    template <OscInitConfig osc_conf>
    requires (is_valid_osc_init_conf<osc_conf>)
    static inline hal_error configure_oscillator () {
        if constexpr (osc_conf.hse_state != hse_states::noconf) {
            std::uint32_t sysclk_source = get_sysclk_source();
            std::uint32_t pll_source = get_pll_source();
            if ((sysclk_source == RCC_CFGR_SWS_HSE) || ((sysclk_source == RCC_CFGR_SWS_PLL) && (pll_source == RCC_PLLSOURCE_HSE))) {
                if (!is_hse_ready() && (osc_conf.hse_state == hse_states::off)) {
                    return hal_error::error;
                }
            }
            else {
                if constexpr (osc_conf.hse_state == hse_states::on) {
                    CRegister::set_bits(&reinterpret_cast<m_reg_t*>(m_address)->CR, RCC_CR_HSEON);
                }
                else if constexpr (osc_conf.hse_state == hse_states::bypass) {
                    CRegister::set_bits(&reinterpret_cast<m_reg_t*>(m_address)->CR, RCC_CR_HSEBYP);
                    CRegister::set_bits(&reinterpret_cast<m_reg_t*>(m_address)->CR, RCC_CR_HSEON);
                }
                else {
                    CRegister::clear_bits(&reinterpret_cast<m_reg_t*>(m_address)->CR, RCC_CR_HSEON);
                    CRegister::clear_bits(&reinterpret_cast<m_reg_t*>(m_address)->CR, RCC_CR_HSEBYP);
                }

                if constexpr (osc_conf.hse_state != hse_states::off) {
                    auto tickstart = systick::CSysTick::now();
                    while (!is_hse_ready()) {
                        if ((systick::CSysTick::now() - tickstart) > HSE_TIMEOUT_VALUE) {
                            return hal_error::timeout;
                        }
                    }
                }
                else {
                    auto tickstart = systick::CSysTick::now();
                    while (is_hse_ready()) {
                        if ((systick::CSysTick::now() - tickstart) > HSE_TIMEOUT_VALUE) {
                            return hal_error::timeout;
                        }
                    }
                }
            }
        }
        if constexpr (osc_conf.hsi_state != hsi_states::noconf) {
            std::uint32_t sysclk_source = get_sysclk_source();
            std::uint32_t pll_source = get_pll_source();
            if ((sysclk_source == RCC_CFGR_SWS_HSI) || ((sysclk_source == RCC_CFGR_SWS_PLL) && (pll_source == RCC_PLLSOURCE_HSI))) {
                if (!is_hsi_ready() && (osc_conf.hsi_state != hsi_states::on)) {
                    return hal_error::error;
                }
                else {
                    calibrate_hsi<osc_conf.hsi_calib_value>();
                }
            }
            else {
                if constexpr (osc_conf.hsi_state != hsi_states::off) {
                    CRegister::set_bits(&reinterpret_cast<m_reg_t*>(m_address)->CR, RCC_CR_HSION);
                    auto tickstart = systick::CSysTick::now();
                    while (!is_hsi_ready()) {
                        if ((systick::CSysTick::now() - tickstart) > HSI_TIMEOUT_VALUE) {
                            return hal_error::timeout;
                        }
                    }
                    calibrate_hsi<osc_conf.hsi_calib_value>();
                }
                else {
                    CRegister::clear_bits(&reinterpret_cast<m_reg_t*>(m_address)->CR, RCC_CR_HSION);
                    auto tickstart = systick::CSysTick::now();
                    while (is_hsi_ready()) {
                        if ((systick::CSysTick::now() - tickstart) > HSI_TIMEOUT_VALUE) {
                            return hal_error::timeout;
                        }
                    }
                }
            }
        }
        if constexpr (osc_conf.lsi_state != lsi_states::noconf) {
            if constexpr (osc_conf.lsi_state != lsi_states::off) {
                CRegister::set_bits(&reinterpret_cast<m_reg_t*>(m_address)->CSR, RCC_CSR_LSION);
                auto tickstart = systick::CSysTick::now();
                while (!is_lsi_ready()) {
                    if ((systick::CSysTick::now() - tickstart) > LSI_TIMEOUT_VALUE) {
                        return hal_error::timeout;
                    }
                }
            }
            else {
                CRegister::clear_bits(&reinterpret_cast<m_reg_t*>(m_address)->CSR, RCC_CSR_LSION);
                auto tickstart = systick::CSysTick::now();
                while (is_lsi_ready()) {
                    if ((systick::CSysTick::now() - tickstart) > LSI_TIMEOUT_VALUE) {
                        return hal_error::timeout;
                    }
                }
            }
        }
        if constexpr (osc_conf.lse_state != lse_states::noconf) {
            bool power_clk_changed = false;
            if (CRegister::is_cleared(&reinterpret_cast<m_reg_t*>(m_address)->APB1ENR, RCC_APB1ENR_PWREN)) {
                enable_pwr_clock();
                power_clk_changed = true;
            }

            if (CRegister::is_cleared(&reinterpret_cast<m_reg_t*>(m_address)->CR, PWR_CR_DBP)) {
                // Enable write access to Backup domain
                CRegister::set_bits(&reinterpret_cast<m_reg_t*>(m_address)->CR, PWR_CR_DBP);
                auto tickstart = systick::CSysTick::now();
                while (CRegister::is_cleared(&reinterpret_cast<m_reg_t*>(m_address)->CR, PWR_CR_DBP)) {
                    if ((systick::CSysTick::now() - tickstart) > RCC_DBP_TIMEOUT_VALUE) {
                        return hal_error::timeout;
                    }
                }
            }

            if constexpr (osc_conf.lse_state != lse_states::off) {
                CRegister::clear_bits(&reinterpret_cast<m_reg_t*>(m_address)->BDCR, RCC_BDCR_LSEON);
                CRegister::clear_bits(&reinterpret_cast<m_reg_t*>(m_address)->BDCR, RCC_BDCR_LSEBYP);
                auto tickstart = systick::CSysTick::now();
                while (!is_lse_ready()) {
                    if ((systick::CSysTick::now() - tickstart) > LSE_STARTUP_TIMEOUT) {
                        return hal_error::timeout;
                    }
                }
            }
            else {
                if constexpr (osc_conf.lse_state == lse_states::on) {
                    CRegister::set_bits(&reinterpret_cast<m_reg_t*>(m_address)->BDCR, RCC_BDCR_LSEON);
                }
                else {
                    CRegister::set_bits(&reinterpret_cast<m_reg_t*>(m_address)->BDCR, RCC_BDCR_LSEBYP);
                    CRegister::set_bits(&reinterpret_cast<m_reg_t*>(m_address)->BDCR, RCC_BDCR_LSEON);
                }
                CRegister::clear_bits(&reinterpret_cast<m_reg_t*>(m_address)->CR, RCC_CR_HSION);
                auto tickstart = systick::CSysTick::now();
                while (is_lse_ready()) {
                    if ((systick::CSysTick::now() - tickstart) > LSE_STARTUP_TIMEOUT) {
                        return hal_error::timeout;
                    }
                }
            }

            if(power_clk_changed) {
                disable_pwr_clock();
            }
        }
        if constexpr (osc_conf.hsi14_state != hsi14_states::noconf) {
            if constexpr (osc_conf.hsi14_state == hsi14_states::on) {
                CRegister::set_bits(&reinterpret_cast<m_reg_t*>(m_address)->CR2, RCC_CR2_HSI14DIS);
                CRegister::set_bits(&reinterpret_cast<m_reg_t*>(m_address)->CR2, RCC_CR2_HSI14ON);
                auto tickstart = systick::CSysTick::now();
                while (!is_hsi14_ready()) {
                    if ((systick::CSysTick::now() - tickstart) > HSI14_TIMEOUT_VALUE) {
                        return hal_error::timeout;
                    }
                }
                calibrate_hsi14<osc_conf.hsi14_calib_value>();
            }
            else if constexpr (osc_conf.hsi14_state == hsi14_states::adc_control) {
                CRegister::clear_bits(&reinterpret_cast<m_reg_t*>(m_address)->CR2, RCC_CR2_HSI14DIS);
                calibrate_hsi14<osc_conf.hsi14_calib_value>();
            }
            else
            {
                CRegister::set_bits(&reinterpret_cast<m_reg_t*>(m_address)->CR2, RCC_CR2_HSI14DIS);
                CRegister::clear_bits(&reinterpret_cast<m_reg_t*>(m_address)->CR2, RCC_CR2_HSI14ON);
                auto tickstart = systick::CSysTick::now();
                while (is_hsi14_ready()) {
                    if ((systick::CSysTick::now() - tickstart) > HSI14_TIMEOUT_VALUE) {
                        return hal_error::timeout;
                    }
                }
            }
        }
        if constexpr (osc_conf.pll.pll_state != pll_states::noconf) {
            if (get_sysclk_source() != RCC_CFGR_SWS_PLL) {
                CRegister::clear_bits(&reinterpret_cast<m_reg_t*>(m_address)->CR, RCC_CR_PLLON);
                auto tickstart = systick::CSysTick::now();
                while (!is_pll_ready()) {
                    if ((systick::CSysTick::now() - tickstart) > PLL_TIMEOUT_VALUE) {
                        return hal_error::timeout;
                    }
                }
                if constexpr (osc_conf.pll.pll_state == pll_states::on) {
                    CRegister::set(&reinterpret_cast<m_reg_t*>(m_address)->CFGR2, static_cast<std::uint32_t>(osc_conf.pll.pll_div), RCC_CFGR2_PREDIV);
                    CRegister::set(&reinterpret_cast<m_reg_t*>(m_address)->CFGR, static_cast<std::uint32_t>(osc_conf.pll.pll_mul), RCC_CFGR_PLLMUL);
                    if constexpr (osc_conf.pll.pll_source == pll_sources::hse) {
                        CRegister::set_bits(&reinterpret_cast<m_reg_t*>(m_address)->CFGR, RCC_CFGR_PLLSRC);
                    }
                    else {
                        CRegister::clear_bits(&reinterpret_cast<m_reg_t*>(m_address)->CFGR, RCC_CFGR_PLLSRC);
                    }
                    CRegister::set_bits(&reinterpret_cast<m_reg_t*>(m_address)->CR, RCC_CR_PLLON);
                    tickstart = systick::CSysTick::now();
                    while (is_pll_ready()) {
                        if ((systick::CSysTick::now() - tickstart) > PLL_TIMEOUT_VALUE) {
                            return hal_error::timeout;
                        }
                    }
                }
                else {
                    // if the pll is the sysclock source, it cannot be disabled
                    if constexpr (osc_conf.pll.pll_state == pll_states::off) {
                        return hal_error::error;
                    }
                    else {
                        // return error if the configuration request does not match the current configuration
                        std::uint32_t cfgr = CRegister::get(&reinterpret_cast<m_reg_t*>(m_address)->CFGR);
                        std::uint32_t cfgr2 = CRegister::get(&reinterpret_cast<m_reg_t*>(m_address)->CFGR2);
                        if ((cfgr2 & RCC_CFGR2_PREDIV) != static_cast<std::uint32_t>(osc_conf.pll.pll_div)) {
                            return hal_error::error;
                        }
                        if ((cfgr & RCC_CFGR_PLLMUL) != static_cast<std::uint32_t>(osc_conf.pll.pll_mul)) {
                            return hal_error::error;
                        }
                        if constexpr (osc_conf.pll.pll_source == pll_sources::hse) {
                            if (!(cfgr & RCC_CFGR_PLLSRC)) {
                                return hal_error::error;
                            }
                        }
                        else {
                            if (cfgr & RCC_CFGR_PLLSRC) {
                                return hal_error::error;
                            }
                        }
                    }
                }
            }
        }
        return hal_error::ok;
    }
};


} /* namespace rcc */
} /* namespace hal */