#pragma once

#include "hal/adc/constants.hpp"
#include "hal/gpio/gpio.hpp"
#include "hal/rcc/rcc.hpp"
#include "hal/systick/systick.hpp"
#include "hal/register.hpp"
#include "hal/common.hpp"

namespace hal {
namespace adc {

template <adc_instances instance>
requires (is_valid_adc_instance<instance>)
class CAdc {
private:
    static inline ADC_TypeDef* m_adc { reinterpret_cast<ADC_TypeDef*>(instance_to_base_address<instance>()) };
    static inline ADC_Common_TypeDef* m_adc_common { reinterpret_cast<ADC_Common_TypeDef*>(ADC_BASE) };
    static inline AdcState m_state {};
    static inline error_codes m_error_code { error_codes::none };
    static inline bool m_locked { false };
    static inline bool m_low_power_auto_off_enabled { false };

    static inline bool is_enabled () {
        if (CRegister::is_set(&m_adc->CR, ADC_CR_ADEN)) {
            if (CRegister::is_cleared(&m_adc->CR, ADC_CR_ADDIS)) {
                if (CRegister::is_set(&m_adc->ISR, ADC_ISR_ADRDY)) {
                    return true;
                }
                if (CRegister::is_set(&m_adc->CFGR1, ADC_CFGR1_AUTOFF)) {
                    return true;
                }
            }
        }
        return false;
    }

    static inline bool can_be_enabled () {
        return CRegister::is_cleared(&m_adc->CR, ADC_CR_ADCAL | ADC_CR_ADSTP | ADC_CR_ADSTART | ADC_CR_ADDIS | ADC_CR_ADEN);
    }

    template <AdcInitConfig conf>
    static consteval std::uint32_t calculate_cfgr1_set_bits () {
        std::uint32_t cfgr1_set_bits = 0;
        if constexpr (conf.low_power_auto_wait_enabled) { cfgr1_set_bits |= ADC_CFGR1_WAIT; }
        if constexpr (conf.low_power_auto_power_off_enabled) { cfgr1_set_bits |= ADC_CFGR1_AUTOFF; }
        if constexpr (conf.conversion_mode == conversion_modes::continuous) { cfgr1_set_bits |= ADC_CFGR1_CONT; }
        if constexpr (conf.conversion_mode == conversion_modes::discontinuous) { cfgr1_set_bits |= ADC_CFGR1_DISCEN; }
        if constexpr (conf.overrun_behavior == overrun_behaviors::overwrite) { cfgr1_set_bits |= ADC_CFGR1_OVRMOD; }
        if constexpr (conf.data_alignment == data_alignments::left) { cfgr1_set_bits |= ADC_CFGR1_ALIGN; }
        if constexpr (conf.scan_direction == scan_directions::backward) { cfgr1_set_bits |= ADC_CFGR1_SCANDIR; }
        if constexpr (conf.dma_continuous_request_enabled) { cfgr1_set_bits |= ADC_CFGR1_DMACFG; }
        if constexpr (conf.external_trigger != external_triggers::software) {
            cfgr1_set_bits |= static_cast<std::uint32_t>(conf.external_trigger);
            cfgr1_set_bits |= static_cast<std::uint32_t>(conf.external_trigger_edge);
        }
        return cfgr1_set_bits;
    }

    static consteval std::uint32_t get_cfgr1_clear_bitmask () {
        return ADC_CFGR1_DISCEN  |
               ADC_CFGR1_AUTOFF  |
               ADC_CFGR1_AUTDLY  |
               ADC_CFGR1_CONT    |
               ADC_CFGR1_OVRMOD  |
               ADC_CFGR1_EXTSEL  |
               ADC_CFGR1_EXTEN   |
               ADC_CFGR1_ALIGN   |
               ADC_CFGR1_SCANDIR |
               ADC_CFGR1_DMACFG;
    }

    static inline bool is_conversion_ongoing () {
        return CRegister::is_cleared(&m_adc->CR, ADC_CR_ADSTART);
    }
public:
    template <AdcInitConfig conf, gpio::ports port, gpio::pins... pin>
    requires (is_valid_adc_init_conf<conf> && gpio::is_valid_port<port> && gpio::are_valid_pins<pin...>)
    static inline hal_error init () {
        hal_error ret = hal_error::ok;
        if (m_state.reset) {
            m_error_code = error_codes::none;
            m_locked = false;
            rcc::CRcc::enable_adc_clock<adc_instances::adc1>();
            rcc::CRcc::enable_gpio_clock<port>();
            constexpr gpio::GpioInitConfig gpio_conf {
                .mode = gpio::modes::analog,
                .output_type = gpio::output_types::push_pull,
                .speed = gpio::speeds::low,
                .pull_type = gpio::pull_types::none,
                .alternate_function = gpio::alternate_functions::af0
            };
            gpio::CPort<port>::template configure_pins<gpio_conf, pin...>();
        }
        if (!m_state.internal_error && CRegister::is_cleared(&m_adc->CR, ADC_CR_ADSTART)) {
            m_state.busy = false;
            m_state.busy_internal = false;
            if (!is_enabled()) {
                CRegister::set(&m_adc->CFGR1, static_cast<std::uint32_t>(conf.resolution), ADC_CFGR1_RES);
                CRegister::set(&m_adc->CFGR2, static_cast<std::uint32_t>(conf.clock_prescaler), ADC_CFGR2_CKMODE);
            }
            CRegister::set(&m_adc->CFGR1, calculate_cfgr1_set_bits<conf>(), get_cfgr1_clear_bitmask());
            CRegister::set(&m_adc->SMPR, static_cast<std::uint32_t>(conf.sample_time_cycle), ADC_SMPR_SMP);
            m_low_power_auto_off_enabled = conf.low_power_auto_power_off_enabled;
            std::uint32_t cfgr1_val = CRegister::get(&m_adc->CFGR1);
            cfgr1_val &= ~(ADC_CFGR1_AWDCH | ADC_CFGR1_AWDEN | ADC_CFGR1_AWDSGL | ADC_CFGR1_RES);
            if (cfgr1_val == calculate_cfgr1_set_bits<conf>()) {
                m_error_code = error_codes::none;
                m_state.busy_internal = false;
                m_state.ready = true;
            }
            else {
                m_state.busy_internal = false;
                m_state.internal_error = true;
                m_error_code = error_codes::internal_error;
                ret = hal_error::error;
            }
        }
        else {
            m_state.internal_error = true;
            ret = hal_error::error;
        }
        return ret;
    }

    template <channels channel>
    requires (is_valid_channel<channel>)
    static inline hal_error select_channel () {
        hal_error ret = hal_error::ok;
        if (m_locked) {
            ret = hal_error::busy;
        }
        else {
            m_locked = true;
            if (!is_conversion_ongoing()) {
                CRegister::clear_bits(&m_adc->CHSELR, ADC_CHSELR_CHSEL);
                CRegister::set_bits(&m_adc->CHSELR, static_cast<std::uint32_t>(channel));
            }
            else {
                m_state.config_error = true;
                ret = hal_error::error;
            }
            m_locked = false;
        }
        return ret;
    }

    static inline hal_error enable () {
        if (!is_enabled()) {
            if (!can_be_enabled()) {
                m_state.internal_error = true;
                m_error_code = error_codes::internal_error;
                return hal_error::error;
            }
            CRegister::set_bits(&m_adc->CR, ADC_CR_ADEN);
            systick::CSysTick::delay_us(stable_adc_delay_us);
            auto tickstart = systick::CSysTick::now();
            while (CRegister::is_cleared(&m_adc->ISR, ADC_FLAG_RDY)) {
                if ((systick::CSysTick::now() - tickstart) > enable_timeout_ms) {
                    if (CRegister::is_cleared(&m_adc->ISR, ADC_FLAG_RDY)) {
                        m_state.internal_error = true;
                        m_error_code = error_codes::internal_error;
                        return hal_error::error;
                    }
                }
            }
        }
        return hal_error::ok;
    }

    static inline hal_error start () {
        hal_error ret = hal_error::ok;
        if (!is_conversion_ongoing()) {
            if (m_locked) {
                ret = hal_error::busy;
            }
            else {
                m_locked = true;
                if (!m_low_power_auto_off_enabled) {
                    ret = enable();
                }
                if (ret == hal_error::ok) {
                    m_state.ready = false;
                    m_state.end_of_conversion = false;
                    m_state.overrun = false;
                    m_state.end_of_sampling = false;
                    m_state.busy = true;
                    m_error_code = error_codes::none;
                    m_locked = false;
                    CRegister::set_bits(&m_adc->ISR, ADC_FLAG_EOC | ADC_FLAG_EOS | ADC_FLAG_OVR);
                    CRegister::set_bits(&m_adc->CR, ADC_CR_ADSTART);
                }
            }
        }
        else {
            ret = hal_error::busy;
        }
        return ret;
    }
};

} /* namespace adc */
} /* namespace hal */