#include <cstdint>
#include <concepts>
#include <type_traits>

constexpr std::uint32_t ModeRegisterAddress = 0x48000000;

enum class gpio_modes : std::uint32_t {
    input  = 0b00,
    output = 0b01,
    analog = 0b10
};

enum class pin_numbers : std::uint32_t {
    pin_0 = 0,
    pin_1 = 1,
    pin_2 = 2,
    pin_3 = 3,
    pin_4 = 4,
    pin_5 = 5,
    pin_6 = 6,
    pin_7 = 7
};

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

class CModeRegister {
private:
    static inline const CRegister m_register { ModeRegisterAddress };

    static inline std::uint32_t calculate_value (pin_numbers pin, gpio_modes mode) {
        return static_cast<std::uint32_t>(mode) << static_cast<std::uint32_t>(pin) * 2;
    }

    static inline std::uint32_t calculate_bitmask (pin_numbers pin) {
        return static_cast<std::uint32_t>(0b11) << static_cast<std::uint32_t>(pin) * 2;
    }
public:
    static inline void set_mode (pin_numbers pin, gpio_modes mode) {
        m_register.set(calculate_value(pin, mode), calculate_bitmask(pin));
    }
};

int main (void) {
    CModeRegister::set_mode(pin_numbers::pin_6, gpio_modes::output);
    CModeRegister::set_mode(pin_numbers::pin_7, gpio_modes::input);
    CModeRegister::set_mode(pin_numbers::pin_2, gpio_modes::analog);

    while (true) { /* ... */ }
}
