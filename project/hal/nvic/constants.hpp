#pragma once

#include <cstdint>
#include <concepts>

namespace hal {
namespace nvic {

// TODO : why is there 3 defined in SVD but 2 used in the firmware?
constexpr std::uint32_t nvic_prio_bits { 2 }; // 2 nvic prio bits

// NVIC register base addresses
constexpr std::uint32_t NVIC_BASE_ADDR = UINT32_C(0xe000e100);

template <std::uint32_t base_addr>
concept is_valid_base_address = (
    base_addr == NVIC_BASE_ADDR
);
constexpr std::uint32_t STK_ISER_OFFSET         = UINT32_C(0x0);
constexpr std::uint32_t STK_ICER_OFFSET         = UINT32_C(0x80);
constexpr std::uint32_t STK_ISPR_OFFSET         = UINT32_C(0x100);
constexpr std::uint32_t STK_ICPR_OFFSET         = UINT32_C(0x180);
constexpr std::uint32_t STK_IPR0_OFFSET         = UINT32_C(0x300);
constexpr std::uint32_t STK_IPR1_OFFSET         = UINT32_C(0x304);
constexpr std::uint32_t STK_IPR2_OFFSET         = UINT32_C(0x308);
constexpr std::uint32_t STK_IPR3_OFFSET         = UINT32_C(0x30C);
constexpr std::uint32_t STK_IPR4_OFFSET         = UINT32_C(0x310);
constexpr std::uint32_t STK_IPR5_OFFSET         = UINT32_C(0x314);
constexpr std::uint32_t STK_IPR6_OFFSET         = UINT32_C(0x318);
constexpr std::uint32_t STK_IPR7_OFFSET         = UINT32_C(0x31C);
// Interrupt Set Enable Register
constexpr std::uint32_t NVIC_ISER_SETENA_MSK     = UINT32_C(0b11111111111111111111111111111111);
constexpr std::uint32_t NVIC_ISER_SETENA_POS     = UINT32_C(0);
// Interrupt Clear Enable Register
constexpr std::uint32_t NVIC_ICER_CLRENA_MSK     = UINT32_C(0b11111111111111111111111111111111);
constexpr std::uint32_t NVIC_ICER_CLRENA_POS     = UINT32_C(0);
// Interrupt Set-Pending Register
constexpr std::uint32_t NVIC_ISPR_SETPEND_MSK    = UINT32_C(0b11111111111111111111111111111111);
constexpr std::uint32_t NVIC_ISPR_SETPEND_POS    = UINT32_C(0);
// Interrupt Clear-Pending Register
constexpr std::uint32_t NVIC_ICPR_CLRPEND_MSK    = UINT32_C(0b11111111111111111111111111111111);
constexpr std::uint32_t NVIC_ICPR_CLRPEND_POS    = UINT32_C(0);
// Interrupt Priority Register 0
constexpr std::uint32_t NVIC_IPR0_PRI_00_MSK     = UINT32_C(0b00000000000000000000000011000000);
constexpr std::uint32_t NVIC_IPR0_PRI_00_POS     = UINT32_C(6);
constexpr std::uint32_t NVIC_IPR0_PRI_01_MSK     = UINT32_C(0b00000000000000001100000000000000);
constexpr std::uint32_t NVIC_IPR0_PRI_01_POS     = UINT32_C(14);
constexpr std::uint32_t NVIC_IPR0_PRI_02_MSK     = UINT32_C(0b00000000110000000000000000000000);
constexpr std::uint32_t NVIC_IPR0_PRI_02_POS     = UINT32_C(22);
constexpr std::uint32_t NVIC_IPR0_PRI_03_MSK     = UINT32_C(0b11000000000000000000000000000000);
constexpr std::uint32_t NVIC_IPR0_PRI_03_POS     = UINT32_C(30);
// Interrupt Priority Register 1
constexpr std::uint32_t NVIC_IPR1_PRI_40_MSK     = UINT32_C(0b00000000000000000000000011000000);
constexpr std::uint32_t NVIC_IPR1_PRI_40_POS     = UINT32_C(6);
constexpr std::uint32_t NVIC_IPR1_PRI_41_MSK     = UINT32_C(0b00000000000000001100000000000000);
constexpr std::uint32_t NVIC_IPR1_PRI_41_POS     = UINT32_C(14);
constexpr std::uint32_t NVIC_IPR1_PRI_42_MSK     = UINT32_C(0b00000000110000000000000000000000);
constexpr std::uint32_t NVIC_IPR1_PRI_42_POS     = UINT32_C(22);
constexpr std::uint32_t NVIC_IPR1_PRI_43_MSK     = UINT32_C(0b11000000000000000000000000000000);
constexpr std::uint32_t NVIC_IPR1_PRI_43_POS     = UINT32_C(30);
// Interrupt Priority Register 2
constexpr std::uint32_t NVIC_IPR2_PRI_80_MSK     = UINT32_C(0b00000000000000000000000011000000);
constexpr std::uint32_t NVIC_IPR2_PRI_80_POS     = UINT32_C(6);
constexpr std::uint32_t NVIC_IPR2_PRI_81_MSK     = UINT32_C(0b00000000000000001100000000000000);
constexpr std::uint32_t NVIC_IPR2_PRI_81_POS     = UINT32_C(14);
constexpr std::uint32_t NVIC_IPR2_PRI_82_MSK     = UINT32_C(0b00000000110000000000000000000000);
constexpr std::uint32_t NVIC_IPR2_PRI_82_POS     = UINT32_C(22);
constexpr std::uint32_t NVIC_IPR2_PRI_83_MSK     = UINT32_C(0b11000000000000000000000000000000);
constexpr std::uint32_t NVIC_IPR2_PRI_83_POS     = UINT32_C(30);
// Interrupt Priority Register 3
constexpr std::uint32_t NVIC_IPR3_PRI_120_MSK    = UINT32_C(0b00000000000000000000000011000000);
constexpr std::uint32_t NVIC_IPR3_PRI_120_POS    = UINT32_C(6);
constexpr std::uint32_t NVIC_IPR3_PRI_121_MSK    = UINT32_C(0b00000000000000001100000000000000);
constexpr std::uint32_t NVIC_IPR3_PRI_121_POS    = UINT32_C(14);
constexpr std::uint32_t NVIC_IPR3_PRI_122_MSK    = UINT32_C(0b00000000110000000000000000000000);
constexpr std::uint32_t NVIC_IPR3_PRI_122_POS    = UINT32_C(22);
constexpr std::uint32_t NVIC_IPR3_PRI_123_MSK    = UINT32_C(0b11000000000000000000000000000000);
constexpr std::uint32_t NVIC_IPR3_PRI_123_POS    = UINT32_C(30);
// Interrupt Priority Register 4
constexpr std::uint32_t NVIC_IPR4_PRI_160_MSK    = UINT32_C(0b00000000000000000000000011000000);
constexpr std::uint32_t NVIC_IPR4_PRI_160_POS    = UINT32_C(6);
constexpr std::uint32_t NVIC_IPR4_PRI_161_MSK    = UINT32_C(0b00000000000000001100000000000000);
constexpr std::uint32_t NVIC_IPR4_PRI_161_POS    = UINT32_C(14);
constexpr std::uint32_t NVIC_IPR4_PRI_162_MSK    = UINT32_C(0b00000000110000000000000000000000);
constexpr std::uint32_t NVIC_IPR4_PRI_162_POS    = UINT32_C(22);
constexpr std::uint32_t NVIC_IPR4_PRI_163_MSK    = UINT32_C(0b11000000000000000000000000000000);
constexpr std::uint32_t NVIC_IPR4_PRI_163_POS    = UINT32_C(30);
// Interrupt Priority Register 5
constexpr std::uint32_t NVIC_IPR5_PRI_200_MSK    = UINT32_C(0b00000000000000000000000011000000);
constexpr std::uint32_t NVIC_IPR5_PRI_200_POS    = UINT32_C(6);
constexpr std::uint32_t NVIC_IPR5_PRI_201_MSK    = UINT32_C(0b00000000000000001100000000000000);
constexpr std::uint32_t NVIC_IPR5_PRI_201_POS    = UINT32_C(14);
constexpr std::uint32_t NVIC_IPR5_PRI_202_MSK    = UINT32_C(0b00000000110000000000000000000000);
constexpr std::uint32_t NVIC_IPR5_PRI_202_POS    = UINT32_C(22);
constexpr std::uint32_t NVIC_IPR5_PRI_203_MSK    = UINT32_C(0b11000000000000000000000000000000);
constexpr std::uint32_t NVIC_IPR5_PRI_203_POS    = UINT32_C(30);
// Interrupt Priority Register 6
constexpr std::uint32_t NVIC_IPR6_PRI_240_MSK    = UINT32_C(0b00000000000000000000000011000000);
constexpr std::uint32_t NVIC_IPR6_PRI_240_POS    = UINT32_C(6);
constexpr std::uint32_t NVIC_IPR6_PRI_241_MSK    = UINT32_C(0b00000000000000001100000000000000);
constexpr std::uint32_t NVIC_IPR6_PRI_241_POS    = UINT32_C(14);
constexpr std::uint32_t NVIC_IPR6_PRI_242_MSK    = UINT32_C(0b00000000110000000000000000000000);
constexpr std::uint32_t NVIC_IPR6_PRI_242_POS    = UINT32_C(22);
constexpr std::uint32_t NVIC_IPR6_PRI_243_MSK    = UINT32_C(0b11000000000000000000000000000000);
constexpr std::uint32_t NVIC_IPR6_PRI_243_POS    = UINT32_C(30);
// Interrupt Priority Register 7
constexpr std::uint32_t NVIC_IPR7_PRI_280_MSK    = UINT32_C(0b00000000000000000000000011000000);
constexpr std::uint32_t NVIC_IPR7_PRI_280_POS    = UINT32_C(6);
constexpr std::uint32_t NVIC_IPR7_PRI_281_MSK    = UINT32_C(0b00000000000000001100000000000000);
constexpr std::uint32_t NVIC_IPR7_PRI_281_POS    = UINT32_C(14);
constexpr std::uint32_t NVIC_IPR7_PRI_282_MSK    = UINT32_C(0b00000000110000000000000000000000);
constexpr std::uint32_t NVIC_IPR7_PRI_282_POS    = UINT32_C(22);
constexpr std::uint32_t NVIC_IPR7_PRI_283_MSK    = UINT32_C(0b11000000000000000000000000000000);
constexpr std::uint32_t NVIC_IPR7_PRI_283_POS    = UINT32_C(30);

} /* namespace nvic */
} /* namespace hal */