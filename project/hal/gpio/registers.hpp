#pragma once

#include <cstdint>

#include "hal/gpio/constants.hpp"
#include "hal/register.hpp"

namespace hal {

/* GPIOx_MODER */

enum class gpio_modes : std::uint32_t {
    input    = 0b00,
    output   = 0b01,
    alt_func = 0b10,
    analog   = 0b11
};

template<gpio_ports port>
requires (is_valid_gpio_port<port>)
class CModeRegister : public CRegister<port_to_base_address<port>() + GPIO_MODER_OFFSET> {
private:
    template <gpio_pins pin, gpio_modes mode>
    static consteval std::uint32_t calculate_value () {
        return static_cast<std::uint32_t>(mode) << (static_cast<std::uint32_t>(pin) * 2);
    }

    template <gpio_pins pin, gpio_modes mode>
    static consteval std::uint32_t calculate_bitmask () {
        return static_cast<std::uint32_t>(0b11) << (static_cast<std::uint32_t>(pin) * 2);
    }
public:
    template <gpio_pins pin, gpio_modes mode>
    inline void set_mode () {
        this->set(calculate_value<pin, mode>(), calculate_bitmask<pin, mode>());
    }
};

/* GPIOx_BSRR */

template<gpio_ports port>
requires (is_valid_gpio_port<port>)
class CBSRRegister : public CRegister<port_to_base_address<port>() + GPIO_BSRR_OFFSET> {
public:
    template <gpio_pins pin>
    inline void set_pin () {
        this->set_bits(static_cast<std::uint32_t>(1) << static_cast<std::uint32_t>(pin));
    }

    template <gpio_pins pin>
    inline void reset_pin () {
        this->set_bits(static_cast<std::uint32_t>(0x10000) << static_cast<std::uint32_t>(pin));
    }
};

} /* namespace hal */