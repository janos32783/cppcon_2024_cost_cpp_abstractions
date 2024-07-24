#include <stdint.h>

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

typedef struct {
    uint32_t pin;
    GPIO_Modes mode;
    GPIO_Output_Types type;
    GPIO_Output_Speeds speed;
} GPIO_InitStruct;

//static inline
void GPIO_Init(GPIO_InitStruct* conf) {
    uint32_t temp;

    /* check the values */
    if (!IS_GPIO_PIN(conf->pin)) { return; }
    if (!IS_GPIO_MODE(conf->mode)) { return; }

    /* configure the GPIO based on the settings */
    if (conf->mode == GPIO_MODE_OUTPUT) {
        temp = OSPEEDR;
        temp &= ~(OSPEEDR_MASK << (conf->pin * 2u));
        temp |= (conf->speed << (conf->pin * 2u));
        OSPEEDR = temp;

        temp = OTYPER;
        temp &= ~(OTYPER_MASK << conf->pin);
        temp |= (((conf->type & GPIO_OUTPUT_TYPE) >> 4u) << conf->pin);
        OTYPER = temp;
    }

    temp = MODER;
    temp &= ~(MODER_MASK << (conf->pin * 2u));
    temp |= ((conf->mode & GPIO_MODE) << (conf->pin * 2u));
    MODER = temp;

    /* ... */
}

int main (void) {
    GPIO_InitStruct conf = {0};
    
    conf.pin = GPIO_PIN_6;
    conf.mode = GPIO_MODE_OUTPUT;
    conf.type = GPIO_TYPE_OD;
    conf.speed = GPIO_SPEED_SLOW;

    GPIO_Init(&conf);
    
    //conf.pin = GPIO_PIN_7;
    //conf.mode = GPIO_MODE_INPUT;

    //GPIO_Init(&conf);

    while (1) {}
}