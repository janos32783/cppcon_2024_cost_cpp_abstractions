#include <stdint.h>
#include <stdbool.h>

#define AHBENR       (*((volatile uint32_t*)0x40021014))
#define GPIO_A_MODER (*((volatile uint32_t*)0x48000000))
#define GPIO_A_BSRR  (*((volatile uint32_t*)0x48000018))

void delay (int cycles) {
    volatile int i;
    for (i = 0; i < cycles;) { i = i + 1; }
}

int main (void) {
    uint32_t tmp;
    bool led_on = false;

    AHBENR = AHBENR | 0x00020000;
    
    tmp = GPIO_A_MODER;
    tmp &= ~0x00003000;
    tmp |= 0x00001000;
    GPIO_A_MODER = tmp;

    GPIO_A_BSRR = GPIO_A_BSRR | 0x00400000;


    while (1) {
        if (led_on) {
            GPIO_A_BSRR = GPIO_A_BSRR | 0x00400000;
            led_on = false;
        }
        else {
            GPIO_A_BSRR = GPIO_A_BSRR | 0x00000040;
            led_on = true;
        }
        delay(500000);
    }
}