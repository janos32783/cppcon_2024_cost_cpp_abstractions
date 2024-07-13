#include <cstdint>

#define MODER   (*((volatile uint32_t*)0x48000000))
#define OTYPER  (*((volatile uint32_t*)0x48000004))
#define OSPEEDR (*((volatile uint32_t*)0x48000008))
/* ... */
#define GPIO_PIN_6  ((uint16_t)0x0004U)
/* ... */
#define MODER_MASK   (0x3UL)
#define OTYPER_MASK  (0x1UL)
#define OSPEEDR_MASK (0x3UL)
/* ... */
enum class GPIO_Mode {
    input,
    output
};
/* ... */
#define  GPIO_SPEED_FREQ_LOW (0x00000000U)
#define  GPIO_OUTPUT_TYPE    (0x00000000U)
#define  GPIO_OUTPUT_MODE    (0x00000000U)
/* ... */

template <std::uint8_t pin>
concept is_valid_pin = (pin <= 15);

consteval std::uint32_t ospeedr_pin_mask(std::uint8_t pin) {
    return OSPEEDR_MASK << (static_cast<std::uint32_t>(pin) * 2u);
}

consteval std::uint32_t ospeedr_pin_mask_low_freq(std::uint8_t pin) {
    return GPIO_SPEED_FREQ_LOW << (static_cast<std::uint32_t>(pin) * 2u);
}

consteval std::uint32_t otyper_pin_mask(std::uint8_t pin) {
    return OTYPER_MASK << static_cast<std::uint32_t>(pin);
}

consteval std::uint32_t otyper_pin_mask_out(std::uint8_t pin) {
    return GPIO_OUTPUT_TYPE << static_cast<std::uint32_t>(pin);
}

consteval std::uint32_t moder_pin_mask(std::uint8_t pin) {
    return MODER_MASK << (static_cast<std::uint32_t>(pin) * 2u);
}

consteval std::uint32_t moder_pin_mask_out(std::uint8_t pin) {
    return GPIO_OUTPUT_MODE << (static_cast<std::uint32_t>(pin) * 2u);
}

template <std::uint8_t pin, GPIO_Mode mode>
requires (is_valid_pin<pin>)
void GPIO_Init() {
    uint32_t temp;

    /* configure the GPIO based on the settings */
    if constexpr (mode == GPIO_Mode::output) {
        temp = OSPEEDR;
        temp &= ~ospeedr_pin_mask(pin);
        temp |= ospeedr_pin_mask_low_freq(pin);
        OSPEEDR = temp;

        temp = OTYPER;
        temp &= ~otyper_pin_mask(pin);
        temp |= otyper_pin_mask(pin);
        OTYPER = temp;
    }

    temp = MODER;
    temp &= ~moder_pin_mask(pin);
    temp |= moder_pin_mask_out(pin);
    MODER = temp;

    /* ... */
}

class IPin {
public:
    virtual std::uint8_t get_pin_number () const = 0;
};

class CPin : public IPin {
private:
    std::uint8_t m_pin;
public:
    CPin (std::uint8_t pin) : m_pin(pin) {}
    std::uint8_t get_pin_number () const override { return m_pin; }
};

std::uint8_t HandlePin (IPin* pin) {
    std::uint8_t pin_number = pin->get_pin_number();
    ++pin_number;
    return pin_number;
}

int main (void) {
    GPIO_Init<GPIO_PIN_6, GPIO_Mode::output>();

    CPin pin { GPIO_PIN_6 };
    std::uint8_t pin_number = HandlePin(&pin);

    while (true) { /* ... */}
}