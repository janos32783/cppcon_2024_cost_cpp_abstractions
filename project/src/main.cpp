#include <cstdint>

#include "hal/hal.hpp"
#include "drv/led.hpp"

void error_handler();
void init_gpio ();

constexpr std::uint32_t HSE_FREQ = 16000000; // 16MHz external oscillator

constexpr hal::systick::SystickConfig systick_config {
    .prio = 0,
    .core_clock_freq = hal::rcc::HSI_FREQ,
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
        .pll_div = hal::rcc::pll_prediv_factors::div1
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
    if (hal::init<systick_config, oscillator_config, clock_config, flash_latency, HSE_FREQ>() != hal::hal_error::ok) {
        error_handler();
    }
    init_gpio();

    hal::gpio::CPin<hal::gpio::ports::port_c, hal::gpio::pins::pin_13> gpio {};
    gpio.configure<hal::gpio::modes::output>();

    drv::CLed<decltype(gpio)> led { &gpio };

    while (true) {
        led.toggle();
        delay(200000);
    }
}

void init_gpio () {
    hal::rcc::CRcc::enable_gpio_clock<hal::gpio::ports::port_a>();
    hal::rcc::CRcc::enable_gpio_clock<hal::gpio::ports::port_b>();
    hal::rcc::CRcc::enable_gpio_clock<hal::gpio::ports::port_c>();

    hal::gpio::CPort<hal::gpio::ports::port_a>::reset<
        hal::gpio::pins::pin_00,
        hal::gpio::pins::pin_01,
        hal::gpio::pins::pin_04,
        hal::gpio::pins::pin_08,
        hal::gpio::pins::pin_09,
        hal::gpio::pins::pin_10,
        hal::gpio::pins::pin_11,
        hal::gpio::pins::pin_12
    >();

    hal::gpio::CPort<hal::gpio::ports::port_b>::reset<
        hal::gpio::pins::pin_02,
        hal::gpio::pins::pin_05,
        hal::gpio::pins::pin_06,
        hal::gpio::pins::pin_07,
        hal::gpio::pins::pin_08,
        hal::gpio::pins::pin_09,
        hal::gpio::pins::pin_10,
        hal::gpio::pins::pin_11,
        hal::gpio::pins::pin_12,
        hal::gpio::pins::pin_13,
        hal::gpio::pins::pin_14,
        hal::gpio::pins::pin_15
    >();

    hal::gpio::CPort<hal::gpio::ports::port_a>::reset<hal::gpio::pins::pin_13>();

    constexpr hal::gpio::GpioInitConfig gpio_init {
        .mode = hal::gpio::modes::output,
        .output_type = hal::gpio::output_types::push_pull,
        .speed = hal::gpio::speeds::low,
        .pull_type = hal::gpio::pull_types::none
    };

    hal::gpio::CPort<hal::gpio::ports::port_a>::configure_pins<gpio_init, 
        hal::gpio::pins::pin_00,
        hal::gpio::pins::pin_01,
        hal::gpio::pins::pin_04,
        hal::gpio::pins::pin_08,
        hal::gpio::pins::pin_09,
        hal::gpio::pins::pin_10,
        hal::gpio::pins::pin_11,
        hal::gpio::pins::pin_12
    >();

    hal::gpio::CPort<hal::gpio::ports::port_b>::configure_pins<gpio_init, 
        hal::gpio::pins::pin_02,
        hal::gpio::pins::pin_05,
        hal::gpio::pins::pin_06,
        hal::gpio::pins::pin_07,
        hal::gpio::pins::pin_08,
        hal::gpio::pins::pin_09,
        hal::gpio::pins::pin_10,
        hal::gpio::pins::pin_11,
        hal::gpio::pins::pin_12,
        hal::gpio::pins::pin_13,
        hal::gpio::pins::pin_14,
        hal::gpio::pins::pin_15,
        hal::gpio::pins::pin_12
    >();

    hal::gpio::CPort<hal::gpio::ports::port_c>::configure_pins<gpio_init, hal::gpio::pins::pin_13>();
}

void error_handler() {
    __disable_irq();
    while (true) {
    }
}