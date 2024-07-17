#pragma once

#include "hal/gpio/constants.hpp"
#include "hal/register.hpp"
#include "hal/common.hpp"

namespace hal {
namespace gpio {

template <ports port, pins pin>
requires (is_valid_port<port> && is_valid_pin<pin>)
class CPin {
private:
    GPIO_TypeDef* m_gpio { reinterpret_cast<GPIO_TypeDef*>(port_to_base_address<port>()) };
public:
    template <modes mode>
    requires (is_valid_mode<mode>)
    inline bool configure () const {
        CRegister::set(&m_gpio->MODER, moder_value<pin, mode>(), moder_bitmask<pin>());
        //rcc::CAhbEnRegister ahb_en_register {};

        //ahb_en_register.enable_gpio_clock<port>();
        reset();

        return true;
    }

    inline void set () const {
        CRegister::set_bits(&m_gpio->BSRR, bsrr_bitmask<set_reset::set, pin>());
    }

    inline void reset () const {
        CRegister::set_bits(&m_gpio->BSRR, bsrr_bitmask<set_reset::reset, pin>());
    }

    inline void write (bool level) const {
        if (level) {
            set();
        }
        else {
            reset();
        }
    }
};

template <ports port>
requires (is_valid_port<port>)
class CPort {
private:
    static constexpr std::uint32_t m_address = port_to_base_address<port>();
    using m_reg_t = GPIO_TypeDef;
public:
    template <pins... pin>
    static inline void reset() {
        CRegister::set(&reinterpret_cast<m_reg_t*>(m_address)->BSRR, bsrr_bitmask<set_reset::reset, pin...>());
    }

    template <pins... pin>
    static inline void set() {
        CRegister::set(&reinterpret_cast<m_reg_t*>(m_address)->BSRR, bsrr_bitmask<set_reset::set, pin...>());
    }
};

} /* namespace gpio */
} /* namespace hal */