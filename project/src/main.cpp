#include <cstdint>

#include "hal/gpio/gpio.hpp"
#include "drv/led.hpp"

void delay (int cycles) {
    volatile int i;
    for (i = 0; i < cycles;) { i = i + 1; }
}

using namespace hal;

int main (void) {

    CGpio<hal::gpio_ports::port_c, hal::gpio_pins::pin_13, hal::gpio_modes::output> gpio {};

    drv::CLed<decltype(gpio)> led { &gpio };

    while (true) {
        led.toggle();
        delay(200000);
    }
}
