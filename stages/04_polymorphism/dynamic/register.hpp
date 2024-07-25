#pragma once

#include <cstdint>

template <std::uint32_t address>
class CRegister {
public:
    static inline void set (std::uint32_t val) {
        *(reinterpret_cast<volatile std::uint32_t *>(address)) = val;
    }

    static inline std::uint32_t get () {
        return *(reinterpret_cast<volatile std::uint32_t *>(address));
    }

    static inline void set (std::uint32_t value, std::uint32_t bitmask) {
        std::uint32_t tmp = get();
        tmp &= ~bitmask;
        tmp |= value;
        set(tmp);
    }

    static inline void set_bits (std::uint32_t bitmask) {
        *(reinterpret_cast<volatile std::uint32_t *>(address)) = *(reinterpret_cast<volatile std::uint32_t *>(address)) | bitmask;
    }

    static inline void clear_bits (std::uint32_t bitmask) {
        *(reinterpret_cast<volatile std::uint32_t *>(address)) = *(reinterpret_cast<volatile std::uint32_t *>(address)) & ~bitmask;
    }

    static inline bool is_set (std::uint32_t bitmask) {
        return (*(reinterpret_cast<volatile std::uint32_t *>(address)) & bitmask) == bitmask;
    }

    static inline bool is_cleared (std::uint32_t bitmask) {
        return (*(reinterpret_cast<volatile std::uint32_t *>(address)) & bitmask) == 0;
    }

    static inline std::uint32_t get_bits (std::uint32_t bitmask) {
        return *(reinterpret_cast<volatile std::uint32_t *>(address)) & bitmask;
    }
};