#pragma once

#include <cstdint>

#include "hal/gpio/constants.hpp"
#include "hal/gpio/registers.hpp"
#include "hal/rcc/registers.hpp"

namespace hal {
namespace gpio {

template <ports port,
          pins pin,
          modes mode>
class CPin {
public:
    bool configure () const {
        CModeRegister<port> mode_register {};
        rcc::CAhbEnRegister ahb_en_register {};

        ahb_en_register.enable_gpio_clock<port>();
        mode_register.template set_mode<pin, mode>();
        reset();

        return true;
    }

    void set () const {
        CBitSetResetRegister<port> bsrr_register {};
        bsrr_register.template set_pin<pin>();
    }

    void reset () const {
        CBitSetResetRegister<port> bsrr_register {};
        bsrr_register.template reset_pin<pin>();
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