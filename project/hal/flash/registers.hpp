#pragma once

#include <cstdint>

#include "hal/flash/constants.hpp"
#include "hal/register.hpp"

namespace hal {
namespace flash {

// FLASH_ACR

class CAccessControlRegister : public CRegister<FLASH_BASE_ADDR + FLASH_ACR_OFFSET> {
public:
    inline void enable_prefetch () {
        this->set_bits(FLASH_ACR_PRFTBE_MSK);
    }
};

// FLASH_KEYR

class CKeyRegister : public CRegister<FLASH_BASE_ADDR + FLASH_KEYR_OFFSET> { /* TODO */ };

// FLASH_OPTKEYR

class COptionKeyRegister : public CRegister<FLASH_BASE_ADDR + FLASH_OPTKEYR_OFFSET> { /* TODO */ };

// FLASH_SR

class CStatusRegister : public CRegister<FLASH_BASE_ADDR + FLASH_SR_OFFSET> { /* TODO */ };

// FLASH_CR

class CControlRegister : public CRegister<FLASH_BASE_ADDR + FLASH_CR_OFFSET> { /* TODO */ };

// FLASH_AR

class CAddressRegister : public CRegister<FLASH_BASE_ADDR + FLASH_AR_OFFSET> { /* TODO */ };

// FLASH_OBR

class COptionByteRegister : public CRegister<FLASH_BASE_ADDR + FLASH_OBR_OFFSET> { /* TODO */ };

// FLASH_WRPR

class CWriteProtectionRegister : public CRegister<FLASH_BASE_ADDR + FLASH_WRPR_OFFSET> { /* TODO */ };

} /* namespace flash */
} /* namespace hal */