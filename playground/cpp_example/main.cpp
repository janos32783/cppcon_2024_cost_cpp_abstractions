#include <type_traits>
#include <concepts>
#include <cstdint>

namespace common {

template <typename T>
concept IDelay = requires (T delay, std::uint32_t val) {
    { delay.sleep_us(val) } -> std::same_as<void>;
    { delay.sleep_ms(val) } -> std::same_as<void>;
};

template <typename T>
concept II2CMaster = requires (T i2c_master, std::uint8_t address, const std::uint8_t* message, std::uint8_t* buffer, std::uint8_t length) {
    { i2c_master.write(address, message, length) } -> std::same_as<bool>;
    { i2c_master.read(address, buffer, length) } -> std::same_as<bool>;
};

} /* namespace common */

namespace osal {

class CFreeRTOSDelay {
public:
    void sleep_us (std::uint32_t us) { /* ... */ }
    void sleep_ms (std::uint32_t ms) { /* ... */ }
};

} /* namespace osal */

namespace hal {

class CStm32Gpio {
};

enum class i2c_modes {
    standard,
    fast,
    fast_plus,
    high_speed
};

class CStm32I2CMaster {
private:
    CStm32Gpio& m_sda;
    CStm32Gpio& m_scl;
public:
    CStm32I2CMaster (i2c_modes mode, CStm32Gpio& sda, CStm32Gpio& scl) : m_sda(sda), m_scl(scl) { /* ... */ }
    bool write (std::uint8_t address, const std::uint8_t* data, std::uint8_t data_length) { /* ... */ return true; }
    bool read (std::uint8_t address, std::uint8_t* buffer, std::uint8_t buffer_length) { /* ... */ return true; }
};

} /* namespace hal */

namespace pal {

template <common::II2CMaster TI2CMaster, common::IDelay TDelay>
class CAirQualitySensor {
private:
    TI2CMaster& m_i2c_master;
    TDelay& m_delay;

    const std::uint8_t m_address = 0x48;
    std::uint8_t m_buffer [10];
public:
    CAirQualitySensor () = delete;
    CAirQualitySensor (TI2CMaster& i2c_master, TDelay& delay) : m_i2c_master(i2c_master), m_delay(delay) {}

    std::uint32_t measure () {
        std::uint32_t result = 0;
        /* fill the buffer with the command */
        /* initiate measurement */
        m_i2c_master.write(m_address, m_buffer, 6);

        m_delay.sleep_us(100);

        /* read the measurement result */
        m_i2c_master.read(m_address, m_buffer, 4);

        /* process the result */

        return result;
    }
};

} /* namespace pal */

namespace hal {
    typedef CStm32I2CMaster CI2CMaster;
}
namespace osal {
    typedef CFreeRTOSDelay CDelay;
}

struct STAirQualityParameter {
    pal::CAirQualitySensor<hal::CI2CMaster, osal::CDelay>* air_quality_sensor { nullptr };
    osal::CDelay* delay { nullptr };
};

void air_quality_task (void* parameter) {
    STAirQualityParameter* param = (STAirQualityParameter*)parameter;
    if (param == nullptr) return;

    pal::CAirQualitySensor<hal::CI2CMaster, osal::CDelay>* air_quality_sensor = param->air_quality_sensor;
    osal::CDelay* delay = param->delay;
    if (air_quality_sensor == nullptr) return;
    if (delay == nullptr) return;

    while (true) {
        /* ... */
        std::uint32_t measurement = air_quality_sensor->measure();
        /* ... */
        delay->sleep_ms(1000);
    }
}

int main (void) {
    osal::CFreeRTOSDelay delay {};

    hal::CStm32Gpio sda {};
    hal::CStm32Gpio scl {};
    hal::CStm32I2CMaster i2c_master { hal::i2c_modes::standard, sda, scl };

    pal::CAirQualitySensor air_quality_sensor { i2c_master, delay };

    STAirQualityParameter param {};
    param.air_quality_sensor = &air_quality_sensor;
    param.delay = &delay;

    air_quality_task((void*)&param);

    //xTaskCreate(air_quality_task, "AIR", STACK_SIZE, (void*)&param, nullptr);
    //vTaskStartScheduler();

    while (true) {
        /* ... */
    }
}