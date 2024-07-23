#include <gtest/gtest.h>

#include <string>
#include <iostream>
#include <iomanip>

#include "../hal/gpio/gpio.hpp"

void print (std::uint32_t val) {
    std::cout << "#############################################################################" << std::endl;
    std::ios_base::fmtflags f( std::cout.flags() );
    std::cout << "0x" << std::right << std::hex << std::setw(8) << std::setfill('0') << val << std::endl;
    std::cout.flags(f);
    std::cout << " 31  30  29  28  27  26  25  24  23  22  21  20  19  18  17  16  " << std::endl;
    std::cout << "+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+" << std::endl;
    for (int i = 31; i > 15; --i) {
        std::cout << "| " << ((val & (1 << i)) ? "1" : "0") << " ";
    }
    std::cout << "|" << std::endl;
    std::cout << "+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+" << std::endl;
    for (int i = 15; i >= 0; --i) {
        std::cout << "| " << ((val & (1 << i)) ? "1" : "0") << " ";
    }
    std::cout << "|" << std::endl;
    std::cout << "+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+" << std::endl;
    std::cout << " 15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0  " << std::endl;
    std::cout << "#############################################################################" << std::endl;
}

#define PINS hal::gpio::pins::pin_02, \
             hal::gpio::pins::pin_05, \
             hal::gpio::pins::pin_06, \
             hal::gpio::pins::pin_07, \
             hal::gpio::pins::pin_08, \
             hal::gpio::pins::pin_09, \
             hal::gpio::pins::pin_10, \
             hal::gpio::pins::pin_11, \
             hal::gpio::pins::pin_14, \
             hal::gpio::pins::pin_15

//constexpr std::uint32_t bsrr_set_bitmask = 0b0000'0000'0000'0000'0000'0000'0000'0000;
constexpr std::uint32_t moder_bitmask        = 0b1111'0000'1111'1111'1111'1100'0011'0000;
constexpr std::uint32_t moder_input_value    = 0b0000'0000'0000'0000'0000'0000'0000'0000;
constexpr std::uint32_t moder_output_value   = 0b0101'0000'0101'0101'0101'0100'0001'0000;

constexpr std::uint32_t otyper_bitmask       = 0b0000'0000'0000'0000'1100'1111'1110'0100;
constexpr std::uint32_t otyper_pp_value      = 0b0000'0000'0000'0000'0000'0000'0000'0000;
constexpr std::uint32_t otyper_od_value      = 0b0000'0000'0000'0000'1100'1111'1110'0100;

constexpr std::uint32_t bsrr_set_bitmask     = 0b0000'0000'0000'0000'1100'1111'1110'0100;
constexpr std::uint32_t bsrr_reset_bitmask   = 0b1100'1111'1110'0100'0000'0000'0000'0000;

TEST(GpioTest, BitmaskAndValueTest) {
    std::uint32_t bitmask = 0;

    bitmask = hal::gpio::moder_bitmask<PINS>();
    EXPECT_EQ(bitmask, moder_bitmask);
    bitmask = hal::gpio::moder_value<hal::gpio::modes::input, PINS>();
    EXPECT_EQ(bitmask, moder_input_value);
    bitmask = hal::gpio::moder_value<hal::gpio::modes::output, PINS>();
    EXPECT_EQ(bitmask, moder_output_value);

    bitmask = hal::gpio::otyper_bitmask<PINS>();
    EXPECT_EQ(bitmask, otyper_bitmask);
    bitmask = hal::gpio::otyper_value<hal::gpio::output_types::push_pull, PINS>();
    EXPECT_EQ(bitmask, otyper_pp_value);
    bitmask = hal::gpio::otyper_value<hal::gpio::output_types::open_drain, PINS>();
    EXPECT_EQ(bitmask, otyper_od_value);

    bitmask = hal::gpio::bsrr_bitmask<hal::gpio::set_reset::set, PINS>();
    EXPECT_EQ(bitmask, bsrr_set_bitmask);
    bitmask = hal::gpio::bsrr_bitmask<hal::gpio::set_reset::reset, PINS>();
    EXPECT_EQ(bitmask, bsrr_reset_bitmask);

    bitmask = hal::gpio::afrh_bitmask<PINS>();
    bitmask = hal::gpio::afrh_value<hal::gpio::alternate_functions::af5, PINS>();
    bitmask = hal::gpio::afrl_bitmask<PINS>();
    bitmask = hal::gpio::afrl_value<hal::gpio::alternate_functions::af5, PINS>();
}