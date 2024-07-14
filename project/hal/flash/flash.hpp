#pragma once

#include <cstdint>

#include "hal/flash/constants.hpp"
#include "hal/flash/registers.hpp"

namespace hal {
namespace flash {

class CFlash {
public:
    static void enable_prefetch () {
        CAccessControlRegister acr {};
        acr.enable_prefetch();
    }
};

} /* namespace flash */
} /* namespace hal */