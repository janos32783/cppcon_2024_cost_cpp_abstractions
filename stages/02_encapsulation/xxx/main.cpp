#include <cstdint>
#include <concepts>
#include <type_traits>

#include "gpio.hpp"

static inline void init_gpio () {
    constexpr GpioInitConfig gpio_init {
        .mode = modes::output,
        .output_type = output_types::push_pull,
        .speed = speeds::low,
        .pull_type = pull_types::none
    };
    CPort<ports::port_c>::configure_pins<gpio_init, pins::pin_06>();
}

int main (void) {
    init_gpio();

    while (true) { /* ... */ }
}
