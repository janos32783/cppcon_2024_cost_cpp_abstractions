#pragma once

#include "constants.hpp"
#include "register.hpp"

template <ports port, pins pin>
requires (is_valid_port<port> && is_valid_pin<pin>)
class CPin {
private:
    GPIO_TypeDef* m_gpio { reinterpret_cast<GPIO_TypeDef*>(port_to_base_address<port>()) };
public:
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
    requires (are_valid_pins<pin...>)
    static inline void reset() {
        CRegister::set(&reinterpret_cast<m_reg_t*>(m_address)->BSRR, bsrr_bitmask<set_reset::reset, pin...>());
    }

    template <pins... pin>
    requires (are_valid_pins<pin...>)
    static inline void set() {
        CRegister::set(&reinterpret_cast<m_reg_t*>(m_address)->BSRR, bsrr_bitmask<set_reset::set, pin...>());
    }

    template <GpioInitConfig conf, pins... pin>
    requires (is_valid_gpio_config<conf> && are_valid_pins<pin...>)
    static inline void configure_pins() {
        static_assert((sizeof...(pin) > 0), "No pins provided.");
        if constexpr ((conf.mode == modes::output) || (conf.mode == modes::alt_func)) {
            CRegister::set(&reinterpret_cast<m_reg_t*>(m_address)->OSPEEDR, ospeedr_value<conf.speed, pin...>(), ospeedr_bitmask<pin...>());
            CRegister::set(&reinterpret_cast<m_reg_t*>(m_address)->OTYPER, otyper_value<conf.output_type, pin...>(), otyper_bitmask<pin...>());
        }
        if constexpr (conf.mode != modes::analog) {
            CRegister::set(&reinterpret_cast<m_reg_t*>(m_address)->PUPDR, pupdr_value<conf.pull_type, pin...>(), pupdr_bitmask<pin...>());
        }
        if constexpr (conf.mode == modes::alt_func) {
            CRegister::set(&reinterpret_cast<m_reg_t*>(m_address)->AFR[0], afrl_value<conf.alternate_function, pin...>(), afrl_bitmask<pin...>());
            CRegister::set(&reinterpret_cast<m_reg_t*>(m_address)->AFR[1], afrh_value<conf.alternate_function, pin...>(), afrh_bitmask<pin...>());
        }
        CRegister::set(&reinterpret_cast<m_reg_t*>(m_address)->MODER, moder_value<conf.mode, pin...>(), moder_bitmask<pin...>());
        // TODO : external interrupt
    }
};