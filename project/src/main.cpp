#include <cstdint>

#include "hal/flash/flash.hpp"
#include "hal/gpio/gpio.hpp"
#include "drv/led.hpp"

void delay (int cycles) {
    volatile int i;
    for (i = 0; i < cycles;) { i = i + 1; }
}

int main (void) {
    hal::flash::CFlash::enable_prefetch();


    hal::gpio::CPin<hal::gpio::ports::port_c, hal::gpio::pins::pin_13, hal::gpio::modes::output> gpio {};

    drv::CLed<decltype(gpio)> led { &gpio };

    while (true) {
        led.toggle();
        delay(200000);
    }
}
