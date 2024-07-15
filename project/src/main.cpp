#include <cstdint>

#include "hal/flash/flash.hpp"
#include "hal/systick/systick.hpp"
#include "hal/gpio/gpio.hpp"
#include "drv/led.hpp"

constexpr hal::systick::SystickConfig systick_config {
    .prio = 0,
    .core_clock_freq = 8000000, // 8MHz
    .systick_freq = hal::systick::tick_frequencies::freq_1kHz
};

void delay (int cycles) {
    volatile int i;
    for (i = 0; i < cycles;) { i = i + 1; }
}

int main (void) {
    hal::flash::CFlash::enable_prefetch();
    hal::systick::init<systick_config>();


    hal::gpio::CPin<hal::gpio::ports::port_c, hal::gpio::pins::pin_13, hal::gpio::modes::output> gpio {};

    drv::CLed<decltype(gpio)> led { &gpio };

    while (true) {
        led.toggle();
        delay(200000);
    }
}
