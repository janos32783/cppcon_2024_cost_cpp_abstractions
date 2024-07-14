#pragma once

#include <cstdint>
#include <concepts>

namespace hal {
namespace flash {

// FLASH register base addresses
constexpr std::uint32_t FLASH_BASE_ADDR = UINT32_C(0x40022000);

template <std::uint32_t base_addr>
concept is_valid_base_address = (
    base_addr == FLASH_BASE_ADDR
);
constexpr std::uint32_t FLASH_ACR_OFFSET          = UINT32_C(0x0);
constexpr std::uint32_t FLASH_KEYR_OFFSET         = UINT32_C(0x4);
constexpr std::uint32_t FLASH_OPTKEYR_OFFSET      = UINT32_C(0x8);
constexpr std::uint32_t FLASH_SR_OFFSET           = UINT32_C(0xC);
constexpr std::uint32_t FLASH_CR_OFFSET           = UINT32_C(0x10);
constexpr std::uint32_t FLASH_AR_OFFSET           = UINT32_C(0x14);
constexpr std::uint32_t FLASH_OBR_OFFSET          = UINT32_C(0x1C);
constexpr std::uint32_t FLASH_WRPR_OFFSET         = UINT32_C(0x20);
// Flash access control register
constexpr std::uint32_t FLASH_ACR_LATENCY_MSK    = UINT32_C(0b00000000000000000000000000000111);
constexpr std::uint32_t FLASH_ACR_LATENCY_POS    = UINT32_C(0);
constexpr std::uint32_t FLASH_ACR_PRFTBE_MSK     = UINT32_C(0b00000000000000000000000000010000);
constexpr std::uint32_t FLASH_ACR_PRFTBE_POS     = UINT32_C(4);
constexpr std::uint32_t FLASH_ACR_PRFTBS_MSK     = UINT32_C(0b00000000000000000000000000100000);
constexpr std::uint32_t FLASH_ACR_PRFTBS_POS     = UINT32_C(5);
// Flash key register
constexpr std::uint32_t FLASH_KEYR_FKEYR_MSK      = UINT32_C(0b11111111111111111111111111111111);
constexpr std::uint32_t FLASH_KEYR_FKEYR_POS      = UINT32_C(0);
// Flash option key register
constexpr std::uint32_t FLASH_OPTKEYR_OPTKEYR_MSK    = UINT32_C(0b11111111111111111111111111111111);
constexpr std::uint32_t FLASH_OPTKEYR_OPTKEYR_POS    = UINT32_C(0);
// Flash status register
constexpr std::uint32_t FLASH_SR_EOP_MSK        = UINT32_C(0b00000000000000000000000000100000);
constexpr std::uint32_t FLASH_SR_EOP_POS        = UINT32_C(5);
constexpr std::uint32_t FLASH_SR_WRPRT_MSK      = UINT32_C(0b00000000000000000000000000010000);
constexpr std::uint32_t FLASH_SR_WRPRT_POS      = UINT32_C(4);
constexpr std::uint32_t FLASH_SR_PGERR_MSK      = UINT32_C(0b00000000000000000000000000000100);
constexpr std::uint32_t FLASH_SR_PGERR_POS      = UINT32_C(2);
constexpr std::uint32_t FLASH_SR_BSY_MSK        = UINT32_C(0b00000000000000000000000000000001);
constexpr std::uint32_t FLASH_SR_BSY_POS        = UINT32_C(0);
// Flash control register
constexpr std::uint32_t FLASH_CR_FORCE_OPTLOAD_MSK = UINT32_C(0b00000000000000000010000000000000);
constexpr std::uint32_t FLASH_CR_FORCE_OPTLOAD_POS = UINT32_C(13);
constexpr std::uint32_t FLASH_CR_EOPIE_MSK      = UINT32_C(0b00000000000000000001000000000000);
constexpr std::uint32_t FLASH_CR_EOPIE_POS      = UINT32_C(12);
constexpr std::uint32_t FLASH_CR_ERRIE_MSK      = UINT32_C(0b00000000000000000000010000000000);
constexpr std::uint32_t FLASH_CR_ERRIE_POS      = UINT32_C(10);
constexpr std::uint32_t FLASH_CR_OPTWRE_MSK     = UINT32_C(0b00000000000000000000001000000000);
constexpr std::uint32_t FLASH_CR_OPTWRE_POS     = UINT32_C(9);
constexpr std::uint32_t FLASH_CR_LOCK_MSK       = UINT32_C(0b00000000000000000000000010000000);
constexpr std::uint32_t FLASH_CR_LOCK_POS       = UINT32_C(7);
constexpr std::uint32_t FLASH_CR_STRT_MSK       = UINT32_C(0b00000000000000000000000001000000);
constexpr std::uint32_t FLASH_CR_STRT_POS       = UINT32_C(6);
constexpr std::uint32_t FLASH_CR_OPTER_MSK      = UINT32_C(0b00000000000000000000000000100000);
constexpr std::uint32_t FLASH_CR_OPTER_POS      = UINT32_C(5);
constexpr std::uint32_t FLASH_CR_OPTPG_MSK      = UINT32_C(0b00000000000000000000000000010000);
constexpr std::uint32_t FLASH_CR_OPTPG_POS      = UINT32_C(4);
constexpr std::uint32_t FLASH_CR_MER_MSK        = UINT32_C(0b00000000000000000000000000000100);
constexpr std::uint32_t FLASH_CR_MER_POS        = UINT32_C(2);
constexpr std::uint32_t FLASH_CR_PER_MSK        = UINT32_C(0b00000000000000000000000000000010);
constexpr std::uint32_t FLASH_CR_PER_POS        = UINT32_C(1);
constexpr std::uint32_t FLASH_CR_PG_MSK         = UINT32_C(0b00000000000000000000000000000001);
constexpr std::uint32_t FLASH_CR_PG_POS         = UINT32_C(0);
// Flash address register
constexpr std::uint32_t FLASH_AR_FAR_MSK        = UINT32_C(0b11111111111111111111111111111111);
constexpr std::uint32_t FLASH_AR_FAR_POS        = UINT32_C(0);
// Option byte register
constexpr std::uint32_t FLASH_OBR_OPTERR_MSK     = UINT32_C(0b00000000000000000000000000000001);
constexpr std::uint32_t FLASH_OBR_OPTERR_POS     = UINT32_C(0);
constexpr std::uint32_t FLASH_OBR_RDPRT_MSK      = UINT32_C(0b00000000000000000000000000000110);
constexpr std::uint32_t FLASH_OBR_RDPRT_POS      = UINT32_C(1);
constexpr std::uint32_t FLASH_OBR_WDG_SW_MSK     = UINT32_C(0b00000000000000000000000100000000);
constexpr std::uint32_t FLASH_OBR_WDG_SW_POS     = UINT32_C(8);
constexpr std::uint32_t FLASH_OBR_nRST_STOP_MSK  = UINT32_C(0b00000000000000000000001000000000);
constexpr std::uint32_t FLASH_OBR_nRST_STOP_POS  = UINT32_C(9);
constexpr std::uint32_t FLASH_OBR_nRST_STDBY_MSK = UINT32_C(0b00000000000000000000010000000000);
constexpr std::uint32_t FLASH_OBR_nRST_STDBY_POS = UINT32_C(10);
constexpr std::uint32_t FLASH_OBR_nBOOT1_MSK     = UINT32_C(0b00000000000000000001000000000000);
constexpr std::uint32_t FLASH_OBR_nBOOT1_POS     = UINT32_C(12);
constexpr std::uint32_t FLASH_OBR_VDDA_MONITOR_MSK = UINT32_C(0b00000000000000000010000000000000);
constexpr std::uint32_t FLASH_OBR_VDDA_MONITOR_POS = UINT32_C(13);
constexpr std::uint32_t FLASH_OBR_RAM_PARITY_CHECK__MSK = UINT32_C(0b00000000000000000100000000000000);
constexpr std::uint32_t FLASH_OBR_RAM_PARITY_CHECK__POS = UINT32_C(14);
constexpr std::uint32_t FLASH_OBR_Data0_MSK      = UINT32_C(0b00000000111111110000000000000000);
constexpr std::uint32_t FLASH_OBR_Data0_POS      = UINT32_C(16);
constexpr std::uint32_t FLASH_OBR_Data1_MSK      = UINT32_C(0b11111111000000000000000000000000);
constexpr std::uint32_t FLASH_OBR_Data1_POS      = UINT32_C(24);
// Write protection register
constexpr std::uint32_t FLASH_WRPR_WRP_MSK        = UINT32_C(0b11111111111111111111111111111111);
constexpr std::uint32_t FLASH_WRPR_WRP_POS        = UINT32_C(0);

} /* namespace flash */
} /* namespace hal */