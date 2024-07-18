#pragma once

#include "hal/adc/constants.hpp"
#include "hal/gpio/gpio.hpp"
#include "hal/rcc/rcc.hpp"
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
    static inline states m_state { states::reset };
    static inline error_codes m_error_code { error_codes::none };
    static inline bool m_locked { false };
public:
    template <AdcInitConfig conf, gpio::ports port, gpio::pins... pin>
    requires (is_valid_adc_init_conf<conf> && gpio::is_valid_port<port> && gpio::are_valid_pins<pin...>)
    static inline hal_error init () {
        hal_error ret = hal_error::ok;
        if (m_state == states::reset) {
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



        return ret;
  
    /*
  if (HAL_IS_BIT_CLR(hadc->State, HAL_ADC_STATE_ERROR_INTERNAL) &&
      (tmp_hal_status == HAL_OK)                                &&
      (ADC_IS_CONVERSION_ONGOING_REGULAR(hadc) == RESET)          )
  {
    ADC_STATE_CLR_SET(hadc->State,
                      HAL_ADC_STATE_REG_BUSY,
                      HAL_ADC_STATE_BUSY_INTERNAL);
    
    if (ADC_IS_ENABLE(hadc) == RESET)
    {
      MODIFY_REG(hadc->Instance->CFGR1,
                 ADC_CFGR1_RES        ,
                 hadc->Init.Resolution );
      
      MODIFY_REG(hadc->Instance->CFGR2    ,
                 ADC_CFGR2_CKMODE         ,
                 hadc->Init.ClockPrescaler );
    }
      
    hadc->Instance->CFGR1 &= ~( ADC_CFGR1_DISCEN  |
                                ADC_CFGR1_AUTOFF  |
                                ADC_CFGR1_AUTDLY  |
                                ADC_CFGR1_CONT    |
                                ADC_CFGR1_OVRMOD  |
                                ADC_CFGR1_EXTSEL  |
                                ADC_CFGR1_EXTEN   |
                                ADC_CFGR1_ALIGN   |
                                ADC_CFGR1_SCANDIR |
                                ADC_CFGR1_DMACFG   );

    tmpCFGR1 |= (ADC_CFGR1_AUTOWAIT((uint32_t)hadc->Init.LowPowerAutoWait)        |
                 ADC_CFGR1_AUTOOFF((uint32_t)hadc->Init.LowPowerAutoPowerOff)     |
                 ADC_CFGR1_CONTINUOUS((uint32_t)hadc->Init.ContinuousConvMode)    |
                 ADC_CFGR1_OVERRUN(hadc->Init.Overrun)                            |
                 hadc->Init.DataAlign                                             |
                 ADC_SCANDIR(hadc->Init.ScanConvMode)                             |
                 ADC_CFGR1_DMACONTREQ((uint32_t)hadc->Init.DMAContinuousRequests)  );
    
    if (hadc->Init.DiscontinuousConvMode == ENABLE)
    {
      if (hadc->Init.ContinuousConvMode == DISABLE)
      {
        tmpCFGR1 |= ADC_CFGR1_DISCEN;
      }
      else
      {
        SET_BIT(hadc->State, HAL_ADC_STATE_ERROR_CONFIG);
        
        SET_BIT(hadc->ErrorCode, HAL_ADC_ERROR_INTERNAL);
      }
    }
    
    if (hadc->Init.ExternalTrigConv != ADC_SOFTWARE_START)
    {
      tmpCFGR1 |= ( hadc->Init.ExternalTrigConv    |
                    hadc->Init.ExternalTrigConvEdge );
    }
    
    hadc->Instance->CFGR1 |= tmpCFGR1;
    
    if (IS_ADC_SAMPLE_TIME(hadc->Init.SamplingTimeCommon))
    {
      hadc->Instance->SMPR &= ~(ADC_SMPR_SMP);
      
      hadc->Instance->SMPR |= ADC_SMPR_SET(hadc->Init.SamplingTimeCommon);
    }
    
    if ((hadc->Instance->CFGR1 & ~(ADC_CFGR1_AWDCH | ADC_CFGR1_AWDEN | ADC_CFGR1_AWDSGL | ADC_CFGR1_RES))
         == tmpCFGR1)
    {
      ADC_CLEAR_ERRORCODE(hadc);
      
      ADC_STATE_CLR_SET(hadc->State,
                        HAL_ADC_STATE_BUSY_INTERNAL,
                        HAL_ADC_STATE_READY);
    }
    else
    {
      ADC_STATE_CLR_SET(hadc->State,
                        HAL_ADC_STATE_BUSY_INTERNAL,
                        HAL_ADC_STATE_ERROR_INTERNAL);
      
      SET_BIT(hadc->ErrorCode, HAL_ADC_ERROR_INTERNAL);
      
      tmp_hal_status = HAL_ERROR;
    }
  
  }
  else
  {
    SET_BIT(hadc->State, HAL_ADC_STATE_ERROR_INTERNAL);
        
    tmp_hal_status = HAL_ERROR;
  }
  
  return tmp_hal_status;*/
    }
};

} /* namespace adc */
} /* namespace hal */