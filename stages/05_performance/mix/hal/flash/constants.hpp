#pragma once

#include "hal/common.hpp"

namespace hal {
namespace flash {

template <std::uint32_t lat>
concept is_valid_flash_latency = (
    (lat == 0x00000000U) ||
    (lat == FLASH_ACR_LATENCY)
);

} /* namespace flash */
} /* namespace hal */