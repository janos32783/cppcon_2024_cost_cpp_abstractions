#pragma once

#include <cstdint>

#include "hal/systick/constants.hpp"
#include "hal/register.hpp"

namespace hal {
namespace systick {

class CControlAndStatusRegister : public CRegister<STK_BASE_ADDR + STK_CSR_OFFSET> { };

class CReloadValueRegister : public CRegister<STK_BASE_ADDR + STK_RVR_OFFSET> {
public:
    inline void set_reload_value (std::uint32_t val) {
        this->set(val, STK_RVR_RELOAD_MSK);
    }
};

class CCurrentValueRegister : public CRegister<STK_BASE_ADDR + STK_CVR_OFFSET> {
public:
    inline void set_current_value (std::uint32_t val) {
        this->set(val, STK_CVR_CURRENT_MSK);
    }
};

class CCalibrationValueRegister : public CRegister<STK_BASE_ADDR + STK_CALIB_OFFSET> { };

} /* namespace systick */
} /* namespace hal */