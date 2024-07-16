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
        if constexpr (osc_conf.hse_state != hse_states::noconf) {
            std::uint32_t sysclk_source = CRegister::get_bits(&reinterpret_cast<m_reg_t*>(m_address)->CFGR, RCC_CFGR_SWS);
            std::uint32_t pll_source = CRegister::get_bits(&reinterpret_cast<m_reg_t*>(m_address)->CFGR, RCC_CFGR_PLLSRC);
            if ((sysclk_source == RCC_CFGR_SWS_HSE) || ((sysclk_source == RCC_CFGR_SWS_PLL) && (pll_source == RCC_PLLSOURCE_HSE))) {
                if (!is_hse_ready() && (osc_conf.hse_state == hse_states::off))
                {
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
            /* Check if HSI is used as system clock or as PLL source when PLL is selected as system clock */ 
            if((__HAL_RCC_GET_SYSCLK_SOURCE() == RCC_SYSCLKSOURCE_STATUS_HSI) 
            || ((__HAL_RCC_GET_SYSCLK_SOURCE() == RCC_SYSCLKSOURCE_STATUS_PLLCLK) && (__HAL_RCC_GET_PLL_OSCSOURCE() == RCC_PLLSOURCE_HSI)))
            {
                /* When HSI is used as system clock it will not disabled */
                if((__HAL_RCC_GET_FLAG(RCC_FLAG_HSIRDY) != RESET) && (RCC_OscInitStruct->HSIState != RCC_HSI_ON))
                {
                    return HAL_ERROR;
                }
                /* Otherwise, just the calibration is allowed */
                else
                {
                    /* Adjusts the Internal High Speed oscillator (HSI) calibration value.*/
                    __HAL_RCC_HSI_CALIBRATIONVALUE_ADJUST(RCC_OscInitStruct->HSICalibrationValue);
                }
            }
            else
            {
                /* Check the HSI State */
                if(RCC_OscInitStruct->HSIState != RCC_HSI_OFF)
                {
                /* Enable the Internal High Speed oscillator (HSI). */
                    __HAL_RCC_HSI_ENABLE();
                    
                    /* Get Start Tick */
                    tickstart = HAL_GetTick();
                    
                    /* Wait till HSI is ready */
                    while(__HAL_RCC_GET_FLAG(RCC_FLAG_HSIRDY) == RESET)
                    {
                    if((HAL_GetTick() - tickstart ) > HSI_TIMEOUT_VALUE)
                    {
                        return HAL_TIMEOUT;
                    }
                    }
                            
                    /* Adjusts the Internal High Speed oscillator (HSI) calibration value.*/
                    __HAL_RCC_HSI_CALIBRATIONVALUE_ADJUST(RCC_OscInitStruct->HSICalibrationValue);
                }
                else
                {
                    /* Disable the Internal High Speed oscillator (HSI). */
                    __HAL_RCC_HSI_DISABLE();
                    
                    /* Get Start Tick */
                    tickstart = HAL_GetTick();
                    
                    /* Wait till HSI is disabled */
                    while(__HAL_RCC_GET_FLAG(RCC_FLAG_HSIRDY) != RESET)
                    {
                    if((HAL_GetTick() - tickstart ) > HSI_TIMEOUT_VALUE)
                    {
                        return HAL_TIMEOUT;
                    }
                    }
                }
            }
        }
        if constexpr (osc_conf.lsi_state != lsi_states::noconf) {

        }
        if constexpr (osc_conf.lse_state != lse_states::noconf) {

        }
        if constexpr (osc_conf.hsi14_state != hsi14_states::noconf) {

        }
        // PLL
        return hal_error::ok;
    }
};


} /* namespace rcc */
} /* namespace hal */