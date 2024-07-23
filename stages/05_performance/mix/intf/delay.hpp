#pragma once

#include <concepts>
#include <cstdint>

namespace intf {

template <typename T>
concept Delay = requires (T delay, std::uint32_t interval) {
    { delay.delay_ms(interval) } -> std::same_as<void>;
    { delay.delay_us(interval) } -> std::same_as<void>;
};

} /* namespace intf */