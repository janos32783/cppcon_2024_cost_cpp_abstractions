#include <cstdint>

#include "hal/gpio/gpio.hpp"
#include "led.hpp"

void delay (int cycles) {
    volatile int i;
    for (i = 0; i < cycles;) { i = i + 1; }
}

using namespace hal;

int main (void) {

    CGpio<gpio_ports::port_c, gpio_pins::pin_13, gpio_modes::output> gpio {};

    CLed<decltype(gpio)> led { &gpio };

    while (true) {
        led.toggle();
        delay(200000);
    }
}
