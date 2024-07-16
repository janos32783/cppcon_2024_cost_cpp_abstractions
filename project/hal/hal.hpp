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



} /* namespace hal */