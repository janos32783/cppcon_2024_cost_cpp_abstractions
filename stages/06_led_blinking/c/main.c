#include <stdint.h>
#include <stdbool.h>

#define AHBENR       (*((volatile uint32_t*)0x40021014))
#define GPIO_A_MODER (*((volatile uint32_t*)0x48000800))
#define GPIO_A_BSRR  (*((volatile uint32_t*)0x48000818))

void delay (int cycles) {
    volatile int i;
    for (i = 0; i < cycles;) { i = i + 1; }
}

int main (void) {
    uint32_t tmp;
    bool led_on = false;

    AHBENR = AHBENR | 0x00080000;
    
    tmp = GPIO_A_MODER;
    tmp &= ~0x0c000000;
    tmp |= 0x04000000;
    GPIO_A_MODER = tmp;

    GPIO_A_BSRR = GPIO_A_BSRR | 0x20000000;


    while (1) {
        if (led_on) {
            GPIO_A_BSRR = GPIO_A_BSRR | 0x20000000;
            led_on = false;
        }
        else {
            GPIO_A_BSRR = GPIO_A_BSRR | 0x00002000;
            led_on = true;
        }
        delay(500000);
    }
}