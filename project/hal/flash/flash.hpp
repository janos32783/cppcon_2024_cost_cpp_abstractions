#pragma once

#include <cstdint>

#include "hal/register.hpp"
#include "hal/CMSIS/Device/ST/STM32F0xx/Include/stm32f030xc.h"

namespace hal {
namespace flash {

class CFlash {
private:
    FLASH_TypeDef* m_flash { reinterpret_cast<FLASH_TypeDef*>(FLASH_R_BASE) };
public:
    void enable_prefetch () {
        CRegister::set_bits(&m_flash->ACR, FLASH_ACR_PRFTBE_Msk);
    }
};

} /* namespace flash */
} /* namespace hal */