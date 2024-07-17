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

TEST(GpioTest, BitmaskAndValueTest) {
    std::uint32_t bitmask = hal::gpio::bsrr_bitmask<
        hal::gpio::set_reset::set,
        hal::gpio::pins::pin_02,
        hal::gpio::pins::pin_05,
        hal::gpio::pins::pin_06,
        hal::gpio::pins::pin_07,
        hal::gpio::pins::pin_08,
        hal::gpio::pins::pin_09,
        hal::gpio::pins::pin_10,
        hal::gpio::pins::pin_11,
        hal::gpio::pins::pin_14,
        hal::gpio::pins::pin_15
    >();
    print(bitmask);
    bitmask = hal::gpio::bsrr_bitmask<
        hal::gpio::set_reset::reset,
        hal::gpio::pins::pin_02,
        hal::gpio::pins::pin_05,
        hal::gpio::pins::pin_06,
        hal::gpio::pins::pin_07,
        hal::gpio::pins::pin_08,
        hal::gpio::pins::pin_09,
        hal::gpio::pins::pin_10,
        hal::gpio::pins::pin_11,
        hal::gpio::pins::pin_14,
        hal::gpio::pins::pin_15
    >();
    print(bitmask);
    bitmask = hal::gpio::afrh_bitmask<
        hal::gpio::pins::pin_02,
        hal::gpio::pins::pin_05,
        hal::gpio::pins::pin_06,
        hal::gpio::pins::pin_07,
        hal::gpio::pins::pin_08,
        hal::gpio::pins::pin_10,
        hal::gpio::pins::pin_11,
        hal::gpio::pins::pin_14,
        hal::gpio::pins::pin_15
    >();
    print(bitmask);
    bitmask = hal::gpio::afrh_value<
        hal::gpio::alternate_functions::af5,
        hal::gpio::pins::pin_02,
        hal::gpio::pins::pin_05,
        hal::gpio::pins::pin_06,
        hal::gpio::pins::pin_07,
        hal::gpio::pins::pin_08,
        hal::gpio::pins::pin_10,
        hal::gpio::pins::pin_11,
        hal::gpio::pins::pin_14,
        hal::gpio::pins::pin_15
    >();
    print(bitmask);
    bitmask = hal::gpio::afrl_bitmask<
        hal::gpio::pins::pin_02,
        hal::gpio::pins::pin_05,
        hal::gpio::pins::pin_06,
        hal::gpio::pins::pin_07,
        hal::gpio::pins::pin_08,
        hal::gpio::pins::pin_10,
        hal::gpio::pins::pin_11,
        hal::gpio::pins::pin_14,
        hal::gpio::pins::pin_15
    >();
    print(bitmask);
    bitmask = hal::gpio::afrl_value<
        hal::gpio::alternate_functions::af5,
        hal::gpio::pins::pin_02,
        hal::gpio::pins::pin_05,
        hal::gpio::pins::pin_06,
        hal::gpio::pins::pin_07,
        hal::gpio::pins::pin_08,
        hal::gpio::pins::pin_10,
        hal::gpio::pins::pin_11,
        hal::gpio::pins::pin_14,
        hal::gpio::pins::pin_15
    >();
    print(bitmask);
}