#pragma once

#include "hal/common.hpp"
#include "hal/flash/flash.hpp"
#include "hal/rcc/rcc.hpp"
#include "hal/systick/systick.hpp"
#include "hal/gpio/gpio.hpp"

namespace hal {

template <systick::SystickConfig systick_conf, rcc::OscInitConfig osc_conf, rcc::ClkInitConfig clock_conf, std::uint32_t flash_latency, std::uint32_t hse_freq>
static inline hal_error init () {
    hal::flash::CFlash::enable_prefetch();
    hal::systick::CSysTick::init<systick_conf>();
    hal::rcc::CRcc::enable_syscfg_clock();
    hal::rcc::CRcc::enable_pwr_clock();
    NVIC_SetPriority(SVC_IRQn, 1);
    NVIC_SetPriority(PendSV_IRQn, 1);

    hal_error error = rcc::CRcc::configure_oscillator<osc_conf>();
    if (error != hal_error::ok) {
        return error;
    }
    error = rcc::CRcc::configure_clock<clock_conf, flash_latency>();
    if (error != hal_error::ok) {
        return error;
    }
    constexpr systick::SystickConfig updated_systick_conf {
        .prio = systick_conf.prio,
        .core_clock_freq = rcc::calculate_core_frequency<osc_conf, clock_conf, hse_freq>(),
        .systick_freq = systick_conf.systick_freq
    };
    hal::systick::CSysTick::init<updated_systick_conf>();
    
    return hal_error::ok;
}

} /* namespace hal */