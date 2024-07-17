#pragma once

#include "hal/common.hpp"
#include "hal/flash/flash.hpp"
#include "hal/rcc/rcc.hpp"
#include "hal/systick/systick.hpp"
#include "hal/gpio/gpio.hpp"

namespace hal {

template <systick::SystickConfig config>
static inline void init () {
    hal::flash::CFlash::enable_prefetch();
    hal::systick::CSysTick::init<config>();
    hal::rcc::CRcc::enable_syscfg_clock();
    hal::rcc::CRcc::enable_pwr_clock();
    NVIC_SetPriority(SVC_IRQn, 1);
    NVIC_SetPriority(PendSV_IRQn, 1);
}

template <rcc::OscInitConfig osc_conf, rcc::ClkInitConfig clock_conf, std::uint32_t flash_latency>
static inline hal_error configure_system_clock () {
    hal_error error = rcc::CRcc::configure_oscillator<osc_conf>();
    if (error != hal_error::ok) {
        return error;
    }
    error = rcc::CRcc::configure_clock<clock_conf, flash_latency>();
    if (error != hal_error::ok) {
        return error;
    }
    return hal_error::ok;
}



} /* namespace hal */