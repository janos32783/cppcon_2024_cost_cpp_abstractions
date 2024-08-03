#pragma once

#include "hal/common.hpp"

namespace hal {
namespace gpio {

enum class ports : std::uint8_t {
    port_a = 0,
    port_b = 1,
    port_c = 2,
    port_d = 3,
    port_f = 4
};

template <ports port>
concept valid_port = (
    (port == ports::port_f) ||
    (port == ports::port_d) ||
    (port == ports::port_c) ||
    (port == ports::port_b) ||
    (port == ports::port_a)
);

static constexpr GPIO_TypeDef* gpio_vector[] = {GPIOA, GPIOB, GPIOC, GPIOD, GPIOF};

enum class pins : std::uint16_t {
    pin_00 = 0b0000000000000001,
    pin_01 = 0b0000000000000010,
    pin_02 = 0b0000000000000100,
    pin_03 = 0b0000000000001000,
    pin_04 = 0b0000000000010000,
    pin_05 = 0b0000000000100000,
    pin_06 = 0b0000000001000000,
    pin_07 = 0b0000000010000000,
    pin_08 = 0b0000000100000000,
    pin_09 = 0b0000001000000000,
    pin_10 = 0b0000010000000000,
    pin_11 = 0b0000100000000000,
    pin_12 = 0b0001000000000000,
    pin_13 = 0b0010000000000000,
    pin_14 = 0b0100000000000000,
    pin_15 = 0b1000000000000000
};

enum class modes : uint32_t {
    input = GPIO_MODE_INPUT,
    output_pp = GPIO_MODE_OUTPUT_PP,
    output_od = GPIO_MODE_OUTPUT_OD,
    af_pp = GPIO_MODE_AF_PP,
    af_od = GPIO_MODE_AF_OD,
    analog = GPIO_MODE_ANALOG,
    it_rising = GPIO_MODE_IT_RISING,
    it_falling = GPIO_MODE_IT_FALLING,
    it_rising_falling = GPIO_MODE_IT_RISING_FALLING,
    evt_rising = GPIO_MODE_EVT_RISING,
    evt_falling = GPIO_MODE_EVT_FALLING,
    evt_rising_falling = GPIO_MODE_EVT_RISING_FALLING
};

enum class pull_states : uint32_t {
    NO_PULL,
    PULL_UP,
    PULL_DOWN,
};

template <ports m_port>
requires (valid_port<m_port>)
class CPort {
public:
    static inline void init () {
        if constexpr (m_port == ports::port_a) {
            __HAL_RCC_GPIOA_CLK_ENABLE();
        }
        else if constexpr (m_port == ports::port_b) {
            __HAL_RCC_GPIOB_CLK_ENABLE();
        }
        else if constexpr (m_port == ports::port_c) {
            __HAL_RCC_GPIOC_CLK_ENABLE();
        }
        else if constexpr (m_port == ports::port_f) {
            __HAL_RCC_GPIOF_CLK_ENABLE();
        }
    }
    static inline void deinit () {
        if constexpr (m_port == ports::port_a) {
            __HAL_RCC_GPIOA_CLK_DISABLE();
        }
        else if constexpr (m_port == ports::port_b) {
            __HAL_RCC_GPIOB_CLK_DISABLE();
        }
        else if constexpr (m_port == ports::port_c) {
            __HAL_RCC_GPIOC_CLK_DISABLE();
        }
        else if constexpr (m_port == ports::port_f) {
            __HAL_RCC_GPIOF_CLK_DISABLE();
        }
    }
};

class CPin {
private:
    GPIO_TypeDef* m_gpio;
    const pins m_pin;
    typedef std::underlying_type<pins>::type pin_utype;
public:
    CPin () = delete;
    CPin (ports gpio_port, pins pin) : m_pin(pin) {
        m_gpio = gpio_vector[static_cast<std::uint8_t>(gpio_port)];
    }
    ~CPin() = default;
    error_codes set_pin_output() {
        HAL_GPIO_WritePin(m_gpio, static_cast<pin_utype>(m_pin), GPIO_PIN_RESET);
        GPIO_InitTypeDef GPIO_InitStruct;
        GPIO_InitStruct.Pin = static_cast<pin_utype>(m_pin);
        GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
        HAL_GPIO_Init(m_gpio, &GPIO_InitStruct);
        return error_codes::HAL_OK;
    }
    error_codes set_pin_input(const pull_states pull_state) {
        GPIO_InitTypeDef GPIO_InitStruct;
        GPIO_InitStruct.Pin = static_cast<pin_utype>(m_pin);
        GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
        GPIO_InitStruct.Pull = static_cast<std::uint32_t>(pull_state);
        HAL_GPIO_Init(m_gpio, &GPIO_InitStruct);
        return error_codes::HAL_OK;
    }
    error_codes set_pin_value(const bool value) {
        HAL_GPIO_WritePin(m_gpio, static_cast<pin_utype>(m_pin), (GPIO_PinState)value);
        return error_codes::HAL_OK;
    }
    error_codes toggle_pin_value() {
        HAL_GPIO_TogglePin(m_gpio, static_cast<pin_utype>(m_pin));
        return error_codes::HAL_OK;
    }
    bool get_pin_value() const {
        return HAL_GPIO_ReadPin(m_gpio, static_cast<pin_utype>(m_pin));
    }
};

} /* namespace gpio */
} /* namespace hal */