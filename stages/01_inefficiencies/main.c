#include <stdint.h>

#define MODER (*((volatile uint32_t*)0x48000000))
#define OTYPER (*((volatile uint32_t*)0x48000004))
#define OSPEEDR (*((volatile uint32_t*)0x48000008))
/* ... */
#define GPIO_PIN_6 ((uint16_t)0x0006U)
/* ... */
#define MODER_MASK   (0x3UL)
#define OTYPER_MASK  (0x1UL)
#define OSPEEDR_MASK (0x3UL)
/* ... */
#define GPIO_MODE_INPUT  (0x00000000U)
#define GPIO_MODE_OUTPUT (0x00000001U)
/* ... */
#define GPIO_SPEED_FREQ_LOW (0x00000000U)
/* ... */
#define GPIO_MODE        (0x00000003U)
#define GPIO_OUTPUT_TYPE (0x00000010U)
/* ... */
#define IS_GPIO_PIN(X) ((X) < 16 && (X) >= 0)
#define IS_GPIO_MODE(X) (((X) == GPIO_MODE_INPUT) || ((X) == GPIO_MODE_OUTPUT))

typedef struct {
    uint32_t pin ;
    uint32_t mode ;
} GPIO_InitStruct ;

void GPIO_Init(GPIO_InitStruct* gpio_init_struct) {
    uint32_t temp;

    /* check the values */
    if (!IS_GPIO_PIN(gpio_init_struct->pin)) { return; }
    if (!IS_GPIO_MODE(gpio_init_struct->mode)) { return; }

    /* configure the GPIO based on the settings */
    if (gpio_init_struct->mode == GPIO_MODE_OUTPUT) {
        temp = OSPEEDR;
        temp &= ~(OSPEEDR_MASK << (gpio_init_struct->pin * 2u));
        temp |= (GPIO_SPEED_FREQ_LOW << (gpio_init_struct->pin * 2u));
        OSPEEDR = temp;

        temp = OTYPER;
        temp &= ~(OTYPER_MASK << gpio_init_struct->pin);
        temp |= (((gpio_init_struct->mode & GPIO_OUTPUT_TYPE) >> 4u) << gpio_init_struct->pin);
        OTYPER = temp;
    }

    temp = MODER;
    temp &= ~(MODER_MASK << (gpio_init_struct->pin * 2u));
    temp |= ((gpio_init_struct->mode & GPIO_MODE) << (gpio_init_struct->pin * 2u));
    MODER = temp;

    /* ... */
}

int main (void) {
    GPIO_InitStruct gpio_init_struct = {0};
    
    gpio_init_struct.pin = GPIO_PIN_6;
    gpio_init_struct.mode = GPIO_MODE_INPUT;

    GPIO_Init(& gpio_init_struct) ;

    while (1) {}
}