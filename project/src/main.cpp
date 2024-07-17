#include <cstdint>

#include "hal/hal.hpp"
#include "drv/led.hpp"

constexpr hal::systick::SystickConfig systick_config {
    .prio = 0,
    .core_clock_freq = 8000000, // 8MHz
    .systick_freq = hal::systick::tick_frequencies::freq_1kHz
};

constexpr hal::rcc::OscInitConfig oscillator_config {
    .hse_state = hal::rcc::hse_states::on,
    .lse_state = hal::rcc::lse_states::noconf,
    .hsi_state = hal::rcc::hsi_states::noconf,
    .hsi_calib_value = hal::rcc::hsi_calibration_default,
    .hsi14_state = hal::rcc::hsi14_states::on,
    .hsi14_calib_value = 16,
    .lsi_state = hal::rcc::lsi_states::noconf,
    .pll = {
        .pll_state = hal::rcc::pll_states::noconf,
        .pll_source = hal::rcc::pll_sources::hsi,
        .pll_mul = hal::rcc::pll_mul_factors::mul2,
        .pll_div = hal::rcc::pll_predic_factors::div1
    }
};

constexpr hal::rcc::ClkInitConfig clock_config {
    .is_sysclk = true,
    .is_hclk = true,
    .is_pclk1 = true,
    .system_clock_source = hal::rcc::system_clock_sources::hsi,
    .ahb_clk_div = hal::rcc::ahb_clk_dividers::div1,
    .hclk_div = hal::rcc::hclk_dividers::div1
};

constexpr std::uint32_t flash_latency { 0 };

void delay (int cycles) {
    volatile int i;
    for (i = 0; i < cycles;) { i = i + 1; }
}

int main (void) {
    hal::init<systick_config>();
    hal::configure_system_clock<oscillator_config, clock_config, flash_latency>();


    hal::rcc::CRcc::enable_gpio_clock<hal::gpio::ports::port_c>();

    hal::gpio::CPin<hal::gpio::ports::port_c, hal::gpio::pins::pin_13> gpio {};
    gpio.configure<hal::gpio::modes::output>();

    drv::CLed<decltype(gpio)> led { &gpio };

    while (true) {
        led.toggle();
        delay(200000);
    }
}
