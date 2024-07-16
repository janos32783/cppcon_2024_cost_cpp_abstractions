#pragma once

#include "hal/register.hpp"
#include "hal/rcc/constants.hpp"
#include "hal/gpio/constants.hpp"
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
        return CRegister::is_set(&reinterpret_cast<m_reg_t*>(m_address)->CR, RCC_CR_HSERDY_Msk);
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

    template<OscInitConfig osc_conf>
    requires (is_valid_osc_init_conf<osc_conf>)
    static inline hal_error configure_oscillator () {
        if constexpr (osc_conf.oscillator_type == oscillator_types::hse) {
            std::uint32_t sysclk_source = CRegister::get_bits(&reinterpret_cast<m_reg_t*>(m_address)->CFGR, RCC_CFGR_SWS);
            std::uint32_t pll_source = CRegister::get_bits(&reinterpret_cast<m_reg_t*>(m_address)->CFGR, RCC_CFGR_PLLSRC);
            if ((sysclk_source == RCC_CFGR_SWS_HSE) || ((sysclk_source == RCC_CFGR_SWS_PLL) && (pll_source == RCC_PLLSOURCE_HSE))) {
                if (!is_hse_ready() && (osc_conf.hse_state == hse_states::off))
                {
                    return hal_error::error;
                }
            }
            else {
                /* Check the HSE State */
                if(RCC_OscInitStruct->HSEState != RCC_HSE_OFF)
                {
                    /* Get Start Tick */
                    tickstart = HAL_GetTick();
                    
                    /* Wait till HSE is ready */
                    while(__HAL_RCC_GET_FLAG(RCC_FLAG_HSERDY) == RESET)
                    {
                        if((HAL_GetTick() - tickstart ) > HSE_TIMEOUT_VALUE)
                        {
                            return HAL_TIMEOUT;
                        }
                    }
                }
                else
                {
                    /* Get Start Tick */
                    tickstart = HAL_GetTick();
                    
                    /* Wait till HSE is disabled */
                    while(__HAL_RCC_GET_FLAG(RCC_FLAG_HSERDY) != RESET)
                    {
                        if((HAL_GetTick() - tickstart ) > HSE_TIMEOUT_VALUE)
                        {
                            return HAL_TIMEOUT;
                        }
                    }
                }
            }
        }
        if constexpr (osc_conf.oscillator_type == oscillator_types::hsi) {

        }
        if constexpr (osc_conf.oscillator_type == oscillator_types::lsi) {

        }
        if constexpr (osc_conf.oscillator_type == oscillator_types::lse) {

        }
        if constexpr (osc_conf.oscillator_type == oscillator_types::hsi14) {

        }
        // PLL
    }
};


} /* namespace rcc */
} /* namespace hal */