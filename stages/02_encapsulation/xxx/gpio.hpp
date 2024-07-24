#pragma once

#include "registers.hpp"

template <ports port, pins pin>
requires (is_valid_port<port> && is_valid_pin<pin>)
class CPin {
private:
    GPIO_TypeDef* m_gpio { reinterpret_cast<GPIO_TypeDef*>(port_to_base_address<port>()) };
public:
    inline void set () const {
        CBitSetResetRegister<port>::template set<pin>();
    }

    inline void reset () const {
        CBitSetResetRegister<port>::template reset<pin>();
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
        CBitSetResetRegister<port>::template reset<pin...>();
    }

    template <pins... pin>
    requires (are_valid_pins<pin...>)
    static inline void set() {
        CBitSetResetRegister<port>::template set<pin...>();
    }

    template <GpioInitConfig conf, pins... pin>
    requires (is_valid_gpio_config<conf> && are_valid_pins<pin...>)
    static inline void configure_pins() {
        static_assert((sizeof...(pin) > 0), "No pins provided.");
        if constexpr ((conf.mode == modes::output) || (conf.mode == modes::alt_func)) {
            COutputSpeedRegister<port>::template configure<conf.speed, pin...>();
            COutputTypeRegister<port>::template configure<conf.output_type, pin...>();
        }
        if constexpr (conf.mode != modes::analog) {
            CPullUpPullDownRegister<port>::template configure<conf.pull_type, pin...>();
        }
        if constexpr (conf.mode == modes::alt_func) {
            CAlternateFunctionRegister<port>::template configure<conf.alternate_function, pin...>();
        }
        CModeRegister<port>::template configure<conf.mode, pin...>();
        // TODO : external interrupt
    }
};