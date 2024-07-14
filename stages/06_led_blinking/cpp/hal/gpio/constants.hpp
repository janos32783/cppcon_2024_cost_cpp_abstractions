#pragma once

#include <cstdint>
#include <concepts>

#include "hal/base/constants.hpp"

namespace hal {

constexpr std::uint32_t GPIOA_BASE_ADDR = AHB2PERIPH_BASE_ADDR + UINT32_C(0x0000);
constexpr std::uint32_t GPIOB_BASE_ADDR = AHB2PERIPH_BASE_ADDR + UINT32_C(0x0400);
constexpr std::uint32_t GPIOC_BASE_ADDR = AHB2PERIPH_BASE_ADDR + UINT32_C(0x0800);
constexpr std::uint32_t GPIOD_BASE_ADDR = AHB2PERIPH_BASE_ADDR + UINT32_C(0x0C00);
constexpr std::uint32_t GPIOF_BASE_ADDR = AHB2PERIPH_BASE_ADDR + UINT32_C(0x1400);

constexpr std::uint32_t MODER_OFFSET   = UINT32_C(0x00);     /* GPIO port mode register,               Address offset: 0x00 */
constexpr std::uint32_t OTYPER_OFFSET  = UINT32_C(0x04);     /* GPIO port output type register,        Address offset: 0x04 */
constexpr std::uint32_t OSPEEDR_OFFSET = UINT32_C(0x08);     /* GPIO port output speed register,       Address offset: 0x08 */
constexpr std::uint32_t PUPDR_OFFSET   = UINT32_C(0x0C);     /* GPIO port pull-up/pull-down register,  Address offset: 0x0C */
constexpr std::uint32_t IDR_OFFSET     = UINT32_C(0x10);     /* GPIO port input data register,         Address offset: 0x10 */
constexpr std::uint32_t ODR_OFFSET     = UINT32_C(0x14);     /* GPIO port output data register,        Address offset: 0x14 */
constexpr std::uint32_t BSRR_OFFSET    = UINT32_C(0x18);     /* GPIO port bit set/reset register,      Address offset: 0x18 */
constexpr std::uint32_t LCKR_OFFSET    = UINT32_C(0x1C);     /* GPIO port configuration lock register, Address offset: 0x1C */
constexpr std::uint32_t AFRL_OFFSET    = UINT32_C(0x20);     /* GPIO alternate function registers,     Address offset: 0x20 */
constexpr std::uint32_t AFRH_OFFSET    = UINT32_C(0x24);     /* GPIO alternate function registers,     Address offset: 0x24 */
constexpr std::uint32_t BRR_OFFSET     = UINT32_C(0x28);     /* GPIO port bit reset registers,         Address offset: 0x28 */

template <std::uint32_t GPIOx_BASE_ADDR>
concept is_valid_gpio_base_address = ((GPIOx_BASE_ADDR == GPIOA_BASE_ADDR) ||
                                      (GPIOx_BASE_ADDR == GPIOB_BASE_ADDR) ||
                                      (GPIOx_BASE_ADDR == GPIOC_BASE_ADDR) ||
                                      (GPIOx_BASE_ADDR == GPIOD_BASE_ADDR) ||
                                      (GPIOx_BASE_ADDR == GPIOF_BASE_ADDR));

enum class gpio_ports : std::uint8_t {
    port_a,
    port_b,
    port_c,
    port_d,
    port_f
};

template <gpio_ports port>
concept is_valid_gpio_port = ((port == gpio_ports::port_a) ||
                              (port == gpio_ports::port_b) ||
                              (port == gpio_ports::port_c) ||
                              (port == gpio_ports::port_d) ||
                              (port == gpio_ports::port_f));

template <gpio_ports port>
requires (is_valid_gpio_port<port>)
consteval std::uint32_t port_to_base_address () {
    if (port == gpio_ports::port_a) return GPIOA_BASE_ADDR;
    else if (port == gpio_ports::port_b) return GPIOB_BASE_ADDR;
    else if (port == gpio_ports::port_c) return GPIOC_BASE_ADDR;
    else if (port == gpio_ports::port_d) return GPIOD_BASE_ADDR;
    else return GPIOF_BASE_ADDR;
}

enum class gpio_pins : std::uint8_t {
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

} /* namespace hal */