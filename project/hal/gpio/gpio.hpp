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
    bool configure () const {
        CRegister::set(&m_gpio->MODER, moder_value<pin, mode>(), moder_bitmask<pin>());
        //rcc::CAhbEnRegister ahb_en_register {};

        //ahb_en_register.enable_gpio_clock<port>();
        reset();

        return true;
    }

    void set () const {
        CRegister::set_bits(&m_gpio->BSRR, bsrr_bitmask<pin, set_reset::set>());
    }

    void reset () const {
        CRegister::set_bits(&m_gpio->BSRR, bsrr_bitmask<pin, set_reset::reset>());
    }

    void write (bool level) const {
        if (level) {
            set();
        }
        else {
            reset();
        }
    }
};

} /* namespace gpio */
} /* namespace hal */