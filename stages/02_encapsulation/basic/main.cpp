#include <cstdint>
#include <concepts>
#include <type_traits>

#include "register.hpp"

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

class CModeRegister {
private:
    const CRegister m_register { 0x48000000 };

    inline std::uint32_t calculate_value (std::uint32_t pin, GPIO_Modes mode) {
        return (mode & GPIO_MODE) << (pin * 2);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t pin) {
        return MODER_MASK << (pin * 2);
    }
public:
    inline void set_mode (std::uint32_t pin, GPIO_Modes mode) {
        m_register.set(calculate_value(pin, mode), calculate_bitmask(pin));
    }
};

class COutputTypeRegister {
private:
    const CRegister m_register { 0x48000004 };

    inline std::uint32_t calculate_value (std::uint32_t pin, GPIO_Output_Types type) {
        return ((type & GPIO_OUTPUT_TYPE) >> 4u) << pin;
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t pin) {
        return OTYPER_MASK << pin;
    }
public:
    inline void set_type (std::uint32_t pin, GPIO_Output_Types type) {
        m_register.set(calculate_value(pin, type), calculate_bitmask(pin));
    }
};

class COutputSpeedRegister {
private:
    const CRegister m_register { 0x48000008 };

    inline std::uint32_t calculate_value (std::uint32_t pin, GPIO_Output_Speeds speed) {
        return speed << (pin * 2);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t pin) {
        return OSPEEDR_MASK << (pin * 2);
    }
public:
    inline void set_speed (std::uint32_t pin, GPIO_Output_Speeds speed) {
        m_register.set(calculate_value(pin, speed), calculate_bitmask(pin));
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
        COutputSpeedRegister ospeedr {};
        COutputTypeRegister otyper {};
        ospeedr.set_speed(conf->pin, conf->speed);
        otyper.set_type(conf->pin, conf->type);
    }
    CModeRegister moder {};
    moder.set_mode(conf->pin, conf->mode);

    /* ... */
}

int main (void) {
    GPIO_InitStruct conf = {0};
    
    conf.pin = GPIO_PIN_6;
    conf.mode = GPIO_MODE_OUTPUT;
    conf.type = GPIO_TYPE_OD;
    conf.speed = GPIO_SPEED_SLOW;

    GPIO_Init(&conf);

    while (true) { /* ... */ }
}
