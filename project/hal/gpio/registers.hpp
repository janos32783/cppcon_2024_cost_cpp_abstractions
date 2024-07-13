#pragma once

#include <cstdint>

#include "hal/gpio/constants.hpp"
#include "hal/register.hpp"

namespace hal {

// GPIOx_MODER

enum class gpio_modes : std::uint32_t {
    input    = 0b00,
    output   = 0b01,
    alt_func = 0b10,
    analog   = 0b11
};

template <gpio_modes mode>
concept is_valid_gpio_mode = (
    (mode == gpio_modes::input) ||
    (mode == gpio_modes::output) ||
    (mode == gpio_modes::alt_func) ||
    (mode == gpio_modes::analog)
);

template<gpio_ports port>
requires (is_valid_gpio_port<port>)
class CModeRegister : public CRegister<port_to_base_address<port>() + GPIO_MODER_OFFSET> {
private:
    template <gpio_pins pin, gpio_modes mode>
    static consteval std::uint32_t calculate_value () {
        return static_cast<std::uint32_t>(mode) << (static_cast<std::uint32_t>(pin) * 2);
    }

    template <gpio_pins pin>
    static consteval std::uint32_t calculate_bitmask () {
        return GPIO_MODER_MODER0_MSK << (static_cast<std::uint32_t>(pin) * 2);
    }
public:
    template <gpio_pins pin, gpio_modes mode>
    requires (is_valid_gpio_pin<pin> && is_valid_gpio_mode<mode>)
    inline void set_mode () {
        this->set(calculate_value<pin, mode>(), calculate_bitmask<pin>());
    }
};

// GPIOx_OTYPER

enum class gpio_types : std::uint32_t {
    push_pull  = 0,
    open_drain = 1
};

template <gpio_types type>
concept is_valid_gpio_type = (
    (type == gpio_types::push_pull) ||
    (type == gpio_types::open_drain)
);

template<gpio_ports port>
requires (is_valid_gpio_port<port>)
class COutputTypeRegister : public CRegister<port_to_base_address<port>() + GPIO_OTYPER_OFFSET> {
private:
    template <gpio_pins pin, gpio_types type>
    static consteval std::uint32_t calculate_value () {
        return static_cast<std::uint32_t>(type) << static_cast<std::uint32_t>(pin);
    }

    template <gpio_pins pin>
    static consteval std::uint32_t calculate_bitmask () {
        return GPIO_OTYPER_OT0_MSK << static_cast<std::uint32_t>(pin);
    }
public:
    template <gpio_pins pin, gpio_types type>
    requires (is_valid_gpio_pin<pin> && is_valid_gpio_type<type>)
    inline void set_type () {
        this->set(calculate_value<pin, type>(), calculate_bitmask<pin>());
    }
};

// GPIOx_OSPEEDR

enum class gpio_speeds : std::uint32_t {
    low = 0b00,
    medium = 0b01,
    high = 0b11
};

template <gpio_speeds speed>
concept is_valid_gpio_speed = (
    (speed == gpio_speeds::low) ||
    (speed == gpio_speeds::medium) ||
    (speed == gpio_speeds::high)
);

template<gpio_ports port>
requires (is_valid_gpio_port<port>)
class COutputSpeedRegister : public CRegister<port_to_base_address<port>() + GPIO_OSPEEDR_OFFSET> {
private:
    template <gpio_pins pin, gpio_speeds speed>
    static consteval std::uint32_t calculate_value () {
        return static_cast<std::uint32_t>(speed) << (static_cast<std::uint32_t>(pin) * 2);
    }

    template <gpio_pins pin>
    static consteval std::uint32_t calculate_bitmask () {
        return GPIO_OSPEEDR_OSPEEDR0_MSK << (static_cast<std::uint32_t>(pin) * 2);
    }
public:
    template <gpio_pins pin, gpio_speeds speed>
    requires (is_valid_gpio_pin<pin> && is_valid_gpio_speed<speed>)
    inline void set_speed () {
        this->set(calculate_value<pin, speed>(), calculate_bitmask<pin>());
    }
};

// GPIOx_PUPDR

enum class gpio_pull_types : std::uint32_t {
    none = 0b00,
    pull_up = 0b01,
    pull_down = 0b10
};

template <gpio_pull_types pull_type>
concept is_valid_gpio_pull_type = (
    (pull_type == gpio_pull_types::none) ||
    (pull_type == gpio_pull_types::pull_up) ||
    (pull_type == gpio_pull_types::pull_down)
);

template<gpio_ports port>
requires (is_valid_gpio_port<port>)
class CPullUpPullDownRegister : public CRegister<port_to_base_address<port>() + GPIO_PUPDR_OFFSET> {
private:
    template <gpio_pins pin, gpio_pull_types pull_type>
    static consteval std::uint32_t calculate_value () {
        return static_cast<std::uint32_t>(pull_type) << (static_cast<std::uint32_t>(pin) * 2);
    }

    template <gpio_pins pin>
    static consteval std::uint32_t calculate_bitmask () {
        return GPIO_PUPDR_PUPDR0_MSK << (static_cast<std::uint32_t>(pin) * 2);
    }
public:
    template <gpio_pins pin, gpio_pull_types pull_type>
    requires (is_valid_gpio_pin<pin> && is_valid_gpio_pull_type<pull_type>)
    inline void set_pull_type () {
        this->set(calculate_value<pin, pull_type>(), calculate_bitmask<pin>());
    }
};

// GPIOx_IDR

template<gpio_ports port>
requires (is_valid_gpio_port<port>)
class CInputDataRegister : public CRegister<port_to_base_address<port>() + GPIO_IDR_OFFSET> {
private:
    template <gpio_pins pin>
    static consteval std::uint32_t calculate_bitmask () {
        return GPIO_IDR_IDR0_MSK << static_cast<std::uint32_t>(pin);
    }
public:
    template <gpio_pins pin>
    requires (is_valid_gpio_pin<pin>)
    inline bool read () {
        return this->is_set(calculate_bitmask<pin>());
    }
};

// GPIOx_ODR

template<gpio_ports port>
requires (is_valid_gpio_port<port>)
class COutputDataRegister : public CRegister<port_to_base_address<port>() + GPIO_ODR_OFFSET> {
private:
    template <gpio_pins pin>
    static consteval std::uint32_t calculate_value () {
        return GPIO_ODR_ODR0_MSK << static_cast<std::uint32_t>(pin);
    }

    template <gpio_pins pin>
    static consteval std::uint32_t calculate_bitmask () {
        return GPIO_ODR_ODR0_MSK << static_cast<std::uint32_t>(pin);
    }
public:
    template <gpio_pins pin>
    requires (is_valid_gpio_pin<pin>)
    inline void set_pin () {
        this->set(calculate_value<pin>(), calculate_bitmask<pin>());
    }

    template <gpio_pins pin>
    requires (is_valid_gpio_pin<pin>)
    inline void reset_pin () {
        this->set(calculate_value<pin>(), calculate_bitmask<pin>());
    }
};

// GPIOx_BSRR

template<gpio_ports port>
requires (is_valid_gpio_port<port>)
class CBitSetResetRegister : public CRegister<port_to_base_address<port>() + GPIO_BSRR_OFFSET> {
public:
    template <gpio_pins pin>
    requires (is_valid_gpio_pin<pin>)
    inline void set_pin () {
        this->set_bits(GPIO_BSRR_BS0_MSK << static_cast<std::uint32_t>(pin));
    }

    template <gpio_pins pin>
    requires (is_valid_gpio_pin<pin>)
    inline void reset_pin () {
        this->set_bits(GPIO_BSRR_BR0_MSK << static_cast<std::uint32_t>(pin));
    }
};

// GPIOx_LCKR
// TODO

// GPIOx_AFRL
// GPIOx_AFRH

enum class gpio_alternate_functions : std::uint32_t {
    af0 = 0b0000,
    af1 = 0b0001,
    af2 = 0b0010,
    af3 = 0b0011,
    af4 = 0b0100,
    af5 = 0b0101,
    af6 = 0b0110,
    af7 = 0b0111
};

template <gpio_alternate_functions alternate_function>
concept is_valid_gpio_alternate_function = (
    (alternate_function == gpio_alternate_functions::af0) ||
    (alternate_function == gpio_alternate_functions::af1) ||
    (alternate_function == gpio_alternate_functions::af2) ||
    (alternate_function == gpio_alternate_functions::af3) ||
    (alternate_function == gpio_alternate_functions::af4) ||
    (alternate_function == gpio_alternate_functions::af5) ||
    (alternate_function == gpio_alternate_functions::af6) ||
    (alternate_function == gpio_alternate_functions::af1)
);

template <gpio_pins pin>
concept is_valid_gpio_low_pin = (
    (pin == gpio_pins::pin_00) ||
    (pin == gpio_pins::pin_01) ||
    (pin == gpio_pins::pin_02) ||
    (pin == gpio_pins::pin_03) ||
    (pin == gpio_pins::pin_04) ||
    (pin == gpio_pins::pin_05) ||
    (pin == gpio_pins::pin_06) ||
    (pin == gpio_pins::pin_07)
);

template <gpio_pins pin>
concept is_valid_gpio_high_pin = (
    (pin == gpio_pins::pin_08) ||
    (pin == gpio_pins::pin_09) ||
    (pin == gpio_pins::pin_10) ||
    (pin == gpio_pins::pin_11) ||
    (pin == gpio_pins::pin_12) ||
    (pin == gpio_pins::pin_13) ||
    (pin == gpio_pins::pin_14) ||
    (pin == gpio_pins::pin_15)
);

template<gpio_ports port>
requires (is_valid_gpio_port<port>)
class CAlternateFunctionLowRegister : public CRegister<port_to_base_address<port>() + GPIO_AFRL_OFFSET> {
private:
    template <gpio_pins pin, gpio_alternate_functions alternate_function>
    static consteval std::uint32_t calculate_value () {
        return static_cast<std::uint32_t>(alternate_function) << (static_cast<std::uint32_t>(pin) * 4);
    }

    template <gpio_pins pin>
    static consteval std::uint32_t calculate_bitmask () {
        return GPIO_AFRL_AFRL0_MSK << (static_cast<std::uint32_t>(pin) * 4);
    }
public:
    template <gpio_pins pin, gpio_alternate_functions alternate_function>
    requires (is_valid_gpio_low_pin<pin> && is_valid_gpio_alternate_function<alternate_function>)
    inline void set_alternate_function () {
        this->set(calculate_value<pin, alternate_function>(), calculate_bitmask<pin>());
    }
};

template<gpio_ports port>
requires (is_valid_gpio_port<port>)
class CAlternateFunctionHighRegister : public CRegister<port_to_base_address<port>() + GPIO_AFRH_OFFSET> {
private:
    template <gpio_pins pin, gpio_alternate_functions alternate_function>
    static consteval std::uint32_t calculate_value () {
        return static_cast<std::uint32_t>(alternate_function) << (static_cast<std::uint32_t>(pin) * 4);
    }

    template <gpio_pins pin>
    static consteval std::uint32_t calculate_bitmask () {
        return GPIO_AFRH_AFRH8_MSK << (static_cast<std::uint32_t>(pin) * 4);
    }
public:
    template <gpio_pins pin, gpio_alternate_functions alternate_function>
    requires (is_valid_gpio_high_pin<pin> && is_valid_gpio_alternate_function<alternate_function>)
    inline void set_alternate_function () {
        this->set(calculate_value<pin, alternate_function>(), calculate_bitmask<pin>());
    }
};

// GPIOx_BRR

template<gpio_ports port>
requires (is_valid_gpio_port<port>)
class CBitResetRegister : public CRegister<port_to_base_address<port>() + GPIO_BRR_OFFSET> {
public:
    template <gpio_pins pin>
    requires (is_valid_gpio_pin<pin>)
    inline void reset_pin () {
        this->set_bits(GPIO_BRR_BR0_MSK << static_cast<std::uint32_t>(pin));
    }
};

} /* namespace hal */