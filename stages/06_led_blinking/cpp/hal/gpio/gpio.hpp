#pragma once

#include <cstdint>

#include "hal/gpio/constants.hpp"
#include "hal/gpio/registers.hpp"
#include "hal/rcc/registers.hpp"

namespace hal {

template <gpio_ports port,
          gpio_pins pin,
          gpio_modes mode>
class CGpio {
public:
    bool configure () const {
        CModeRegister<port> mode_register {};
        CAhbEnRegister ahb_en_register {};

        ahb_en_register.enable_gpio_clock<port>();
        mode_register.template set_mode<pin, mode>();
        reset();

        return true;
    }

    void set () const {
        CBSRRegister<port> bsrr_register {};
        bsrr_register.template set_pin<pin>();
    }

    void reset () const {
        CBSRRegister<port> bsrr_register {};
        bsrr_register.template reset_pin<pin>();
    }
};

} /* namespace hal */