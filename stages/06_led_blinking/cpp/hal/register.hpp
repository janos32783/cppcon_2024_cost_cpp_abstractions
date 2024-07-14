#pragma once

#include <cstdint>

namespace hal {

template <std::uint32_t address>
class CRegister {
public:
    inline void set (std::uint32_t value) const {
        *(reinterpret_cast<volatile std::uint32_t *>(address)) = value;
    }

    inline std::uint32_t get () const {
        return *(reinterpret_cast<volatile std::uint32_t *>(address));
    }

    inline void set (std::uint32_t value, std::uint32_t bitmask) const {
        std::uint32_t tmp = get();
        tmp &= ~bitmask;
        tmp |= value;
        set(tmp);
    }

    inline void set_bits (std::uint32_t bitmask) const {
        *(reinterpret_cast<volatile std::uint32_t *>(address)) = *(reinterpret_cast<volatile std::uint32_t *>(address)) | bitmask;
    }

    inline void clear_bits (std::uint32_t bitmask) const {
        *(reinterpret_cast<volatile std::uint32_t *>(address)) = *(reinterpret_cast<volatile std::uint32_t *>(address)) & ~bitmask;
    }

    inline bool is_set (std::uint32_t bitmask) const {
        return static_cast<bool>(*(reinterpret_cast<volatile std::uint32_t *>(address)) & bitmask);
    }

    inline std::uint32_t get_bits (std::uint32_t bitmask) const {
        return *(reinterpret_cast<volatile std::uint32_t *>(address)) & bitmask;
    }
};

} /* namespace hal */