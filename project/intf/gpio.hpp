#pragma once

#include <concepts>

namespace intf {

template <typename T>
concept GPIO = requires (T pin, bool level) {
    { pin.configure() } -> std::same_as<bool>;
    { pin.set() } -> std::same_as<void>;
    { pin.reset() } -> std::same_as<void>;
    { pin.write(level) } -> std::same_as<void>;
};

} /* namespace intf */