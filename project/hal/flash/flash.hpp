#pragma once

#include <cstdint>

#include "hal/register.hpp"
#include "hal/CMSIS/Device/ST/STM32F0xx/Include/stm32f030xc.h"

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