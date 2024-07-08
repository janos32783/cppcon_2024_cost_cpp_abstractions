#pragma once

#include <concepts>

namespace intf {

template <typename T>
concept GPIO = requires (T pin) {
    { pin.configure() } -> std::same_as<bool>;
    { pin.set() } -> std::same_as<void>;
    { pin.reset() } -> std::same_as<void>;
};

} /* namespace intf */