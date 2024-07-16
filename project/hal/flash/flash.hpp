#pragma once

#include "hal/register.hpp"
#include "hal/common.hpp"

namespace hal {
namespace flash {

class CFlash {
private:
    static constexpr std::uint32_t m_address = FLASH_R_BASE;
    using m_reg_t = FLASH_TypeDef;
public:
    static inline void enable_prefetch () {
        CRegister::set_bits(&reinterpret_cast<m_reg_t*>(m_address)->ACR, FLASH_ACR_PRFTBE_Msk);
    }
};

} /* namespace flash */
} /* namespace hal */