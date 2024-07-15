#pragma once

#include <cstdint>
#include <concepts>

namespace hal {
namespace scb {

// SCB register base addresses
constexpr std::uint32_t SCB_BASE_ADDR = UINT32_C(0xe000ed00);

template <std::uint32_t base_addr>
concept is_valid_base_address = (
    base_addr == SCB_BASE_ADDR
);
constexpr std::uint32_t STK_CPUID_OFFSET        = UINT32_C(0x0);
constexpr std::uint32_t STK_ICSR_OFFSET         = UINT32_C(0x4);
constexpr std::uint32_t STK_AIRCR_OFFSET        = UINT32_C(0xC);
constexpr std::uint32_t STK_SCR_OFFSET          = UINT32_C(0x10);
constexpr std::uint32_t STK_CCR_OFFSET          = UINT32_C(0x14);
constexpr std::uint32_t STK_SHPR2_OFFSET        = UINT32_C(0x1C);
constexpr std::uint32_t STK_SHPR3_OFFSET        = UINT32_C(0x20);
// CPUID base register
constexpr std::uint32_t SCB_CPUID_Revision_MSK   = UINT32_C(0b00000000000000000000000000001111);
constexpr std::uint32_t SCB_CPUID_Revision_POS   = UINT32_C(0);
constexpr std::uint32_t SCB_CPUID_PartNo_MSK     = UINT32_C(0b00000000000000001111111111110000);
constexpr std::uint32_t SCB_CPUID_PartNo_POS     = UINT32_C(4);
constexpr std::uint32_t SCB_CPUID_Constant_MSK   = UINT32_C(0b00000000000011110000000000000000);
constexpr std::uint32_t SCB_CPUID_Constant_POS   = UINT32_C(16);
constexpr std::uint32_t SCB_CPUID_Variant_MSK    = UINT32_C(0b00000000111100000000000000000000);
constexpr std::uint32_t SCB_CPUID_Variant_POS    = UINT32_C(20);
constexpr std::uint32_t SCB_CPUID_Implementer_MSK = UINT32_C(0b11111111000000000000000000000000);
constexpr std::uint32_t SCB_CPUID_Implementer_POS = UINT32_C(24);
// Interrupt control and state register
constexpr std::uint32_t SCB_ICSR_VECTACTIVE_MSK = UINT32_C(0b00000000000000000000000000111111);
constexpr std::uint32_t SCB_ICSR_VECTACTIVE_POS = UINT32_C(0);
constexpr std::uint32_t SCB_ICSR_VECTPENDING_MSK = UINT32_C(0b00000000000000111111000000000000);
constexpr std::uint32_t SCB_ICSR_VECTPENDING_POS = UINT32_C(12);
constexpr std::uint32_t SCB_ICSR_ISRPENDING_MSK = UINT32_C(0b00000000010000000000000000000000);
constexpr std::uint32_t SCB_ICSR_ISRPENDING_POS = UINT32_C(22);
constexpr std::uint32_t SCB_ICSR_PENDSTCLR_MSK  = UINT32_C(0b00000010000000000000000000000000);
constexpr std::uint32_t SCB_ICSR_PENDSTCLR_POS  = UINT32_C(25);
constexpr std::uint32_t SCB_ICSR_PENDSTSET_MSK  = UINT32_C(0b00000100000000000000000000000000);
constexpr std::uint32_t SCB_ICSR_PENDSTSET_POS  = UINT32_C(26);
constexpr std::uint32_t SCB_ICSR_PENDSVCLR_MSK  = UINT32_C(0b00001000000000000000000000000000);
constexpr std::uint32_t SCB_ICSR_PENDSVCLR_POS  = UINT32_C(27);
constexpr std::uint32_t SCB_ICSR_PENDSVSET_MSK  = UINT32_C(0b00010000000000000000000000000000);
constexpr std::uint32_t SCB_ICSR_PENDSVSET_POS  = UINT32_C(28);
constexpr std::uint32_t SCB_ICSR_NMIPENDSET_MSK = UINT32_C(0b10000000000000000000000000000000);
constexpr std::uint32_t SCB_ICSR_NMIPENDSET_POS = UINT32_C(31);
// Application interrupt and reset control register
constexpr std::uint32_t SCB_AIRCR_VECTCLRACTIVE_MSK = UINT32_C(0b00000000000000000000000000000010);
constexpr std::uint32_t SCB_AIRCR_VECTCLRACTIVE_POS = UINT32_C(1);
constexpr std::uint32_t SCB_AIRCR_SYSRESETREQ_MSK = UINT32_C(0b00000000000000000000000000000100);
constexpr std::uint32_t SCB_AIRCR_SYSRESETREQ_POS = UINT32_C(2);
constexpr std::uint32_t SCB_AIRCR_ENDIANESS_MSK  = UINT32_C(0b00000000000000001000000000000000);
constexpr std::uint32_t SCB_AIRCR_ENDIANESS_POS  = UINT32_C(15);
constexpr std::uint32_t SCB_AIRCR_VECTKEYSTAT_MSK = UINT32_C(0b11111111111111110000000000000000);
constexpr std::uint32_t SCB_AIRCR_VECTKEYSTAT_POS = UINT32_C(16);
// System control register
constexpr std::uint32_t SCB_SCR_SLEEPONEXIT_MSK = UINT32_C(0b00000000000000000000000000000010);
constexpr std::uint32_t SCB_SCR_SLEEPONEXIT_POS = UINT32_C(1);
constexpr std::uint32_t SCB_SCR_SLEEPDEEP_MSK  = UINT32_C(0b00000000000000000000000000000100);
constexpr std::uint32_t SCB_SCR_SLEEPDEEP_POS  = UINT32_C(2);
constexpr std::uint32_t SCB_SCR_SEVEONPEND_MSK = UINT32_C(0b00000000000000000000000000010000);
constexpr std::uint32_t SCB_SCR_SEVEONPEND_POS = UINT32_C(4);
// Configuration and control register
constexpr std::uint32_t SCB_CCR_UNALIGN__TRP_MSK = UINT32_C(0b00000000000000000000000000001000);
constexpr std::uint32_t SCB_CCR_UNALIGN__TRP_POS = UINT32_C(3);
constexpr std::uint32_t SCB_CCR_STKALIGN_MSK   = UINT32_C(0b00000000000000000000001000000000);
constexpr std::uint32_t SCB_CCR_STKALIGN_POS   = UINT32_C(9);
// System handler priority registers
constexpr std::uint32_t SCB_SHPR2_PRI_11_MSK     = UINT32_C(0b11111111000000000000000000000000);
constexpr std::uint32_t SCB_SHPR2_PRI_11_POS     = UINT32_C(24);
// System handler priority registers
constexpr std::uint32_t SCB_SHPR3_PRI_14_MSK     = UINT32_C(0b00000000111111110000000000000000);
constexpr std::uint32_t SCB_SHPR3_PRI_14_POS     = UINT32_C(16);
constexpr std::uint32_t SCB_SHPR3_PRI_15_MSK     = UINT32_C(0b11111111000000000000000000000000);
constexpr std::uint32_t SCB_SHPR3_PRI_15_POS     = UINT32_C(24);

} /* namespace scb */
} /* namespace hal */