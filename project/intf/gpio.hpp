#pragma once

#include <concepts>

namespace intf {
namespace gpio {

template <typename T>
concept IPin = requires (T pin, bool level) {
    //{ pin.configure() } -> std::same_as<bool>;
    { pin.set() } -> std::same_as<void>;
    { pin.reset() } -> std::same_as<void>;
    { pin.write(level) } -> std::same_as<void>;
};

template <typename T>
concept IPort = requires (T pin, bool level) {
    { pin.configure() } -> std::same_as<bool>;
};

} /* namespace gpio */
} /* namespace intf */