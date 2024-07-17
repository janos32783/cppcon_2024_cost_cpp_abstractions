#pragma once

#include "hal/adc/constants.hpp"
#include "hal/register.hpp"
#include "hal/common.hpp"

namespace hal {
namespace adc {

template <adc_instances instance>
requires (is_valid_adc_instance<instance>)
class CAdc {
private:
    ADC_TypeDef* m_adc { reinterpret_cast<ADC_TypeDef*>(instance_to_base_address<instance>()) };
    ADC_Common_TypeDef* m_adc_common { reinterpret_cast<ADC_Common_TypeDef*>(ADC_BASE) };
public:
    template <modes mode>
    requires (is_valid_mode<mode>)
    inline bool configure () const {
        //CRegister::set(&m_gpio->MODER, moder_value<pin, mode>(), moder_bitmask<pin>());
        //rcc::CAhbEnRegister ahb_en_register {};

        //ahb_en_register.enable_gpio_clock<port>();
        //reset();

        return true;
    }

    inline void set () const {
        CRegister::set_bits(&m_gpio->BSRR, bsrr_bitmask<set_reset::set, pin>());
    }

    inline void reset () const {
        CRegister::set_bits(&m_gpio->BSRR, bsrr_bitmask<set_reset::reset, pin>());
    }

    inline void write (bool level) const {
        if (level) {
            set();
        }
        else {
            reset();
        }
    }
};

} /* namespace adc */
} /* namespace hal */