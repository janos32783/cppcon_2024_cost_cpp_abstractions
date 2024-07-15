#pragma once

#include <cstdint>

#include "hal/register.hpp"
#include "hal/gpio/gpio.hpp"
#include "hal/CMSIS/Device/ST/STM32F0xx/Include/stm32f030xc.h"

namespace hal {
namespace rcc {

class CRcc {
private:
    RCC_TypeDef* m_rcc { reinterpret_cast<RCC_TypeDef*>(RCC_BASE) };
public:
    template<gpio::ports port>
    requires (gpio::is_valid_port<port>)
    inline void enable_gpio_clock () {
        if constexpr (port == gpio::ports::port_a) { CRegister::set_bits(&m_rcc->AHBENR, RCC_AHBENR_GPIOAEN); }
        else if constexpr (port == gpio::ports::port_b) { CRegister::set_bits(&m_rcc->AHBENR, RCC_AHBENR_GPIOBEN); }
        else if constexpr (port == gpio::ports::port_c) { CRegister::set_bits(&m_rcc->AHBENR, RCC_AHBENR_GPIOCEN); }
        else if constexpr (port == gpio::ports::port_d) { CRegister::set_bits(&m_rcc->AHBENR, RCC_AHBENR_GPIODEN); }
        else { CRegister::set_bits(&m_rcc->AHBENR, RCC_AHBENR_GPIOFEN); }
    }
};
} /* namespace rcc */
} /* namespace hal */