#pragma once

#include <cstdint>

class CRegister {
private:
    const std::uint32_t m_address;
public:
    CRegister (std::uint32_t address) : m_address(address) { }

    void set (std::uint32_t val) const {
        *(reinterpret_cast<volatile std::uint32_t *>(this->m_address)) = val;
    }

    std::uint32_t get () const {
        return *(reinterpret_cast<volatile std::uint32_t *>(this->m_address));
    }

    void set (std::uint32_t value, std::uint32_t bitmask) const {
        std::uint32_t tmp = this->get();
        tmp &= ~bitmask;
        tmp |= value;
        this->set(tmp);
    }

    void set_bits (std::uint32_t bitmask) {
        *(reinterpret_cast<volatile std::uint32_t *>(this->m_address)) = *(reinterpret_cast<volatile std::uint32_t *>(this->m_address)) | bitmask;
    }

    void clear_bits (std::uint32_t bitmask) {
        *(reinterpret_cast<volatile std::uint32_t *>(this->m_address)) = *(reinterpret_cast<volatile std::uint32_t *>(this->m_address)) & ~bitmask;
    }

    bool is_set (std::uint32_t bitmask) {
        return (*(reinterpret_cast<volatile std::uint32_t *>(this->m_address)) & bitmask) == bitmask;
    }

    bool is_cleared (std::uint32_t bitmask) {
        return (*(reinterpret_cast<volatile std::uint32_t *>(this->m_address)) & bitmask) == 0;
    }

    std::uint32_t get_bits (std::uint32_t bitmask) {
        return *(reinterpret_cast<volatile std::uint32_t *>(this->m_address)) & bitmask;
    }
};