#pragma once

#include <cstdint>

namespace hal {

class CRegister {
public:
    static inline void set (volatile std::uint32_t* reg, std::uint32_t value) {
        *reg = value;
    }

    static inline std::uint32_t get (volatile std::uint32_t* reg) {
        return *reg;
    }

    static inline void set (volatile std::uint32_t* reg, std::uint32_t value, std::uint32_t bitmask) {
        std::uint32_t tmp = *reg;
        tmp &= ~bitmask;
        tmp |= value;
        *reg = tmp;
    }

    static inline void set_bits (volatile std::uint32_t* reg, std::uint32_t bitmask) {
        *reg = *reg | bitmask;
    }

    static inline void clear_bits (volatile std::uint32_t* reg, std::uint32_t bitmask) {
        *reg = *reg & ~bitmask;
    }

    static inline bool is_set (volatile std::uint32_t* reg, std::uint32_t bitmask) {
        return static_cast<bool>(*reg & bitmask);
    }

    static inline std::uint32_t get_bits (volatile std::uint32_t* reg, std::uint32_t bitmask) {
        return *reg & bitmask;
    }
};

} /* namespace hal */