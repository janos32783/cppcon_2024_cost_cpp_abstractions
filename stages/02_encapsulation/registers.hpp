#pragma once

#include "constants.hpp"
#include "register.hpp"

template <ports port>
requires (is_valid_port<port>)
class CModeRegister {
private:
    static constexpr std::uint32_t m_address = port_to_base_address<port>();
    using m_reg_t = GPIO_TypeDef;
public:
    template <modes mode, pins... pin>
    requires (is_valid_mode<mode> && are_valid_pins<pin...>)
    static inline void configure () {
        CRegister::set(&reinterpret_cast<m_reg_t*>(m_address)->MODER, moder_value<mode, pin...>(), moder_bitmask<pin...>());
    }
};

template <ports port>
requires (is_valid_port<port>)
class COutputTypeRegister {
private:
    static constexpr std::uint32_t m_address = port_to_base_address<port>();
    using m_reg_t = GPIO_TypeDef;
public:
    template <output_types type, pins... pin>
    requires (is_valid_output_type<type> && are_valid_pins<pin...>)
    static inline void configure () {
        CRegister::set(&reinterpret_cast<m_reg_t*>(m_address)->OTYPER, otyper_value<type, pin...>(), otyper_bitmask<pin...>());
    }
};

template <ports port>
requires (is_valid_port<port>)
class COutputSpeedRegister {
private:
    static constexpr std::uint32_t m_address = port_to_base_address<port>();
    using m_reg_t = GPIO_TypeDef;
public:
    template <speeds speed, pins... pin>
    requires (is_valid_speed<speed> && are_valid_pins<pin...>)
    static inline void configure () {
        CRegister::set(&reinterpret_cast<m_reg_t*>(m_address)->OSPEEDR, ospeedr_value<speed, pin...>(), ospeedr_bitmask<pin...>());
    }
};

template <ports port>
requires (is_valid_port<port>)
class CPullUpPullDownRegister {
private:
    static constexpr std::uint32_t m_address = port_to_base_address<port>();
    using m_reg_t = GPIO_TypeDef;
public:
    template <pull_types pull_type, pins... pin>
    requires (is_valid_pull_type<pull_type> && are_valid_pins<pin...>)
    static inline void configure () {
        CRegister::set(&reinterpret_cast<m_reg_t*>(m_address)->PUPDR, pupdr_value<pull_type, pin...>(), pupdr_bitmask<pin...>());
    }
};

template <ports port>
requires (is_valid_port<port>)
class CBitSetResetRegister {
private:
    static constexpr std::uint32_t m_address = port_to_base_address<port>();
    using m_reg_t = GPIO_TypeDef;
public:
    template <pins... pin>
    requires (are_valid_pins<pin...>)
    static inline void set () {
        CRegister::set(&reinterpret_cast<m_reg_t*>(m_address)->BSRR, bsrr_bitmask<set_reset::set, pin...>());
    }

    template <pins... pin>
    requires (are_valid_pins<pin...>)
    static inline void reset () {
        CRegister::set(&reinterpret_cast<m_reg_t*>(m_address)->BSRR, bsrr_bitmask<set_reset::reset, pin...>());
    }
};

template <ports port>
requires (is_valid_port<port>)
class CAlternateFunctionRegister {
private:
    static constexpr std::uint32_t m_address = port_to_base_address<port>();
    using m_reg_t = GPIO_TypeDef;
public:
    template <alternate_functions func, pins... pin>
    requires (is_valid_alternate_function<func> && are_valid_pins<pin...>)
    static inline void configure () {
        CRegister::set(&reinterpret_cast<m_reg_t*>(m_address)->AFR[0], afrl_value<func, pin...>(), afrl_bitmask<pin...>());
        CRegister::set(&reinterpret_cast<m_reg_t*>(m_address)->AFR[1], afrh_value<func, pin...>(), afrh_bitmask<pin...>());
    }
};