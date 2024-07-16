#include <cstdint>

#include "hal/flash/flash.hpp"
#include "hal/rcc/rcc.hpp"
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
    hal::systick::CSysTick::init<systick_config>();
    hal::rcc::CRcc::enable_syscfg_clock();
    hal::rcc::CRcc::enable_pwr_clock();


    hal::rcc::CRcc::enable_gpio_clock<hal::gpio::ports::port_c>();

    hal::gpio::CPin<hal::gpio::ports::port_c, hal::gpio::pins::pin_13> gpio {};
    gpio.configure<hal::gpio::modes::output>();

    drv::CLed<decltype(gpio)> led { &gpio };

    while (true) {
        led.toggle();
        delay(200000);
    }
}
