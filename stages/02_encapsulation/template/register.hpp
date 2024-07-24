#pragma once

#include <cstdint>

template <std::uint32_t address>
class CRegister {
public:
    void set (std::uint32_t val) const {
        *(reinterpret_cast<volatile std::uint32_t *>(address)) = val;
    }

    std::uint32_t get () const {
        return *(reinterpret_cast<volatile std::uint32_t *>(address));
    }

    void set (std::uint32_t value, std::uint32_t bitmask) const {
        std::uint32_t tmp = this->get();
        tmp &= ~bitmask;
        tmp |= value;
        this->set(tmp);
    }

    void set_bits (std::uint32_t bitmask) {
        *(reinterpret_cast<volatile std::uint32_t *>(address)) = *(reinterpret_cast<volatile std::uint32_t *>(address)) | bitmask;
    }

    void clear_bits (std::uint32_t bitmask) {
        *(reinterpret_cast<volatile std::uint32_t *>(address)) = *(reinterpret_cast<volatile std::uint32_t *>(address)) & ~bitmask;
    }

    bool is_set (std::uint32_t bitmask) {
        return (*(reinterpret_cast<volatile std::uint32_t *>(address)) & bitmask) == bitmask;
    }

    bool is_cleared (std::uint32_t bitmask) {
        return (*(reinterpret_cast<volatile std::uint32_t *>(address)) & bitmask) == 0;
    }

    std::uint32_t get_bits (std::uint32_t bitmask) {
        return *(reinterpret_cast<volatile std::uint32_t *>(address)) & bitmask;
    }
};