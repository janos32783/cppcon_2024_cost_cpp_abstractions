#include <cstdint>
#include "main.h"
#include <stdio.h>
#include <string.h>

#include "hal/hal.hpp"
#include "drv/led.hpp"

ADC_HandleTypeDef hadc;
TIM_HandleTypeDef htim1;
TIM_HandleTypeDef htim3;
UART_HandleTypeDef huart2;

void error_handler();
void init_gpio ();
void init_adc ();
static void MX_TIM1_Init(void);
static void MX_TIM3_Init(void);
static void MX_USART2_UART_Init(void);

constexpr std::uint32_t HSE_FREQ = 16000000; // 16MHz external oscillator

constexpr hal::systick::SystickConfig systick_config {
    .prio = 0,
    .core_clock_freq = hal::rcc::HSI_FREQ,
    .systick_freq = hal::systick::tick_frequencies::freq_1kHz
};

constexpr hal::rcc::OscInitConfig oscillator_config {
    .hse_state = hal::rcc::hse_states::on,
    .lse_state = hal::rcc::lse_states::noconf,
    .hsi_state = hal::rcc::hsi_states::noconf,
    .hsi_calib_value = hal::rcc::hsi_calibration_default,
    .hsi14_state = hal::rcc::hsi14_states::on,
    .hsi14_calib_value = 16,
    .lsi_state = hal::rcc::lsi_states::noconf,
    .pll = {
        .pll_state = hal::rcc::pll_states::noconf,
        .pll_source = hal::rcc::pll_sources::hsi,
        .pll_mul = hal::rcc::pll_mul_factors::mul2,
        .pll_div = hal::rcc::pll_prediv_factors::div1
    }
};

constexpr hal::rcc::ClkInitConfig clock_config {
    .is_sysclk = true,
    .is_hclk = true,
    .is_pclk1 = true,
    .system_clock_source = hal::rcc::system_clock_sources::hsi,
    .ahb_clk_div = hal::rcc::ahb_clk_dividers::div1,
    .hclk_div = hal::rcc::hclk_dividers::div1
};

constexpr std::uint32_t flash_latency { 0 };

void delay (int cycles) {
    volatile int i;
    for (i = 0; i < cycles;) { i = i + 1; }
}

GPIO_TypeDef* ports [8] = { GPIOB, GPIOB, GPIOB, GPIOB, GPIOB, GPIOA, GPIOA, GPIOA };
uint16_t pins [8] = { GPIO_PIN_5, GPIO_PIN_6, GPIO_PIN_7, GPIO_PIN_8, GPIO_PIN_9, GPIO_PIN_0, GPIO_PIN_1, GPIO_PIN_4 };
void set_leds (uint32_t val) {
	for (int i = 0; i < 8; ++i) {
		if (val >= (0x000000ff / 8) * (i + 1)) {
			HAL_GPIO_WritePin(ports[i], pins[i], GPIO_PIN_SET);
		}
		else {
			HAL_GPIO_WritePin(ports[i], pins[i], GPIO_PIN_RESET);
		}
	}
}
void select_adc_channel(uint32_t channel) {
    ADC_ChannelConfTypeDef sConfig = {0};
    sConfig.Channel = channel;
    sConfig.Rank = ADC_RANK_CHANNEL_NUMBER;
    sConfig.SamplingTime = ADC_SAMPLETIME_1CYCLE_5;
    if (HAL_ADC_ConfigChannel(&hadc, &sConfig) != HAL_OK) {
        Error_Handler();
    }
}

using ADC_1 = hal::adc::CAdc<hal::adc::adc_instances::adc1>;

int main (void) {
    if (hal::init<systick_config, oscillator_config, clock_config, flash_latency, HSE_FREQ>() != hal::hal_error::ok) {
        error_handler();
    }
    init_gpio();
    init_adc();
    MX_TIM1_Init();
    MX_TIM3_Init();
    MX_USART2_UART_Init();

    hal::gpio::CPin<hal::gpio::ports::port_c, hal::gpio::pins::pin_13> gpio {};
    //gpio.configure<hal::gpio::modes::output>();

    drv::CLed<decltype(gpio)> led { &gpio };

    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
    while (1)
    {
        __HAL_TIM_SET_COUNTER(&htim1, 0);
        HAL_TIM_Base_Start(&htim1);

        // hal::adc::CAdc adc1;

        ADC1->CHSELR = 0b0000000001000000;
        select_adc_channel(ADC_CHANNEL_6);
        HAL_ADC_Start(&hadc);
        HAL_ADC_PollForConversion(&hadc, HAL_MAX_DELAY);
        uint32_t raw6 = HAL_ADC_GetValue(&hadc);
        set_leds(raw6);
        HAL_ADC_Stop(&hadc);

        HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);

        ADC1->CHSELR = 0b0000000010000000;
        select_adc_channel(ADC_CHANNEL_7);
        HAL_ADC_Start(&hadc);
        HAL_ADC_PollForConversion(&hadc, HAL_MAX_DELAY);
        uint32_t raw7 = HAL_ADC_GetValue(&hadc);
        TIM3->CCR1 = (uint32_t)((float)0xffffffff * ((float)raw7 / 255.0f));
        HAL_ADC_Stop(&hadc);

        HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);

        HAL_TIM_Base_Stop(&htim1);
        uint32_t time_taken = __HAL_TIM_GET_COUNTER(&htim1);
        char msg[50] = {0};
        snprintf(msg, sizeof(msg), "Time taken: %lu ticks\r\n", time_taken);
        HAL_UART_Transmit(&huart2, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);

        HAL_Delay(1000);

        led.toggle();
        delay(200000);
    }
}

void init_gpio () {
    hal::rcc::CRcc::enable_gpio_clock<hal::gpio::ports::port_a>();
    hal::rcc::CRcc::enable_gpio_clock<hal::gpio::ports::port_b>();
    hal::rcc::CRcc::enable_gpio_clock<hal::gpio::ports::port_c>();

    hal::gpio::CPort<hal::gpio::ports::port_a>::reset<
        hal::gpio::pins::pin_00,
        hal::gpio::pins::pin_01,
        hal::gpio::pins::pin_04,
        hal::gpio::pins::pin_08,
        hal::gpio::pins::pin_09,
        hal::gpio::pins::pin_10,
        hal::gpio::pins::pin_11,
        hal::gpio::pins::pin_12
    >();

    hal::gpio::CPort<hal::gpio::ports::port_b>::reset<
        hal::gpio::pins::pin_02,
        hal::gpio::pins::pin_05,
        hal::gpio::pins::pin_06,
        hal::gpio::pins::pin_07,
        hal::gpio::pins::pin_08,
        hal::gpio::pins::pin_09,
        hal::gpio::pins::pin_10,
        hal::gpio::pins::pin_11,
        hal::gpio::pins::pin_12,
        hal::gpio::pins::pin_13,
        hal::gpio::pins::pin_14,
        hal::gpio::pins::pin_15
    >();

    hal::gpio::CPort<hal::gpio::ports::port_a>::reset<hal::gpio::pins::pin_13>();

    constexpr hal::gpio::GpioInitConfig gpio_init {
        .mode = hal::gpio::modes::output,
        .output_type = hal::gpio::output_types::push_pull,
        .speed = hal::gpio::speeds::low,
        .pull_type = hal::gpio::pull_types::none
    };

    hal::gpio::CPort<hal::gpio::ports::port_a>::configure_pins<gpio_init, 
        hal::gpio::pins::pin_00,
        hal::gpio::pins::pin_01,
        hal::gpio::pins::pin_04,
        hal::gpio::pins::pin_08,
        hal::gpio::pins::pin_09,
        hal::gpio::pins::pin_10,
        hal::gpio::pins::pin_11,
        hal::gpio::pins::pin_12
    >();

    hal::gpio::CPort<hal::gpio::ports::port_b>::configure_pins<gpio_init, 
        hal::gpio::pins::pin_02,
        hal::gpio::pins::pin_05,
        hal::gpio::pins::pin_06,
        hal::gpio::pins::pin_07,
        hal::gpio::pins::pin_08,
        hal::gpio::pins::pin_09,
        hal::gpio::pins::pin_10,
        hal::gpio::pins::pin_11,
        hal::gpio::pins::pin_12,
        hal::gpio::pins::pin_13,
        hal::gpio::pins::pin_14,
        hal::gpio::pins::pin_15,
        hal::gpio::pins::pin_12
    >();

    hal::gpio::CPort<hal::gpio::ports::port_c>::configure_pins<gpio_init, hal::gpio::pins::pin_13>();
}

void init_adc () {
    constexpr hal::adc::AdcInitConfig conf {
        .clock_prescaler = hal::adc::clock_prescalers::async_div_1,
        .resolution = hal::adc::resolutions::res_8_bit,
        .data_alignment = hal::adc::data_alignments::right,
        .scan_direction = hal::adc::scan_directions::forward,
        .eoc_selection = hal::adc::eoc_selections::single,
        .low_power_auto_wait_enabled = false,
        .low_power_auto_power_off_enabled = false,
        .conversion_mode = hal::adc::conversion_modes::continuous,
        .external_trigger = hal::adc::external_triggers::software,
        .external_trigger_edge = hal::adc::external_trigger_edges::none,
        .dma_continuous_request_enabled = false,
        .overrun_behavior = hal::adc::overrun_behaviors::preserve,
        .sample_time_cycle = hal::adc::sample_time_cycles::cycles_1_5
    };
    ADC_1::init<conf, hal::gpio::ports::port_a, hal::gpio::pins::pin_06, hal::gpio::pins::pin_07>();
}

static void MX_TIM1_Init(void)
{
    TIM_ClockConfigTypeDef sClockSourceConfig = {0};
    TIM_MasterConfigTypeDef sMasterConfig = {0};

    htim1.Instance = TIM1;
    htim1.Init.Prescaler = 0;
    htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
    htim1.Init.Period = 65535;
    htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    htim1.Init.RepetitionCounter = 0;
    htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
    if (HAL_TIM_Base_Init(&htim1) != HAL_OK)
    {
        Error_Handler();
    }
    sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
    if (HAL_TIM_ConfigClockSource(&htim1, &sClockSourceConfig) != HAL_OK)
    {
        Error_Handler();
    }
    sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
    sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
    if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
    {
        Error_Handler();
    }
}

static void MX_TIM3_Init(void)
{
    TIM_ClockConfigTypeDef sClockSourceConfig = {0};
    TIM_MasterConfigTypeDef sMasterConfig = {0};
    TIM_OC_InitTypeDef sConfigOC = {0};

    htim3.Instance = TIM3;
    htim3.Init.Prescaler = 0;
    htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
    htim3.Init.Period = 65535;
    htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
    if (HAL_TIM_Base_Init(&htim3) != HAL_OK)
    {
        Error_Handler();
    }
    sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
    if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK)
    {
        Error_Handler();
    }
    if (HAL_TIM_PWM_Init(&htim3) != HAL_OK)
    {
        Error_Handler();
    }
    sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
    sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
    if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
    {
        Error_Handler();
    }
    sConfigOC.OCMode = TIM_OCMODE_PWM1;
    sConfigOC.Pulse = 0;
    sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
    sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
    if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
    {
        Error_Handler();
    }
    HAL_TIM_MspPostInit(&htim3);
}

static void MX_USART2_UART_Init(void)
{
    huart2.Instance = USART2;
    huart2.Init.BaudRate = 115200;
    huart2.Init.WordLength = UART_WORDLENGTH_8B;
    huart2.Init.StopBits = UART_STOPBITS_1;
    huart2.Init.Parity = UART_PARITY_NONE;
    huart2.Init.Mode = UART_MODE_TX_RX;
    huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    huart2.Init.OverSampling = UART_OVERSAMPLING_16;
    huart2.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
    huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
    if (HAL_UART_Init(&huart2) != HAL_OK)
    {
        Error_Handler();
    }
}

void error_handler() {
    __disable_irq();
    while (true) {
    }
}

void Error_Handler(void) {
    __disable_irq();
    while (1) {
    }
}