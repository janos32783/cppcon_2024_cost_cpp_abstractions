#pragma once

#include "ipin.hpp"

class CLed {
private:
    bool m_state { false };
    IPin* m_gpio { nullptr };
public:
    CLed () = delete;
    CLed (IPin* gpio) : m_gpio(gpio) {
        m_gpio->reset();
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