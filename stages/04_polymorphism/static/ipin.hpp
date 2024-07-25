#pragma once

#include <concepts>
#include <type_traits>

template <typename T>
concept IPin = requires (T pin) {
    { pin.set() } -> std::same_as<void>;
    { pin.reset() } -> std::same_as<void>;
};