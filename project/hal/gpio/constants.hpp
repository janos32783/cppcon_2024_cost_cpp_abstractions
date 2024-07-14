#pragma once

#include <cstdint>
#include <concepts>

namespace hal {
namespace gpio {

// GPIO register base addresses
constexpr std::uint32_t GPIOF_BASE_ADDR = UINT32_C(0x48001400);
constexpr std::uint32_t GPIOD_BASE_ADDR = UINT32_C(0x48000c00);
constexpr std::uint32_t GPIOC_BASE_ADDR = UINT32_C(0x48000800);
constexpr std::uint32_t GPIOB_BASE_ADDR = UINT32_C(0x48000400);
constexpr std::uint32_t GPIOA_BASE_ADDR = UINT32_C(0x48000000);

template <std::uint32_t base_address>
concept is_valid_base_address = (
    (base_address == GPIOF_BASE_ADDR) ||
    (base_address == GPIOD_BASE_ADDR) ||
    (base_address == GPIOC_BASE_ADDR) ||
    (base_address == GPIOB_BASE_ADDR) ||
    (base_address == GPIOA_BASE_ADDR)
);

enum class ports : std::uint8_t {
    port_f,
    port_d,
    port_c,
    port_b,
    port_a
};

template <ports port>
concept is_valid_port = (
    (port == ports::port_f) ||
    (port == ports::port_d) ||
    (port == ports::port_c) ||
    (port == ports::port_b) ||
    (port == ports::port_a)
);

template <ports port>
requires (is_valid_port<port>)
consteval std::uint32_t port_to_base_address () {
    if (port == ports::port_f) { return GPIOF_BASE_ADDR; }
    else if (port == ports::port_d) { return GPIOD_BASE_ADDR; }
    else if (port == ports::port_c) { return GPIOC_BASE_ADDR; }
    else if (port == ports::port_b) { return GPIOB_BASE_ADDR; }
    else { return GPIOA_BASE_ADDR; }
}
constexpr std::uint32_t GPIO_MODER_OFFSET        = UINT32_C(0x0);
constexpr std::uint32_t GPIO_OTYPER_OFFSET       = UINT32_C(0x4);
constexpr std::uint32_t GPIO_OSPEEDR_OFFSET      = UINT32_C(0x8);
constexpr std::uint32_t GPIO_PUPDR_OFFSET        = UINT32_C(0xC);
constexpr std::uint32_t GPIO_IDR_OFFSET          = UINT32_C(0x10);
constexpr std::uint32_t GPIO_ODR_OFFSET          = UINT32_C(0x14);
constexpr std::uint32_t GPIO_BSRR_OFFSET         = UINT32_C(0x18);
constexpr std::uint32_t GPIO_LCKR_OFFSET         = UINT32_C(0x1C);
constexpr std::uint32_t GPIO_AFRL_OFFSET         = UINT32_C(0x20);
constexpr std::uint32_t GPIO_AFRH_OFFSET         = UINT32_C(0x24);
constexpr std::uint32_t GPIO_BRR_OFFSET          = UINT32_C(0x28);

enum class pins : std::uint8_t {
    pin_00 = 0,
    pin_01 = 1,
    pin_02 = 2,
    pin_03 = 3,
    pin_04 = 4,
    pin_05 = 5,
    pin_06 = 6,
    pin_07 = 7,
    pin_08 = 8,
    pin_09 = 9,
    pin_10 = 10,
    pin_11 = 11,
    pin_12 = 12,
    pin_13 = 13,
    pin_14 = 14,
    pin_15 = 15
};

template <pins pin>
concept is_valid_pin = (
    (pin == pins::pin_00) ||
    (pin == pins::pin_01) ||
    (pin == pins::pin_02) ||
    (pin == pins::pin_03) ||
    (pin == pins::pin_04) ||
    (pin == pins::pin_05) ||
    (pin == pins::pin_06) ||
    (pin == pins::pin_07) ||
    (pin == pins::pin_08) ||
    (pin == pins::pin_09) ||
    (pin == pins::pin_10) ||
    (pin == pins::pin_11) ||
    (pin == pins::pin_12) ||
    (pin == pins::pin_13) ||
    (pin == pins::pin_14) ||
    (pin == pins::pin_15)
);

template <pins pin>
concept is_valid_low_pin = (
    (pin == pins::pin_00) ||
    (pin == pins::pin_01) ||
    (pin == pins::pin_02) ||
    (pin == pins::pin_03) ||
    (pin == pins::pin_04) ||
    (pin == pins::pin_05) ||
    (pin == pins::pin_06) ||
    (pin == pins::pin_07)
);

template <pins pin>
concept is_valid_high_pin = (
    (pin == pins::pin_08) ||
    (pin == pins::pin_09) ||
    (pin == pins::pin_10) ||
    (pin == pins::pin_11) ||
    (pin == pins::pin_12) ||
    (pin == pins::pin_13) ||
    (pin == pins::pin_14) ||
    (pin == pins::pin_15)
);
// GPIO port mode register
constexpr std::uint32_t GPIO_MODER_MODER15_MSK    = UINT32_C(0b11000000000000000000000000000000);
constexpr std::uint32_t GPIO_MODER_MODER15_POS    = UINT32_C(30);
constexpr std::uint32_t GPIO_MODER_MODER14_MSK    = UINT32_C(0b00110000000000000000000000000000);
constexpr std::uint32_t GPIO_MODER_MODER14_POS    = UINT32_C(28);
constexpr std::uint32_t GPIO_MODER_MODER13_MSK    = UINT32_C(0b00001100000000000000000000000000);
constexpr std::uint32_t GPIO_MODER_MODER13_POS    = UINT32_C(26);
constexpr std::uint32_t GPIO_MODER_MODER12_MSK    = UINT32_C(0b00000011000000000000000000000000);
constexpr std::uint32_t GPIO_MODER_MODER12_POS    = UINT32_C(24);
constexpr std::uint32_t GPIO_MODER_MODER11_MSK    = UINT32_C(0b00000000110000000000000000000000);
constexpr std::uint32_t GPIO_MODER_MODER11_POS    = UINT32_C(22);
constexpr std::uint32_t GPIO_MODER_MODER10_MSK    = UINT32_C(0b00000000001100000000000000000000);
constexpr std::uint32_t GPIO_MODER_MODER10_POS    = UINT32_C(20);
constexpr std::uint32_t GPIO_MODER_MODER9_MSK     = UINT32_C(0b00000000000011000000000000000000);
constexpr std::uint32_t GPIO_MODER_MODER9_POS     = UINT32_C(18);
constexpr std::uint32_t GPIO_MODER_MODER8_MSK     = UINT32_C(0b00000000000000110000000000000000);
constexpr std::uint32_t GPIO_MODER_MODER8_POS     = UINT32_C(16);
constexpr std::uint32_t GPIO_MODER_MODER7_MSK     = UINT32_C(0b00000000000000001100000000000000);
constexpr std::uint32_t GPIO_MODER_MODER7_POS     = UINT32_C(14);
constexpr std::uint32_t GPIO_MODER_MODER6_MSK     = UINT32_C(0b00000000000000000011000000000000);
constexpr std::uint32_t GPIO_MODER_MODER6_POS     = UINT32_C(12);
constexpr std::uint32_t GPIO_MODER_MODER5_MSK     = UINT32_C(0b00000000000000000000110000000000);
constexpr std::uint32_t GPIO_MODER_MODER5_POS     = UINT32_C(10);
constexpr std::uint32_t GPIO_MODER_MODER4_MSK     = UINT32_C(0b00000000000000000000001100000000);
constexpr std::uint32_t GPIO_MODER_MODER4_POS     = UINT32_C(8);
constexpr std::uint32_t GPIO_MODER_MODER3_MSK     = UINT32_C(0b00000000000000000000000011000000);
constexpr std::uint32_t GPIO_MODER_MODER3_POS     = UINT32_C(6);
constexpr std::uint32_t GPIO_MODER_MODER2_MSK     = UINT32_C(0b00000000000000000000000000110000);
constexpr std::uint32_t GPIO_MODER_MODER2_POS     = UINT32_C(4);
constexpr std::uint32_t GPIO_MODER_MODER1_MSK     = UINT32_C(0b00000000000000000000000000001100);
constexpr std::uint32_t GPIO_MODER_MODER1_POS     = UINT32_C(2);
constexpr std::uint32_t GPIO_MODER_MODER0_MSK     = UINT32_C(0b00000000000000000000000000000011);
constexpr std::uint32_t GPIO_MODER_MODER0_POS     = UINT32_C(0);
// GPIO port output type register
constexpr std::uint32_t GPIO_OTYPER_OT15_MSK       = UINT32_C(0b00000000000000001000000000000000);
constexpr std::uint32_t GPIO_OTYPER_OT15_POS       = UINT32_C(15);
constexpr std::uint32_t GPIO_OTYPER_OT14_MSK       = UINT32_C(0b00000000000000000100000000000000);
constexpr std::uint32_t GPIO_OTYPER_OT14_POS       = UINT32_C(14);
constexpr std::uint32_t GPIO_OTYPER_OT13_MSK       = UINT32_C(0b00000000000000000010000000000000);
constexpr std::uint32_t GPIO_OTYPER_OT13_POS       = UINT32_C(13);
constexpr std::uint32_t GPIO_OTYPER_OT12_MSK       = UINT32_C(0b00000000000000000001000000000000);
constexpr std::uint32_t GPIO_OTYPER_OT12_POS       = UINT32_C(12);
constexpr std::uint32_t GPIO_OTYPER_OT11_MSK       = UINT32_C(0b00000000000000000000100000000000);
constexpr std::uint32_t GPIO_OTYPER_OT11_POS       = UINT32_C(11);
constexpr std::uint32_t GPIO_OTYPER_OT10_MSK       = UINT32_C(0b00000000000000000000010000000000);
constexpr std::uint32_t GPIO_OTYPER_OT10_POS       = UINT32_C(10);
constexpr std::uint32_t GPIO_OTYPER_OT9_MSK        = UINT32_C(0b00000000000000000000001000000000);
constexpr std::uint32_t GPIO_OTYPER_OT9_POS        = UINT32_C(9);
constexpr std::uint32_t GPIO_OTYPER_OT8_MSK        = UINT32_C(0b00000000000000000000000100000000);
constexpr std::uint32_t GPIO_OTYPER_OT8_POS        = UINT32_C(8);
constexpr std::uint32_t GPIO_OTYPER_OT7_MSK        = UINT32_C(0b00000000000000000000000010000000);
constexpr std::uint32_t GPIO_OTYPER_OT7_POS        = UINT32_C(7);
constexpr std::uint32_t GPIO_OTYPER_OT6_MSK        = UINT32_C(0b00000000000000000000000001000000);
constexpr std::uint32_t GPIO_OTYPER_OT6_POS        = UINT32_C(6);
constexpr std::uint32_t GPIO_OTYPER_OT5_MSK        = UINT32_C(0b00000000000000000000000000100000);
constexpr std::uint32_t GPIO_OTYPER_OT5_POS        = UINT32_C(5);
constexpr std::uint32_t GPIO_OTYPER_OT4_MSK        = UINT32_C(0b00000000000000000000000000010000);
constexpr std::uint32_t GPIO_OTYPER_OT4_POS        = UINT32_C(4);
constexpr std::uint32_t GPIO_OTYPER_OT3_MSK        = UINT32_C(0b00000000000000000000000000001000);
constexpr std::uint32_t GPIO_OTYPER_OT3_POS        = UINT32_C(3);
constexpr std::uint32_t GPIO_OTYPER_OT2_MSK        = UINT32_C(0b00000000000000000000000000000100);
constexpr std::uint32_t GPIO_OTYPER_OT2_POS        = UINT32_C(2);
constexpr std::uint32_t GPIO_OTYPER_OT1_MSK        = UINT32_C(0b00000000000000000000000000000010);
constexpr std::uint32_t GPIO_OTYPER_OT1_POS        = UINT32_C(1);
constexpr std::uint32_t GPIO_OTYPER_OT0_MSK        = UINT32_C(0b00000000000000000000000000000001);
constexpr std::uint32_t GPIO_OTYPER_OT0_POS        = UINT32_C(0);
// GPIO port output speed register
constexpr std::uint32_t GPIO_OSPEEDR_OSPEEDR15_MSK  = UINT32_C(0b11000000000000000000000000000000);
constexpr std::uint32_t GPIO_OSPEEDR_OSPEEDR15_POS  = UINT32_C(30);
constexpr std::uint32_t GPIO_OSPEEDR_OSPEEDR14_MSK  = UINT32_C(0b00110000000000000000000000000000);
constexpr std::uint32_t GPIO_OSPEEDR_OSPEEDR14_POS  = UINT32_C(28);
constexpr std::uint32_t GPIO_OSPEEDR_OSPEEDR13_MSK  = UINT32_C(0b00001100000000000000000000000000);
constexpr std::uint32_t GPIO_OSPEEDR_OSPEEDR13_POS  = UINT32_C(26);
constexpr std::uint32_t GPIO_OSPEEDR_OSPEEDR12_MSK  = UINT32_C(0b00000011000000000000000000000000);
constexpr std::uint32_t GPIO_OSPEEDR_OSPEEDR12_POS  = UINT32_C(24);
constexpr std::uint32_t GPIO_OSPEEDR_OSPEEDR11_MSK  = UINT32_C(0b00000000110000000000000000000000);
constexpr std::uint32_t GPIO_OSPEEDR_OSPEEDR11_POS  = UINT32_C(22);
constexpr std::uint32_t GPIO_OSPEEDR_OSPEEDR10_MSK  = UINT32_C(0b00000000001100000000000000000000);
constexpr std::uint32_t GPIO_OSPEEDR_OSPEEDR10_POS  = UINT32_C(20);
constexpr std::uint32_t GPIO_OSPEEDR_OSPEEDR9_MSK   = UINT32_C(0b00000000000011000000000000000000);
constexpr std::uint32_t GPIO_OSPEEDR_OSPEEDR9_POS   = UINT32_C(18);
constexpr std::uint32_t GPIO_OSPEEDR_OSPEEDR8_MSK   = UINT32_C(0b00000000000000110000000000000000);
constexpr std::uint32_t GPIO_OSPEEDR_OSPEEDR8_POS   = UINT32_C(16);
constexpr std::uint32_t GPIO_OSPEEDR_OSPEEDR7_MSK   = UINT32_C(0b00000000000000001100000000000000);
constexpr std::uint32_t GPIO_OSPEEDR_OSPEEDR7_POS   = UINT32_C(14);
constexpr std::uint32_t GPIO_OSPEEDR_OSPEEDR6_MSK   = UINT32_C(0b00000000000000000011000000000000);
constexpr std::uint32_t GPIO_OSPEEDR_OSPEEDR6_POS   = UINT32_C(12);
constexpr std::uint32_t GPIO_OSPEEDR_OSPEEDR5_MSK   = UINT32_C(0b00000000000000000000110000000000);
constexpr std::uint32_t GPIO_OSPEEDR_OSPEEDR5_POS   = UINT32_C(10);
constexpr std::uint32_t GPIO_OSPEEDR_OSPEEDR4_MSK   = UINT32_C(0b00000000000000000000001100000000);
constexpr std::uint32_t GPIO_OSPEEDR_OSPEEDR4_POS   = UINT32_C(8);
constexpr std::uint32_t GPIO_OSPEEDR_OSPEEDR3_MSK   = UINT32_C(0b00000000000000000000000011000000);
constexpr std::uint32_t GPIO_OSPEEDR_OSPEEDR3_POS   = UINT32_C(6);
constexpr std::uint32_t GPIO_OSPEEDR_OSPEEDR2_MSK   = UINT32_C(0b00000000000000000000000000110000);
constexpr std::uint32_t GPIO_OSPEEDR_OSPEEDR2_POS   = UINT32_C(4);
constexpr std::uint32_t GPIO_OSPEEDR_OSPEEDR1_MSK   = UINT32_C(0b00000000000000000000000000001100);
constexpr std::uint32_t GPIO_OSPEEDR_OSPEEDR1_POS   = UINT32_C(2);
constexpr std::uint32_t GPIO_OSPEEDR_OSPEEDR0_MSK   = UINT32_C(0b00000000000000000000000000000011);
constexpr std::uint32_t GPIO_OSPEEDR_OSPEEDR0_POS   = UINT32_C(0);
// GPIO port pull-up/pull-down register
constexpr std::uint32_t GPIO_PUPDR_PUPDR15_MSK    = UINT32_C(0b11000000000000000000000000000000);
constexpr std::uint32_t GPIO_PUPDR_PUPDR15_POS    = UINT32_C(30);
constexpr std::uint32_t GPIO_PUPDR_PUPDR14_MSK    = UINT32_C(0b00110000000000000000000000000000);
constexpr std::uint32_t GPIO_PUPDR_PUPDR14_POS    = UINT32_C(28);
constexpr std::uint32_t GPIO_PUPDR_PUPDR13_MSK    = UINT32_C(0b00001100000000000000000000000000);
constexpr std::uint32_t GPIO_PUPDR_PUPDR13_POS    = UINT32_C(26);
constexpr std::uint32_t GPIO_PUPDR_PUPDR12_MSK    = UINT32_C(0b00000011000000000000000000000000);
constexpr std::uint32_t GPIO_PUPDR_PUPDR12_POS    = UINT32_C(24);
constexpr std::uint32_t GPIO_PUPDR_PUPDR11_MSK    = UINT32_C(0b00000000110000000000000000000000);
constexpr std::uint32_t GPIO_PUPDR_PUPDR11_POS    = UINT32_C(22);
constexpr std::uint32_t GPIO_PUPDR_PUPDR10_MSK    = UINT32_C(0b00000000001100000000000000000000);
constexpr std::uint32_t GPIO_PUPDR_PUPDR10_POS    = UINT32_C(20);
constexpr std::uint32_t GPIO_PUPDR_PUPDR9_MSK     = UINT32_C(0b00000000000011000000000000000000);
constexpr std::uint32_t GPIO_PUPDR_PUPDR9_POS     = UINT32_C(18);
constexpr std::uint32_t GPIO_PUPDR_PUPDR8_MSK     = UINT32_C(0b00000000000000110000000000000000);
constexpr std::uint32_t GPIO_PUPDR_PUPDR8_POS     = UINT32_C(16);
constexpr std::uint32_t GPIO_PUPDR_PUPDR7_MSK     = UINT32_C(0b00000000000000001100000000000000);
constexpr std::uint32_t GPIO_PUPDR_PUPDR7_POS     = UINT32_C(14);
constexpr std::uint32_t GPIO_PUPDR_PUPDR6_MSK     = UINT32_C(0b00000000000000000011000000000000);
constexpr std::uint32_t GPIO_PUPDR_PUPDR6_POS     = UINT32_C(12);
constexpr std::uint32_t GPIO_PUPDR_PUPDR5_MSK     = UINT32_C(0b00000000000000000000110000000000);
constexpr std::uint32_t GPIO_PUPDR_PUPDR5_POS     = UINT32_C(10);
constexpr std::uint32_t GPIO_PUPDR_PUPDR4_MSK     = UINT32_C(0b00000000000000000000001100000000);
constexpr std::uint32_t GPIO_PUPDR_PUPDR4_POS     = UINT32_C(8);
constexpr std::uint32_t GPIO_PUPDR_PUPDR3_MSK     = UINT32_C(0b00000000000000000000000011000000);
constexpr std::uint32_t GPIO_PUPDR_PUPDR3_POS     = UINT32_C(6);
constexpr std::uint32_t GPIO_PUPDR_PUPDR2_MSK     = UINT32_C(0b00000000000000000000000000110000);
constexpr std::uint32_t GPIO_PUPDR_PUPDR2_POS     = UINT32_C(4);
constexpr std::uint32_t GPIO_PUPDR_PUPDR1_MSK     = UINT32_C(0b00000000000000000000000000001100);
constexpr std::uint32_t GPIO_PUPDR_PUPDR1_POS     = UINT32_C(2);
constexpr std::uint32_t GPIO_PUPDR_PUPDR0_MSK     = UINT32_C(0b00000000000000000000000000000011);
constexpr std::uint32_t GPIO_PUPDR_PUPDR0_POS     = UINT32_C(0);
// GPIO port input data register
constexpr std::uint32_t GPIO_IDR_IDR15_MSK      = UINT32_C(0b00000000000000001000000000000000);
constexpr std::uint32_t GPIO_IDR_IDR15_POS      = UINT32_C(15);
constexpr std::uint32_t GPIO_IDR_IDR14_MSK      = UINT32_C(0b00000000000000000100000000000000);
constexpr std::uint32_t GPIO_IDR_IDR14_POS      = UINT32_C(14);
constexpr std::uint32_t GPIO_IDR_IDR13_MSK      = UINT32_C(0b00000000000000000010000000000000);
constexpr std::uint32_t GPIO_IDR_IDR13_POS      = UINT32_C(13);
constexpr std::uint32_t GPIO_IDR_IDR12_MSK      = UINT32_C(0b00000000000000000001000000000000);
constexpr std::uint32_t GPIO_IDR_IDR12_POS      = UINT32_C(12);
constexpr std::uint32_t GPIO_IDR_IDR11_MSK      = UINT32_C(0b00000000000000000000100000000000);
constexpr std::uint32_t GPIO_IDR_IDR11_POS      = UINT32_C(11);
constexpr std::uint32_t GPIO_IDR_IDR10_MSK      = UINT32_C(0b00000000000000000000010000000000);
constexpr std::uint32_t GPIO_IDR_IDR10_POS      = UINT32_C(10);
constexpr std::uint32_t GPIO_IDR_IDR9_MSK       = UINT32_C(0b00000000000000000000001000000000);
constexpr std::uint32_t GPIO_IDR_IDR9_POS       = UINT32_C(9);
constexpr std::uint32_t GPIO_IDR_IDR8_MSK       = UINT32_C(0b00000000000000000000000100000000);
constexpr std::uint32_t GPIO_IDR_IDR8_POS       = UINT32_C(8);
constexpr std::uint32_t GPIO_IDR_IDR7_MSK       = UINT32_C(0b00000000000000000000000010000000);
constexpr std::uint32_t GPIO_IDR_IDR7_POS       = UINT32_C(7);
constexpr std::uint32_t GPIO_IDR_IDR6_MSK       = UINT32_C(0b00000000000000000000000001000000);
constexpr std::uint32_t GPIO_IDR_IDR6_POS       = UINT32_C(6);
constexpr std::uint32_t GPIO_IDR_IDR5_MSK       = UINT32_C(0b00000000000000000000000000100000);
constexpr std::uint32_t GPIO_IDR_IDR5_POS       = UINT32_C(5);
constexpr std::uint32_t GPIO_IDR_IDR4_MSK       = UINT32_C(0b00000000000000000000000000010000);
constexpr std::uint32_t GPIO_IDR_IDR4_POS       = UINT32_C(4);
constexpr std::uint32_t GPIO_IDR_IDR3_MSK       = UINT32_C(0b00000000000000000000000000001000);
constexpr std::uint32_t GPIO_IDR_IDR3_POS       = UINT32_C(3);
constexpr std::uint32_t GPIO_IDR_IDR2_MSK       = UINT32_C(0b00000000000000000000000000000100);
constexpr std::uint32_t GPIO_IDR_IDR2_POS       = UINT32_C(2);
constexpr std::uint32_t GPIO_IDR_IDR1_MSK       = UINT32_C(0b00000000000000000000000000000010);
constexpr std::uint32_t GPIO_IDR_IDR1_POS       = UINT32_C(1);
constexpr std::uint32_t GPIO_IDR_IDR0_MSK       = UINT32_C(0b00000000000000000000000000000001);
constexpr std::uint32_t GPIO_IDR_IDR0_POS       = UINT32_C(0);
// GPIO port output data register
constexpr std::uint32_t GPIO_ODR_ODR15_MSK      = UINT32_C(0b00000000000000001000000000000000);
constexpr std::uint32_t GPIO_ODR_ODR15_POS      = UINT32_C(15);
constexpr std::uint32_t GPIO_ODR_ODR14_MSK      = UINT32_C(0b00000000000000000100000000000000);
constexpr std::uint32_t GPIO_ODR_ODR14_POS      = UINT32_C(14);
constexpr std::uint32_t GPIO_ODR_ODR13_MSK      = UINT32_C(0b00000000000000000010000000000000);
constexpr std::uint32_t GPIO_ODR_ODR13_POS      = UINT32_C(13);
constexpr std::uint32_t GPIO_ODR_ODR12_MSK      = UINT32_C(0b00000000000000000001000000000000);
constexpr std::uint32_t GPIO_ODR_ODR12_POS      = UINT32_C(12);
constexpr std::uint32_t GPIO_ODR_ODR11_MSK      = UINT32_C(0b00000000000000000000100000000000);
constexpr std::uint32_t GPIO_ODR_ODR11_POS      = UINT32_C(11);
constexpr std::uint32_t GPIO_ODR_ODR10_MSK      = UINT32_C(0b00000000000000000000010000000000);
constexpr std::uint32_t GPIO_ODR_ODR10_POS      = UINT32_C(10);
constexpr std::uint32_t GPIO_ODR_ODR9_MSK       = UINT32_C(0b00000000000000000000001000000000);
constexpr std::uint32_t GPIO_ODR_ODR9_POS       = UINT32_C(9);
constexpr std::uint32_t GPIO_ODR_ODR8_MSK       = UINT32_C(0b00000000000000000000000100000000);
constexpr std::uint32_t GPIO_ODR_ODR8_POS       = UINT32_C(8);
constexpr std::uint32_t GPIO_ODR_ODR7_MSK       = UINT32_C(0b00000000000000000000000010000000);
constexpr std::uint32_t GPIO_ODR_ODR7_POS       = UINT32_C(7);
constexpr std::uint32_t GPIO_ODR_ODR6_MSK       = UINT32_C(0b00000000000000000000000001000000);
constexpr std::uint32_t GPIO_ODR_ODR6_POS       = UINT32_C(6);
constexpr std::uint32_t GPIO_ODR_ODR5_MSK       = UINT32_C(0b00000000000000000000000000100000);
constexpr std::uint32_t GPIO_ODR_ODR5_POS       = UINT32_C(5);
constexpr std::uint32_t GPIO_ODR_ODR4_MSK       = UINT32_C(0b00000000000000000000000000010000);
constexpr std::uint32_t GPIO_ODR_ODR4_POS       = UINT32_C(4);
constexpr std::uint32_t GPIO_ODR_ODR3_MSK       = UINT32_C(0b00000000000000000000000000001000);
constexpr std::uint32_t GPIO_ODR_ODR3_POS       = UINT32_C(3);
constexpr std::uint32_t GPIO_ODR_ODR2_MSK       = UINT32_C(0b00000000000000000000000000000100);
constexpr std::uint32_t GPIO_ODR_ODR2_POS       = UINT32_C(2);
constexpr std::uint32_t GPIO_ODR_ODR1_MSK       = UINT32_C(0b00000000000000000000000000000010);
constexpr std::uint32_t GPIO_ODR_ODR1_POS       = UINT32_C(1);
constexpr std::uint32_t GPIO_ODR_ODR0_MSK       = UINT32_C(0b00000000000000000000000000000001);
constexpr std::uint32_t GPIO_ODR_ODR0_POS       = UINT32_C(0);
// GPIO port bit set/reset register
constexpr std::uint32_t GPIO_BSRR_BR15_MSK       = UINT32_C(0b10000000000000000000000000000000);
constexpr std::uint32_t GPIO_BSRR_BR15_POS       = UINT32_C(31);
constexpr std::uint32_t GPIO_BSRR_BR14_MSK       = UINT32_C(0b01000000000000000000000000000000);
constexpr std::uint32_t GPIO_BSRR_BR14_POS       = UINT32_C(30);
constexpr std::uint32_t GPIO_BSRR_BR13_MSK       = UINT32_C(0b00100000000000000000000000000000);
constexpr std::uint32_t GPIO_BSRR_BR13_POS       = UINT32_C(29);
constexpr std::uint32_t GPIO_BSRR_BR12_MSK       = UINT32_C(0b00010000000000000000000000000000);
constexpr std::uint32_t GPIO_BSRR_BR12_POS       = UINT32_C(28);
constexpr std::uint32_t GPIO_BSRR_BR11_MSK       = UINT32_C(0b00001000000000000000000000000000);
constexpr std::uint32_t GPIO_BSRR_BR11_POS       = UINT32_C(27);
constexpr std::uint32_t GPIO_BSRR_BR10_MSK       = UINT32_C(0b00000100000000000000000000000000);
constexpr std::uint32_t GPIO_BSRR_BR10_POS       = UINT32_C(26);
constexpr std::uint32_t GPIO_BSRR_BR9_MSK        = UINT32_C(0b00000010000000000000000000000000);
constexpr std::uint32_t GPIO_BSRR_BR9_POS        = UINT32_C(25);
constexpr std::uint32_t GPIO_BSRR_BR8_MSK        = UINT32_C(0b00000001000000000000000000000000);
constexpr std::uint32_t GPIO_BSRR_BR8_POS        = UINT32_C(24);
constexpr std::uint32_t GPIO_BSRR_BR7_MSK        = UINT32_C(0b00000000100000000000000000000000);
constexpr std::uint32_t GPIO_BSRR_BR7_POS        = UINT32_C(23);
constexpr std::uint32_t GPIO_BSRR_BR6_MSK        = UINT32_C(0b00000000010000000000000000000000);
constexpr std::uint32_t GPIO_BSRR_BR6_POS        = UINT32_C(22);
constexpr std::uint32_t GPIO_BSRR_BR5_MSK        = UINT32_C(0b00000000001000000000000000000000);
constexpr std::uint32_t GPIO_BSRR_BR5_POS        = UINT32_C(21);
constexpr std::uint32_t GPIO_BSRR_BR4_MSK        = UINT32_C(0b00000000000100000000000000000000);
constexpr std::uint32_t GPIO_BSRR_BR4_POS        = UINT32_C(20);
constexpr std::uint32_t GPIO_BSRR_BR3_MSK        = UINT32_C(0b00000000000010000000000000000000);
constexpr std::uint32_t GPIO_BSRR_BR3_POS        = UINT32_C(19);
constexpr std::uint32_t GPIO_BSRR_BR2_MSK        = UINT32_C(0b00000000000001000000000000000000);
constexpr std::uint32_t GPIO_BSRR_BR2_POS        = UINT32_C(18);
constexpr std::uint32_t GPIO_BSRR_BR1_MSK        = UINT32_C(0b00000000000000100000000000000000);
constexpr std::uint32_t GPIO_BSRR_BR1_POS        = UINT32_C(17);
constexpr std::uint32_t GPIO_BSRR_BR0_MSK        = UINT32_C(0b00000000000000010000000000000000);
constexpr std::uint32_t GPIO_BSRR_BR0_POS        = UINT32_C(16);
constexpr std::uint32_t GPIO_BSRR_BS15_MSK       = UINT32_C(0b00000000000000001000000000000000);
constexpr std::uint32_t GPIO_BSRR_BS15_POS       = UINT32_C(15);
constexpr std::uint32_t GPIO_BSRR_BS14_MSK       = UINT32_C(0b00000000000000000100000000000000);
constexpr std::uint32_t GPIO_BSRR_BS14_POS       = UINT32_C(14);
constexpr std::uint32_t GPIO_BSRR_BS13_MSK       = UINT32_C(0b00000000000000000010000000000000);
constexpr std::uint32_t GPIO_BSRR_BS13_POS       = UINT32_C(13);
constexpr std::uint32_t GPIO_BSRR_BS12_MSK       = UINT32_C(0b00000000000000000001000000000000);
constexpr std::uint32_t GPIO_BSRR_BS12_POS       = UINT32_C(12);
constexpr std::uint32_t GPIO_BSRR_BS11_MSK       = UINT32_C(0b00000000000000000000100000000000);
constexpr std::uint32_t GPIO_BSRR_BS11_POS       = UINT32_C(11);
constexpr std::uint32_t GPIO_BSRR_BS10_MSK       = UINT32_C(0b00000000000000000000010000000000);
constexpr std::uint32_t GPIO_BSRR_BS10_POS       = UINT32_C(10);
constexpr std::uint32_t GPIO_BSRR_BS9_MSK        = UINT32_C(0b00000000000000000000001000000000);
constexpr std::uint32_t GPIO_BSRR_BS9_POS        = UINT32_C(9);
constexpr std::uint32_t GPIO_BSRR_BS8_MSK        = UINT32_C(0b00000000000000000000000100000000);
constexpr std::uint32_t GPIO_BSRR_BS8_POS        = UINT32_C(8);
constexpr std::uint32_t GPIO_BSRR_BS7_MSK        = UINT32_C(0b00000000000000000000000010000000);
constexpr std::uint32_t GPIO_BSRR_BS7_POS        = UINT32_C(7);
constexpr std::uint32_t GPIO_BSRR_BS6_MSK        = UINT32_C(0b00000000000000000000000001000000);
constexpr std::uint32_t GPIO_BSRR_BS6_POS        = UINT32_C(6);
constexpr std::uint32_t GPIO_BSRR_BS5_MSK        = UINT32_C(0b00000000000000000000000000100000);
constexpr std::uint32_t GPIO_BSRR_BS5_POS        = UINT32_C(5);
constexpr std::uint32_t GPIO_BSRR_BS4_MSK        = UINT32_C(0b00000000000000000000000000010000);
constexpr std::uint32_t GPIO_BSRR_BS4_POS        = UINT32_C(4);
constexpr std::uint32_t GPIO_BSRR_BS3_MSK        = UINT32_C(0b00000000000000000000000000001000);
constexpr std::uint32_t GPIO_BSRR_BS3_POS        = UINT32_C(3);
constexpr std::uint32_t GPIO_BSRR_BS2_MSK        = UINT32_C(0b00000000000000000000000000000100);
constexpr std::uint32_t GPIO_BSRR_BS2_POS        = UINT32_C(2);
constexpr std::uint32_t GPIO_BSRR_BS1_MSK        = UINT32_C(0b00000000000000000000000000000010);
constexpr std::uint32_t GPIO_BSRR_BS1_POS        = UINT32_C(1);
constexpr std::uint32_t GPIO_BSRR_BS0_MSK        = UINT32_C(0b00000000000000000000000000000001);
constexpr std::uint32_t GPIO_BSRR_BS0_POS        = UINT32_C(0);
// GPIO port configuration lock register
constexpr std::uint32_t GPIO_LCKR_LCKK_MSK       = UINT32_C(0b00000000000000010000000000000000);
constexpr std::uint32_t GPIO_LCKR_LCKK_POS       = UINT32_C(16);
constexpr std::uint32_t GPIO_LCKR_LCK15_MSK      = UINT32_C(0b00000000000000001000000000000000);
constexpr std::uint32_t GPIO_LCKR_LCK15_POS      = UINT32_C(15);
constexpr std::uint32_t GPIO_LCKR_LCK14_MSK      = UINT32_C(0b00000000000000000100000000000000);
constexpr std::uint32_t GPIO_LCKR_LCK14_POS      = UINT32_C(14);
constexpr std::uint32_t GPIO_LCKR_LCK13_MSK      = UINT32_C(0b00000000000000000010000000000000);
constexpr std::uint32_t GPIO_LCKR_LCK13_POS      = UINT32_C(13);
constexpr std::uint32_t GPIO_LCKR_LCK12_MSK      = UINT32_C(0b00000000000000000001000000000000);
constexpr std::uint32_t GPIO_LCKR_LCK12_POS      = UINT32_C(12);
constexpr std::uint32_t GPIO_LCKR_LCK11_MSK      = UINT32_C(0b00000000000000000000100000000000);
constexpr std::uint32_t GPIO_LCKR_LCK11_POS      = UINT32_C(11);
constexpr std::uint32_t GPIO_LCKR_LCK10_MSK      = UINT32_C(0b00000000000000000000010000000000);
constexpr std::uint32_t GPIO_LCKR_LCK10_POS      = UINT32_C(10);
constexpr std::uint32_t GPIO_LCKR_LCK9_MSK       = UINT32_C(0b00000000000000000000001000000000);
constexpr std::uint32_t GPIO_LCKR_LCK9_POS       = UINT32_C(9);
constexpr std::uint32_t GPIO_LCKR_LCK8_MSK       = UINT32_C(0b00000000000000000000000100000000);
constexpr std::uint32_t GPIO_LCKR_LCK8_POS       = UINT32_C(8);
constexpr std::uint32_t GPIO_LCKR_LCK7_MSK       = UINT32_C(0b00000000000000000000000010000000);
constexpr std::uint32_t GPIO_LCKR_LCK7_POS       = UINT32_C(7);
constexpr std::uint32_t GPIO_LCKR_LCK6_MSK       = UINT32_C(0b00000000000000000000000001000000);
constexpr std::uint32_t GPIO_LCKR_LCK6_POS       = UINT32_C(6);
constexpr std::uint32_t GPIO_LCKR_LCK5_MSK       = UINT32_C(0b00000000000000000000000000100000);
constexpr std::uint32_t GPIO_LCKR_LCK5_POS       = UINT32_C(5);
constexpr std::uint32_t GPIO_LCKR_LCK4_MSK       = UINT32_C(0b00000000000000000000000000010000);
constexpr std::uint32_t GPIO_LCKR_LCK4_POS       = UINT32_C(4);
constexpr std::uint32_t GPIO_LCKR_LCK3_MSK       = UINT32_C(0b00000000000000000000000000001000);
constexpr std::uint32_t GPIO_LCKR_LCK3_POS       = UINT32_C(3);
constexpr std::uint32_t GPIO_LCKR_LCK2_MSK       = UINT32_C(0b00000000000000000000000000000100);
constexpr std::uint32_t GPIO_LCKR_LCK2_POS       = UINT32_C(2);
constexpr std::uint32_t GPIO_LCKR_LCK1_MSK       = UINT32_C(0b00000000000000000000000000000010);
constexpr std::uint32_t GPIO_LCKR_LCK1_POS       = UINT32_C(1);
constexpr std::uint32_t GPIO_LCKR_LCK0_MSK       = UINT32_C(0b00000000000000000000000000000001);
constexpr std::uint32_t GPIO_LCKR_LCK0_POS       = UINT32_C(0);
// GPIO alternate function low register
constexpr std::uint32_t GPIO_AFRL_AFRL7_MSK      = UINT32_C(0b11110000000000000000000000000000);
constexpr std::uint32_t GPIO_AFRL_AFRL7_POS      = UINT32_C(28);
constexpr std::uint32_t GPIO_AFRL_AFRL6_MSK      = UINT32_C(0b00001111000000000000000000000000);
constexpr std::uint32_t GPIO_AFRL_AFRL6_POS      = UINT32_C(24);
constexpr std::uint32_t GPIO_AFRL_AFRL5_MSK      = UINT32_C(0b00000000111100000000000000000000);
constexpr std::uint32_t GPIO_AFRL_AFRL5_POS      = UINT32_C(20);
constexpr std::uint32_t GPIO_AFRL_AFRL4_MSK      = UINT32_C(0b00000000000011110000000000000000);
constexpr std::uint32_t GPIO_AFRL_AFRL4_POS      = UINT32_C(16);
constexpr std::uint32_t GPIO_AFRL_AFRL3_MSK      = UINT32_C(0b00000000000000001111000000000000);
constexpr std::uint32_t GPIO_AFRL_AFRL3_POS      = UINT32_C(12);
constexpr std::uint32_t GPIO_AFRL_AFRL2_MSK      = UINT32_C(0b00000000000000000000111100000000);
constexpr std::uint32_t GPIO_AFRL_AFRL2_POS      = UINT32_C(8);
constexpr std::uint32_t GPIO_AFRL_AFRL1_MSK      = UINT32_C(0b00000000000000000000000011110000);
constexpr std::uint32_t GPIO_AFRL_AFRL1_POS      = UINT32_C(4);
constexpr std::uint32_t GPIO_AFRL_AFRL0_MSK      = UINT32_C(0b00000000000000000000000000001111);
constexpr std::uint32_t GPIO_AFRL_AFRL0_POS      = UINT32_C(0);
// GPIO alternate function high register
constexpr std::uint32_t GPIO_AFRH_AFRH15_MSK     = UINT32_C(0b11110000000000000000000000000000);
constexpr std::uint32_t GPIO_AFRH_AFRH15_POS     = UINT32_C(28);
constexpr std::uint32_t GPIO_AFRH_AFRH14_MSK     = UINT32_C(0b00001111000000000000000000000000);
constexpr std::uint32_t GPIO_AFRH_AFRH14_POS     = UINT32_C(24);
constexpr std::uint32_t GPIO_AFRH_AFRH13_MSK     = UINT32_C(0b00000000111100000000000000000000);
constexpr std::uint32_t GPIO_AFRH_AFRH13_POS     = UINT32_C(20);
constexpr std::uint32_t GPIO_AFRH_AFRH12_MSK     = UINT32_C(0b00000000000011110000000000000000);
constexpr std::uint32_t GPIO_AFRH_AFRH12_POS     = UINT32_C(16);
constexpr std::uint32_t GPIO_AFRH_AFRH11_MSK     = UINT32_C(0b00000000000000001111000000000000);
constexpr std::uint32_t GPIO_AFRH_AFRH11_POS     = UINT32_C(12);
constexpr std::uint32_t GPIO_AFRH_AFRH10_MSK     = UINT32_C(0b00000000000000000000111100000000);
constexpr std::uint32_t GPIO_AFRH_AFRH10_POS     = UINT32_C(8);
constexpr std::uint32_t GPIO_AFRH_AFRH9_MSK      = UINT32_C(0b00000000000000000000000011110000);
constexpr std::uint32_t GPIO_AFRH_AFRH9_POS      = UINT32_C(4);
constexpr std::uint32_t GPIO_AFRH_AFRH8_MSK      = UINT32_C(0b00000000000000000000000000001111);
constexpr std::uint32_t GPIO_AFRH_AFRH8_POS      = UINT32_C(0);
// Port bit reset register
constexpr std::uint32_t GPIO_BRR_BR0_MSK        = UINT32_C(0b00000000000000000000000000000001);
constexpr std::uint32_t GPIO_BRR_BR0_POS        = UINT32_C(0);
constexpr std::uint32_t GPIO_BRR_BR1_MSK        = UINT32_C(0b00000000000000000000000000000010);
constexpr std::uint32_t GPIO_BRR_BR1_POS        = UINT32_C(1);
constexpr std::uint32_t GPIO_BRR_BR2_MSK        = UINT32_C(0b00000000000000000000000000000100);
constexpr std::uint32_t GPIO_BRR_BR2_POS        = UINT32_C(2);
constexpr std::uint32_t GPIO_BRR_BR3_MSK        = UINT32_C(0b00000000000000000000000000001000);
constexpr std::uint32_t GPIO_BRR_BR3_POS        = UINT32_C(3);
constexpr std::uint32_t GPIO_BRR_BR4_MSK        = UINT32_C(0b00000000000000000000000000010000);
constexpr std::uint32_t GPIO_BRR_BR4_POS        = UINT32_C(4);
constexpr std::uint32_t GPIO_BRR_BR5_MSK        = UINT32_C(0b00000000000000000000000000100000);
constexpr std::uint32_t GPIO_BRR_BR5_POS        = UINT32_C(5);
constexpr std::uint32_t GPIO_BRR_BR6_MSK        = UINT32_C(0b00000000000000000000000001000000);
constexpr std::uint32_t GPIO_BRR_BR6_POS        = UINT32_C(6);
constexpr std::uint32_t GPIO_BRR_BR7_MSK        = UINT32_C(0b00000000000000000000000010000000);
constexpr std::uint32_t GPIO_BRR_BR7_POS        = UINT32_C(7);
constexpr std::uint32_t GPIO_BRR_BR8_MSK        = UINT32_C(0b00000000000000000000000100000000);
constexpr std::uint32_t GPIO_BRR_BR8_POS        = UINT32_C(8);
constexpr std::uint32_t GPIO_BRR_BR9_MSK        = UINT32_C(0b00000000000000000000001000000000);
constexpr std::uint32_t GPIO_BRR_BR9_POS        = UINT32_C(9);
constexpr std::uint32_t GPIO_BRR_BR10_MSK       = UINT32_C(0b00000000000000000000010000000000);
constexpr std::uint32_t GPIO_BRR_BR10_POS       = UINT32_C(10);
constexpr std::uint32_t GPIO_BRR_BR11_MSK       = UINT32_C(0b00000000000000000000100000000000);
constexpr std::uint32_t GPIO_BRR_BR11_POS       = UINT32_C(11);
constexpr std::uint32_t GPIO_BRR_BR12_MSK       = UINT32_C(0b00000000000000000001000000000000);
constexpr std::uint32_t GPIO_BRR_BR12_POS       = UINT32_C(12);
constexpr std::uint32_t GPIO_BRR_BR13_MSK       = UINT32_C(0b00000000000000000010000000000000);
constexpr std::uint32_t GPIO_BRR_BR13_POS       = UINT32_C(13);
constexpr std::uint32_t GPIO_BRR_BR14_MSK       = UINT32_C(0b00000000000000000100000000000000);
constexpr std::uint32_t GPIO_BRR_BR14_POS       = UINT32_C(14);
constexpr std::uint32_t GPIO_BRR_BR15_MSK       = UINT32_C(0b00000000000000001000000000000000);
constexpr std::uint32_t GPIO_BRR_BR15_POS       = UINT32_C(15);

} /* namespace gpio */
} /* namespace hal */