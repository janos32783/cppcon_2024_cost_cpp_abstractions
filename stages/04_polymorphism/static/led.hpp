#pragma once

#include "ipin.hpp"

template <IPin TPin>
class CLed {
private:
    bool m_state { false };
    TPin* m_pin { nullptr };
public:
    CLed () = delete;
    CLed (TPin* pin) : m_pin(pin) {
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