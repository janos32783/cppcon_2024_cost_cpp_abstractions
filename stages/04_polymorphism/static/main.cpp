#include <cstdint>
#include <concepts>
#include <type_traits>

#include "register.hpp"
#include "ipin.hpp"
#include "led.hpp"

#define MODER (*((volatile uint32_t*)0x48000000))
#define OTYPER (*((volatile uint32_t*)0x48000004))
#define OSPEEDR (*((volatile uint32_t*)0x48000008))
/* ... */
#define GPIO_PIN_6 ((uint16_t)0x0006U)
#define GPIO_PIN_7 ((uint16_t)0x0007U)
/* ... */
#define MODER_MASK   (0x3UL)
#define OTYPER_MASK  (0x1UL)
#define OSPEEDR_MASK (0x3UL)
#define BSSR_MASK (0x1UL)
/* ... */
#define GPIO_SPEED_FREQ_LOW (0x00000000U)
#define GPIO_SPEED_FREQ_FAST (0x00000001U)
/* ... */
#define GPIO_MODE        (0x00000003U)
#define GPIO_OUTPUT_TYPE (0x00000010U)
/* ... */
#define IS_GPIO_PIN(X) ((X) < 16 && (X) >= 0)

typedef enum {
    GPIO_MODE_INPUT = 0x00000000U,
    GPIO_MODE_OUTPUT = 0x00000001U
} GPIO_Modes;

typedef enum {
    GPIO_TYPE_PP = 0x00000000U,
    GPIO_TYPE_OD = 0x00000001U
} GPIO_Output_Types;

typedef enum {
    GPIO_SPEED_SLOW = GPIO_SPEED_FREQ_LOW,
    GPIO_SPEED_FAST = GPIO_SPEED_FREQ_FAST
} GPIO_Output_Speeds;

#define IS_GPIO_MODE(X) (((X) == GPIO_MODE_INPUT) || ((X) == GPIO_MODE_OUTPUT))

class CModeRegister : public CRegister<0x48000000> {
private:
    static inline std::uint32_t calculate_value (std::uint32_t pin, GPIO_Modes mode) {
        return (mode & GPIO_MODE) << (pin * 2);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t pin) {
        return MODER_MASK << (pin * 2);
    }
public:
    static inline void set_mode (std::uint32_t pin, GPIO_Modes mode) {
        set(calculate_value(pin, mode), calculate_bitmask(pin));
    }
};

class COutputTypeRegister : public CRegister<0x48000004> {
private:
    static inline std::uint32_t calculate_value (std::uint32_t pin, GPIO_Output_Types type) {
        return ((type & GPIO_OUTPUT_TYPE) >> 4u) << pin;
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t pin) {
        return OTYPER_MASK << pin;
    }
public:
    static inline void set_type (std::uint32_t pin, GPIO_Output_Types type) {
        set(calculate_value(pin, type), calculate_bitmask(pin));
    }
};

class COutputSpeedRegister : public CRegister<0x48000008> {
private:
    static inline std::uint32_t calculate_value (std::uint32_t pin, GPIO_Output_Speeds speed) {
        return speed << (pin * 2);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t pin) {
        return OSPEEDR_MASK << (pin * 2);
    }
public:
    static inline void set_speed (std::uint32_t pin, GPIO_Output_Speeds speed) {
        set(calculate_value(pin, speed), calculate_bitmask(pin));
    }
};

class CBitSetResetRegister : public CRegister<0x4800000c> {
private:
    static inline std::uint32_t calculate_bitmask (std::uint32_t pin) {
        return BSSR_MASK << pin;
    }
public:
    static inline void set_pin (std::uint32_t pin) {
        set_bits(calculate_bitmask(pin));
    }
    static inline void reset_pin (std::uint32_t pin) {
        set_bits(calculate_bitmask(2 * pin));
    }
};

struct GPIO_InitStruct {
    std::uint32_t pin;
    GPIO_Modes mode;
    GPIO_Output_Types type;
    GPIO_Output_Speeds speed;
};

void GPIO_Init(GPIO_InitStruct* conf) {
    /* check the values */
    if (!IS_GPIO_PIN(conf->pin)) { return; }
    if (!IS_GPIO_MODE(conf->mode)) { return; }

    /* configure the GPIO based on the settings */
    if (conf->mode == GPIO_MODE_OUTPUT) {
        COutputSpeedRegister::set_speed(conf->pin, conf->speed);
        COutputTypeRegister::set_type(conf->pin, conf->type);
    }
    CModeRegister::set_mode(conf->pin, conf->mode);

    /* ... */
}

class CPin {
private:
    std::uint8_t m_pin { 0 };
public:
    CPin () = delete;
    CPin (std::uint8_t pin) : m_pin(pin) {}
    void set () const {
        CBitSetResetRegister::set_pin(m_pin);
    }
    void reset () const {
        CBitSetResetRegister::reset_pin(m_pin);
    }
};
static_assert(IPin<CPin>,
    "CPin must implement the IPin constraint"); // optional

void delay (uint32_t delay) {
    volatile uint32_t counter = delay;
    while (counter > 0) {
        counter = counter - 1;
    }
}

int main (void) {
    GPIO_InitStruct conf = {0};
    conf.pin = GPIO_PIN_6;
    conf.mode = GPIO_MODE_OUTPUT;
    conf.type = GPIO_TYPE_OD;
    conf.speed = GPIO_SPEED_SLOW;
    GPIO_Init(&conf);

    CPin pin { GPIO_PIN_6 };
    CLed<CPin> led { &pin };

    while (true) {
        led.toggle();
        delay(1000);
    }
}
