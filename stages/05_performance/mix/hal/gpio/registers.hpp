#pragma once

#include "hal/gpio/constants.hpp"
#include "hal/register.hpp"

namespace hal {
namespace gpio {

template <ports port>
requires (is_valid_port<port>)
class COutputModeRegister : public CRegister {
private:
    static constexpr std::uint32_t m_address = port_to_base_address<port>();
    using m_reg_t = GPIO_TypeDef;
public:
    template <modes mode, pins... pin>
    requires (is_valid_mode<mode> && are_valid_pins<pin...>)
    static inline void set_mode () {
        set(&reinterpret_cast<m_reg_t*>(m_address)->MODER, moder_value<mode, pin...>(), moder_bitmask<pin...>());
    }
};

} /* namespace gpio */
} /* namespace hal */