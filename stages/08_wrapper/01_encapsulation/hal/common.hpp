#pragma once

#include <cstdint>
#include <concepts>
#include <type_traits>

#include "stm32f0xx_hal.h"

namespace hal {

enum class error_codes {
    HAL_OK = 0x0,
    HAL_ERROR = 0x01,
    HAL_BUSY = 0x02,
    HAL_TIMEOUT = 0x03
};

} /* namespace hal */