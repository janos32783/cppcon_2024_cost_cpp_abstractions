#pragma once

#include "ipin.hpp"

class CLed {
private:
    bool m_state { false };
    IPin* m_pin { nullptr };
public:
    CLed () = delete;
    CLed (IPin* pin) : m_pin(pin) {
        m_pin->reset();
    }

    void turn_on () {
        m_state = true;
        m_pin->set();
    }

    void turn_off () {
        m_state = false;
        m_pin->reset();
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