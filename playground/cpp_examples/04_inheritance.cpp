#include <cstdint>
#include <concepts>
#include <type_traits>

enum class gpio_modes : std::uint32_t {
    input  = 0b00,
    output = 0b01,
    analog = 0b10
};

enum class gpio_otype : std::uint32_t {
    push_pull  = 0,
    open_drain = 1
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

template<std::uint32_t address>
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
};

class CModeRegister : public CRegister<0x48000000> {
private:

    template <pin_numbers pin, gpio_modes mode>
    static consteval std::uint32_t calculate_value () {
        return static_cast<std::uint32_t>(mode) << static_cast<std::uint32_t>(pin) * 2;
    }

    template <pin_numbers pin, gpio_modes mode>
    static consteval std::uint32_t calculate_bitmask () {
        return static_cast<std::uint32_t>(0b11) << static_cast<std::uint32_t>(pin) * 2;
    }
public:
    template <pin_numbers pin, gpio_modes mode>
    inline void set_mode () {
        set(calculate_value<pin, mode>(), calculate_bitmask<pin, mode>());
    }
};

/*
class CTypeRegister : public CRegister<0x48000004> {
private:

    template <pin_numbers pin, gpio_otype type>
    static consteval std::uint32_t calculate_value () {
        return static_cast<std::uint32_t>(type) << static_cast<std::uint32_t>(pin);
    }

    template <pin_numbers pin, gpio_otype type>
    static consteval std::uint32_t calculate_bitmask () {
        return static_cast<std::uint32_t>(1) << static_cast<std::uint32_t>(pin);
    }
public:
    template <pin_numbers pin, gpio_otype type>
    inline void set_type () {
        set(calculate_value<pin, type>(), calculate_bitmask<pin, type>());
    }
};
*/

int main (void) {
    CModeRegister mode_register {};
    mode_register.set_mode<pin_numbers::pin_6, gpio_modes::output>();
    //CTypeRegister type_register {};
    //type_register.set_type<pin_numbers::pin_6, gpio_otype::push_pull>();

    while (true) { /* ... */ }
}
