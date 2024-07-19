#pragma once

#include "hal/common.hpp"

namespace hal {
namespace adc {

enum class adc_instances {
    adc1
};

template <adc_instances adc>
concept is_valid_adc_instance = (
    adc == adc_instances::adc1
);

template <adc_instances adc>
requires (is_valid_adc_instance<adc>)
consteval std::uint32_t instance_to_base_address () {
    if (adc == adc_instances::adc1) { return ADC1_BASE; }
}

// adc clock prescaler
enum class clock_prescalers : std::uint32_t {
    async_div_1 = 0x00000000U,
    sync_div_2 = ADC_CFGR2_CKMODE_0,
    sync_div_4 = ADC_CFGR2_CKMODE_1
};

template <clock_prescalers presc>
concept is_valid_clock_prescaler = (
    (presc == clock_prescalers::async_div_1) ||
    (presc == clock_prescalers::sync_div_2) ||
    (presc == clock_prescalers::sync_div_4)
);

// adc resolution
enum class resolutions : std::uint32_t {
    res_12_bit = 0x00000000U,
    res_10_bit = ADC_CFGR1_RES_0,
    res_8_bit = ADC_CFGR1_RES_1,
    res_6_bit = ADC_CFGR1_RES
};

template <resolutions res>
concept is_valid_resolution = (
    (res == resolutions::res_12_bit) ||
    (res == resolutions::res_10_bit) ||
    (res == resolutions::res_8_bit) ||
    (res == resolutions::res_6_bit)
);

// data alignment
enum class data_alignments {
    right,
    left
};

template <data_alignments align>
concept is_valid_data_alignment = (
    (align == data_alignments::right) ||
    (align == data_alignments::left)
);

// scan direction
enum class scan_directions {
    forward,
    backward
};

template <scan_directions dir>
concept is_valid_scan_direction = (
    (dir == scan_directions::forward) ||
    (dir == scan_directions::backward)
);

// eoc selection
enum class eoc_selections {
    single,
    sequential
};

template <eoc_selections eoc>
concept is_valid_eoc_selection = (
    (eoc == eoc_selections::single) ||
    (eoc == eoc_selections::sequential)
);

// conversion mode
enum class conversion_modes {
    continuous,
    discontinuous
};

template <conversion_modes conv>
concept is_valid_conversion_mode = (
    (conv == conversion_modes::continuous) ||
    (conv == conversion_modes::discontinuous)
);

// external trigger
enum class external_triggers : std::uint32_t {
    t1_trgo = 0x00000000U,
    t1_cc4 = ADC_CFGR1_EXTSEL_0,
    t3_trgo = ADC_CFGR1_EXTSEL_1 | ADC_CFGR1_EXTSEL_0,
    software = ADC_CFGR1_EXTSEL + 1U,
    t15_trgo = ADC_CFGR1_EXTSEL_2
};

template <external_triggers trigger>
concept is_valid_external_trigger = (
    (trigger == external_triggers::t1_trgo) ||
    (trigger == external_triggers::t1_cc4) ||
    (trigger == external_triggers::t3_trgo) ||
    (trigger == external_triggers::software) ||
    (trigger == external_triggers::t15_trgo)
);

// external trigger edge
enum class external_trigger_edges : std::uint32_t {
    none = 0x00000000U,
    rising = ADC_CFGR1_EXTEN_0,
    falling = ADC_CFGR1_EXTEN_1,
    rising_falling = ADC_CFGR1_EXTEN
};

template <external_trigger_edges edge>
concept is_valid_external_trigger_edge = (
    (edge == external_trigger_edges::none) ||
    (edge == external_trigger_edges::rising) ||
    (edge == external_trigger_edges::falling) ||
    (edge == external_trigger_edges::rising_falling)
);

// overrun_behaviors
enum class overrun_behaviors {
    overwrite,
    preserve
};

template <overrun_behaviors overrun>
concept is_valid_overrun_behavior = (
    (overrun == overrun_behaviors::overwrite) ||
    (overrun == overrun_behaviors::preserve)
);

// sample time
enum class sample_time_cycles : std::uint32_t {
    cycles_1_5 = 0x00000000U,
    cycles_7_5 = ADC_SMPR_SMP_0,
    cycles_13_5 = ADC_SMPR_SMP_1,
    cycles_28_5 = ADC_SMPR_SMP_1 | ADC_SMPR_SMP_0,
    cycles_41_5 = ADC_SMPR_SMP_2,
    cycles_55_5 = ADC_SMPR_SMP_2 | ADC_SMPR_SMP_0,
    cycles_71_5 = ADC_SMPR_SMP_2 | ADC_SMPR_SMP_1,
    cycles_239_5 = ADC_SMPR_SMP
};

template <sample_time_cycles cycle>
concept is_valid_sample_time_cycle = (
    (cycle == sample_time_cycles::cycles_1_5) ||
    (cycle == sample_time_cycles::cycles_7_5) ||
    (cycle == sample_time_cycles::cycles_13_5) ||
    (cycle == sample_time_cycles::cycles_28_5) ||
    (cycle == sample_time_cycles::cycles_41_5) ||
    (cycle == sample_time_cycles::cycles_55_5) ||
    (cycle == sample_time_cycles::cycles_71_5) ||
    (cycle == sample_time_cycles::cycles_239_5)
);

// config struct

struct AdcInitConfig {
    clock_prescalers clock_prescaler { clock_prescalers::async_div_1 };
    resolutions resolution { resolutions::res_12_bit };
    data_alignments data_alignment { data_alignments::right };
    scan_directions scan_direction { scan_directions::forward };
    eoc_selections eoc_selection { eoc_selections::single };
    bool low_power_auto_wait_enabled { false };
    bool low_power_auto_power_off_enabled { false };
    conversion_modes conversion_mode { conversion_modes::continuous };
    external_triggers external_trigger { external_triggers::t1_trgo };
    external_trigger_edges external_trigger_edge { external_trigger_edges::none };
    bool dma_continuous_request_enabled { false };
    overrun_behaviors overrun_behavior { overrun_behaviors::overwrite };
    sample_time_cycles sample_time_cycle { sample_time_cycles::cycles_1_5 };
};

template <AdcInitConfig conf>
concept is_valid_adc_init_conf = (
    is_valid_clock_prescaler<conf.clock_prescaler> &&
    is_valid_resolution<conf.resolution> &&
    is_valid_data_alignment<conf.data_alignment> &&
    is_valid_scan_direction<conf.scan_direction> &&
    is_valid_eoc_selection<conf.eoc_selection> &&
    is_valid_conversion_mode<conf.conversion_mode> &&
    is_valid_external_trigger<conf.external_trigger> &&
    is_valid_external_trigger_edge<conf.external_trigger_edge> &&
    is_valid_overrun_behavior<conf.overrun_behavior> &&
    is_valid_sample_time_cycle<conf.sample_time_cycle>
);

// states

struct AdcState {
    bool reset { true };
    bool ready { false };
    bool busy_internal { false };
    bool timeout { false };
    bool internal_error { false };
    bool config_error { false };
    bool dma_error { false };
    bool busy { false };
    bool end_of_conversion { false };
    bool overrun { false };
    bool end_of_sampling { false };
    bool inj_busy { false };
    bool inj_end_of_conversion { false };
    bool inj_queue_overflow { false };
    bool watchdog_1 { false };
    bool watchdog_2 { false };
    bool watchdog_3 { false };
    bool multimode_slave { false };
};

/*
enum class states {
    reset,
    ready,
    busy_internal,
    timeout,
    internal_error,
    config_error,
    dma_error,
    busy,
    end_of_conversion,
    overrun,
    end_of_sampling,
    inj_busy,
    inj_end_of_conversion,
    inj_queue_overflow,
    watchdog_1,
    watchdog_2,
    watchdog_3,
    multimode_slave
};
*/

// errors

enum class error_codes {
    none,
    internal_error,
    overrun_error,
    dma_error
};

} /* namespace adc */
} /* namespace hal */