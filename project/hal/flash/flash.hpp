#pragma once

#include "hal/register.hpp"
#include "hal/common.hpp"
#include "hal/flash/constants.hpp"

namespace hal {
namespace flash {

class CFlash {
private:
    static constexpr std::uint32_t m_address = FLASH_R_BASE;
    using m_reg_t = FLASH_TypeDef;
public:
    static inline void enable_prefetch () {
        CRegister::set_bits(&reinterpret_cast<m_reg_t*>(m_address)->ACR, FLASH_ACR_PRFTBE);
    }
    static inline std::uint32_t get_latency () {
        return CRegister::get_bits(&reinterpret_cast<m_reg_t*>(m_address)->ACR, FLASH_ACR_LATENCY);
    }
    template <std::uint32_t latency>
    requires (is_valid_flash_latency<latency>)
    static inline void set_latency () {
        CRegister::set(&reinterpret_cast<m_reg_t*>(m_address)->ACR, latency, FLASH_ACR_LATENCY);
    }
};

} /* namespace flash */
} /* namespace hal */