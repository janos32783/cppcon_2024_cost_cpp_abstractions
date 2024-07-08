#pragma once

#include <cstdint>

#include "hal/rcc/constants.hpp"
#include "hal/gpio/constants.hpp"
#include "hal/register.hpp"

namespace hal {

/* RCC_AHBENR */

class CAhbEnRegister : public CRegister<RCC_BASE_ADDR + RCC_AHBENR_OFFSET> {
public:
    template<gpio_ports port>
    requires (is_valid_gpio_port<port>)
    inline void enable_gpio_clock () {
        if constexpr (port == gpio_ports::port_a) { set_bits(0x00020000); }
        else if constexpr (port == gpio_ports::port_b) { set_bits(0x00040000); }
        else if constexpr (port == gpio_ports::port_c) { set_bits(0x00080000); }
        else if constexpr (port == gpio_ports::port_d) { set_bits(0x00080000); }
        else { set_bits(0x00400000); }
    }
};

} /* namespace hal */