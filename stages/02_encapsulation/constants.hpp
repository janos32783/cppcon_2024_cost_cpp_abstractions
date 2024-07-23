#pragma once

#include <cstdint>
#include <concepts>
#include <type_traits>
#include "hal/Drivers/CMSIS/Device/ST/STM32F0xx/Include/stm32f030xc.h"

enum class ports : std::uint8_t {
    port_f,
    port_d,
    port_c,
    port_b,
    port_a
};

template <ports port>
concept is_valid_port = (
    (port == ports::port_f) ||
    (port == ports::port_d) ||
    (port == ports::port_c) ||
    (port == ports::port_b) ||
    (port == ports::port_a)
);

template <ports port>
requires (is_valid_port<port>)
consteval std::uint32_t port_to_base_address () {
    if (port == ports::port_f) { return GPIOF_BASE; }
    else if (port == ports::port_d) { return GPIOD_BASE; }
    else if (port == ports::port_c) { return GPIOC_BASE; }
    else if (port == ports::port_b) { return GPIOB_BASE; }
    else { return GPIOA_BASE; }
}

enum class pins : std::uint8_t {
    pin_00 = 0,
    pin_01 = 1,
    pin_02 = 2,
    pin_03 = 3,
    pin_04 = 4,
    pin_05 = 5,
    pin_06 = 6,
    pin_07 = 7,
    pin_08 = 8,
    pin_09 = 9,
    pin_10 = 10,
    pin_11 = 11,
    pin_12 = 12,
    pin_13 = 13,
    pin_14 = 14,
    pin_15 = 15
};

template <pins pin>
concept is_valid_low_pin = (
    (pin == pins::pin_00) ||
    (pin == pins::pin_01) ||
    (pin == pins::pin_02) ||
    (pin == pins::pin_03) ||
    (pin == pins::pin_04) ||
    (pin == pins::pin_05) ||
    (pin == pins::pin_06) ||
    (pin == pins::pin_07)
);

template <pins... pin>
concept are_valid_low_pins = (is_valid_low_pin<pin> && ...);

template <pins pin>
concept is_valid_high_pin = (
    (pin == pins::pin_08) ||
    (pin == pins::pin_09) ||
    (pin == pins::pin_10) ||
    (pin == pins::pin_11) ||
    (pin == pins::pin_12) ||
    (pin == pins::pin_13) ||
    (pin == pins::pin_14) ||
    (pin == pins::pin_15)
);

template <pins... pin>
concept are_valid_high_pins = (is_valid_high_pin<pin> && ...);

template <pins pin>
concept is_valid_pin = (
    is_valid_low_pin<pin> || is_valid_high_pin<pin>
);

template <pins... pin>
concept are_valid_pins = (is_valid_pin<pin> && ...);

// GPIOx_MODER

enum class modes : std::uint32_t {
    input    = 0b00,
    output   = 0b01,
    alt_func = 0b10,
    analog   = 0b11
};

template <modes mode>
concept is_valid_mode = (
    (mode == modes::input) ||
    (mode == modes::output) ||
    (mode == modes::alt_func) ||
    (mode == modes::analog)
);

template <modes mode, pins... pin>
requires (are_valid_pins<pin ...> && is_valid_mode<mode>)
consteval std::uint32_t moder_value () {
    return (... | (static_cast<std::uint32_t>(mode) << (static_cast<std::uint32_t>(pin) * 2)));
}

template <pins... pin>
requires (are_valid_pins<pin ...>)
consteval std::uint32_t moder_bitmask () {
    return (... | (GPIO_MODER_MODER0 << (static_cast<std::uint32_t>(pin) * 2)));
}

// GPIOx_OTYPER

enum class output_types : std::uint32_t {
    push_pull  = 0,
    open_drain = 1
};

template <output_types type>
concept is_valid_output_type = (
    (type == output_types::push_pull) ||
    (type == output_types::open_drain)
);

template <output_types type, pins... pin>
requires (are_valid_pins<pin ...> && is_valid_output_type<type>)
consteval std::uint32_t otyper_value () {
    return (... | (static_cast<std::uint32_t>(type) << static_cast<std::uint32_t>(pin)));
}

template <pins... pin>
requires (are_valid_pins<pin ...>)
consteval std::uint32_t otyper_bitmask () {
    return (... | (GPIO_OTYPER_OT_0 << static_cast<std::uint32_t>(pin)));
}

// GPIOx_OSPEEDR

enum class speeds : std::uint32_t {
    low    = 0b00,
    medium = 0b01,
    high   = 0b11
};

template <speeds speed>
concept is_valid_speed = (
    (speed == speeds::low) ||
    (speed == speeds::medium) ||
    (speed == speeds::high)
);

template <speeds speed, pins... pin>
requires (are_valid_pins<pin ...> && is_valid_speed<speed>)
consteval std::uint32_t ospeedr_value () {
    return (... | (static_cast<std::uint32_t>(speed) << (static_cast<std::uint32_t>(pin) * 2)));
}

template <pins... pin>
requires (are_valid_pins<pin ...>)
consteval std::uint32_t ospeedr_bitmask () {
    return (... | (GPIO_OSPEEDR_OSPEEDR0 << (static_cast<std::uint32_t>(pin) * 2)));
}

// GPIOx_PUPDR

enum class pull_types : std::uint32_t {
    none      = 0b00,
    pull_up   = 0b01,
    pull_down = 0b10
};

template <pull_types pull_type>
concept is_valid_pull_type = (
    (pull_type == pull_types::none) ||
    (pull_type == pull_types::pull_up) ||
    (pull_type == pull_types::pull_down)
);

template <pull_types pull_type, pins... pin>
requires (are_valid_pins<pin ...> && is_valid_pull_type<pull_type>)
consteval std::uint32_t pupdr_value () {
    return (... | (static_cast<std::uint32_t>(pull_type) << (static_cast<std::uint32_t>(pin) * 2)));
}

template <pins... pin>
requires (are_valid_pins<pin ...>)
consteval std::uint32_t pupdr_bitmask () {
    return (... | (GPIO_PUPDR_PUPDR0 << (static_cast<std::uint32_t>(pin) * 2)));
}

// GPIOx_IDR

template <pins... pin>
requires (are_valid_pins<pin ...>)
consteval std::uint32_t idr_bitmask () {
    return (... | (GPIO_IDR_0 << static_cast<std::uint32_t>(pin)));
}

// GPIOx_ODR

template <pins... pin>
requires (are_valid_pins<pin ...>)
consteval std::uint32_t odr_bitmask () {
    return (... | (GPIO_ODR_0 << static_cast<std::uint32_t>(pin)));
}

// GPIOx_BSRR

enum class set_reset : std::uint32_t {
    reset = 0,
    set = 1
};

template <set_reset val>
concept is_valid_set_reset = (
    (val == set_reset::reset) ||
    (val == set_reset::set)
);

template <set_reset val, pins... pin>
requires (are_valid_pins<pin ...> && is_valid_set_reset<val>)
consteval std::uint32_t bsrr_bitmask () {
    if constexpr (val == set_reset::reset) {
        return (... | (GPIO_BSRR_BR_0 << static_cast<std::uint32_t>(pin)));
    }
    else {
        return (... | (GPIO_BSRR_BS_0 << static_cast<std::uint32_t>(pin)));
    }
}

// GPIOx_AFRL
// GPIOx_AFRH

enum class alternate_functions : std::uint32_t {
    af0 = 0b0000,
    af1 = 0b0001,
    af2 = 0b0010,
    af3 = 0b0011,
    af4 = 0b0100,
    af5 = 0b0101,
    af6 = 0b0110,
    af7 = 0b0111
};

template <alternate_functions alternate_function>
concept is_valid_alternate_function = (
    (alternate_function == alternate_functions::af0) ||
    (alternate_function == alternate_functions::af1) ||
    (alternate_function == alternate_functions::af2) ||
    (alternate_function == alternate_functions::af3) ||
    (alternate_function == alternate_functions::af4) ||
    (alternate_function == alternate_functions::af5) ||
    (alternate_function == alternate_functions::af6) ||
    (alternate_function == alternate_functions::af7)
);

template <alternate_functions alternate_function, pins... pin>
requires (are_valid_pins<pin ...> && is_valid_alternate_function<alternate_function>)
consteval std::uint32_t afrl_value () {
    return (... | (is_valid_low_pin<pin> ? (static_cast<std::uint32_t>(alternate_function) << (static_cast<std::uint32_t>(pin) * 4)) : 0));
}

template <pins... pin>
requires (are_valid_pins<pin ...>)
consteval std::uint32_t afrl_bitmask () {
    return (... | (is_valid_low_pin<pin> ? (GPIO_AFRL_AFSEL0 << (static_cast<std::uint32_t>(pin) * 4)) : 0));
}

template <alternate_functions alternate_function, pins... pin>
requires (are_valid_pins<pin ...> && is_valid_alternate_function<alternate_function>)
consteval std::uint32_t afrh_value () {
    return (... | (is_valid_high_pin<pin> ? (static_cast<std::uint32_t>(alternate_function) << ((static_cast<std::uint32_t>(pin) - 8) * 4)) : 0));
}

template <pins... pin>
requires (are_valid_pins<pin ...>)
consteval std::uint32_t afrh_bitmask () {
    return (... | (is_valid_high_pin<pin> ? (GPIO_AFRH_AFSEL8 << ((static_cast<std::uint32_t>(pin) - 8) * 4)) : 0));
}

struct GpioInitConfig {
    modes mode { modes::input };
    output_types output_type { output_types::push_pull };
    speeds speed { speeds::low };
    pull_types pull_type { pull_types::none };
    alternate_functions alternate_function { alternate_functions::af0 };
};

template <GpioInitConfig conf>
concept is_valid_gpio_config = (
    (is_valid_mode<conf.mode>) &&
    (is_valid_output_type<conf.output_type>) &&
    (is_valid_speed<conf.speed>) &&
    (is_valid_pull_type<conf.pull_type>) &&
    (is_valid_alternate_function<conf.alternate_function>)
);