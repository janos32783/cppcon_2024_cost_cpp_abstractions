#pragma once

#include "hal/register.hpp"
#include "hal/rcc/constants.hpp"
#include "hal/gpio/constants.hpp"
#include "hal/systick/systick.hpp"
#include "hal/common.hpp"

namespace hal {
namespace rcc {

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

    template<OscInitConfig osc_conf>
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

        }
        // PLL
        return hal_error::ok;
    }
};


} /* namespace rcc */
} /* namespace hal */