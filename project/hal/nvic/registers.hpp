#pragma once

#include <cstdint>

#include "hal/nvic/constants.hpp"
#include "hal/register.hpp"

namespace hal {
namespace nvic {

class CInterrupSetEnableRegister : public CRegister<NVIC_BASE_ADDR + STK_ISER_OFFSET> { };
class CInterrupClearEnableRegister : public CRegister<NVIC_BASE_ADDR + STK_ICER_OFFSET> { };
class CInterrupSetPendingRegister : public CRegister<NVIC_BASE_ADDR + STK_ISPR_OFFSET> { };
class CInterrupClearPendingRegister : public CRegister<NVIC_BASE_ADDR + STK_ICPR_OFFSET> { };
class CInterruptPriorityRegister0 : public CRegister<NVIC_BASE_ADDR + STK_IPR0_OFFSET> { };
class CInterruptPriorityRegister1 : public CRegister<NVIC_BASE_ADDR + STK_IPR1_OFFSET> { };
class CInterruptPriorityRegister2 : public CRegister<NVIC_BASE_ADDR + STK_IPR2_OFFSET> { };
class CInterruptPriorityRegister3 : public CRegister<NVIC_BASE_ADDR + STK_IPR3_OFFSET> { };
class CInterruptPriorityRegister4 : public CRegister<NVIC_BASE_ADDR + STK_IPR4_OFFSET> { };
class CInterruptPriorityRegister5 : public CRegister<NVIC_BASE_ADDR + STK_IPR5_OFFSET> { };
class CInterruptPriorityRegister6 : public CRegister<NVIC_BASE_ADDR + STK_IPR6_OFFSET> { };
class CInterruptPriorityRegister7 : public CRegister<NVIC_BASE_ADDR + STK_IPR7_OFFSET> { };

} /* namespace nvic */
} /* namespace hal */