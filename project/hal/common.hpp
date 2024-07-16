#pragma once

#include <cstdint>
#include <concepts>
#include <type_traits>

#include "hal/CMSIS/Device/ST/STM32F0xx/Include/stm32f030xc.h"

namespace hal {

enum class hal_error {
    ok,
    error,
    busy,
    timeout
};

template <uint32_t prio>
concept is_preemptive_prio = (
    prio < 0x4
);

} /* namespace hal */