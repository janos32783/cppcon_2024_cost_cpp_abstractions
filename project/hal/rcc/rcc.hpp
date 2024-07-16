#pragma once

#include <cstdint>

#include "hal/register.hpp"
#include "hal/gpio/gpio.hpp"
#include "hal/CMSIS/Device/ST/STM32F0xx/Include/stm32f030xc.h"

namespace hal {
namespace rcc {

class CRcc {
private:
    static constexpr std::uint32_t m_address = RCC_BASE;
    using m_reg_t = RCC_TypeDef;
    static inline void delay () {
        __asm("NOP");
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
};


} /* namespace rcc */
} /* namespace hal */