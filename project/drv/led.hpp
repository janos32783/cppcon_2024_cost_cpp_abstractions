#pragma once

#include "intf/gpio.hpp"

namespace drv {

template <intf::GPIO TGpio>
class CLed {
private:
    bool m_state { false };
    TGpio* m_gpio { nullptr };
public:
    CLed () = delete;
    CLed (TGpio* gpio) : m_gpio(gpio) {
        m_gpio->configure();
    }

    void turn_on () {
        m_state = true;
        m_gpio->set();
    }

    void turn_off () {
        m_state = false;
        m_gpio->reset();
    }

    void toggle () {
        if (m_state) {
            turn_off();
        }
        else {
            turn_on();
        }
    }
};

} /* namespace drv */