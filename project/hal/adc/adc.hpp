#pragma once

#include "hal/adc/constants.hpp"
#include "hal/gpio/gpio.hpp"
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
    states m_state { states::reset };
    error_codes m_error_code { error_codes::none };
    bool m_locked { false };
public:
    template <AdcInitConfig conf>
    requires (is_valid_adc_init_conf<conf>)
    inline hal_error init () {
        hal_error ret = hal_error::ok;
        if (m_state == states::reset) {
            m_error_code = error_codes::none;
            m_locked = false;
            GPIO_InitTypeDef GPIO_InitStruct = {0};
            if(hadc->Instance==ADC1)
            {
            /* USER CODE BEGIN ADC1_MspInit 0 */

            /* USER CODE END ADC1_MspInit 0 */
                /* Peripheral clock enable */
                __HAL_RCC_ADC1_CLK_ENABLE();

                __HAL_RCC_GPIOA_CLK_ENABLE();
                /**ADC GPIO Configuration
                PA6     ------> ADC_IN6
                PA7     ------> ADC_IN7
                */
                GPIO_InitStruct.Pin = GPIO_PIN_6|GPIO_PIN_7;
                GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
                GPIO_InitStruct.Pull = GPIO_NOPULL;
                HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

            /* USER CODE BEGIN ADC1_MspInit 1 */

            /* USER CODE END ADC1_MspInit 1 */
            }

        }
  
  /* As prerequisite, into HAL_ADC_MspInit(), ADC clock must be configured    */
  /* at RCC top level depending on both possible clock sources:               */
  /* APB clock or HSI clock.                                                  */
  /* Refer to header of this file for more details on clock enabling procedure*/
  
  /* Actions performed only if ADC is coming from state reset:                */
  /* - Initialization of ADC MSP                                              */
  /* - ADC voltage regulator enable                                           */
  if (hadc->State == HAL_ADC_STATE_RESET)
  {
    /* Initialize ADC error code */
    ADC_CLEAR_ERRORCODE(hadc);
    
    /* Allocate lock resource and initialize it */
    hadc->Lock = HAL_UNLOCKED;
    
    /* Init the low level hardware */
    HAL_ADC_MspInit(hadc);
  }
  
  /* Configuration of ADC parameters if previous preliminary actions are      */ 
  /* correctly completed.                                                     */
  /* and if there is no conversion on going on regular group (ADC can be      */ 
  /* enabled anyway, in case of call of this function to update a parameter   */
  /* on the fly).                                                             */
  if (HAL_IS_BIT_CLR(hadc->State, HAL_ADC_STATE_ERROR_INTERNAL) &&
      (tmp_hal_status == HAL_OK)                                &&
      (ADC_IS_CONVERSION_ONGOING_REGULAR(hadc) == RESET)          )
  {
    /* Set ADC state */
    ADC_STATE_CLR_SET(hadc->State,
                      HAL_ADC_STATE_REG_BUSY,
                      HAL_ADC_STATE_BUSY_INTERNAL);
    
    /* Parameters update conditioned to ADC state:                            */
    /* Parameters that can be updated only when ADC is disabled:              */
    /*  - ADC clock mode                                                      */
    /*  - ADC clock prescaler                                                 */
    /*  - ADC resolution                                                      */
    if (ADC_IS_ENABLE(hadc) == RESET)
    {
      /* Some parameters of this register are not reset, since they are set   */
      /* by other functions and must be kept in case of usage of this         */
      /* function on the fly (update of a parameter of ADC_InitTypeDef        */
      /* without needing to reconfigure all other ADC groups/channels         */
      /* parameters):                                                         */
      /*   - internal measurement paths: Vbat, temperature sensor, Vref       */
      /*     (set into HAL_ADC_ConfigChannel() )                              */
     
      /* Configuration of ADC resolution                                      */
      MODIFY_REG(hadc->Instance->CFGR1,
                 ADC_CFGR1_RES        ,
                 hadc->Init.Resolution );
      
      /* Configuration of ADC clock mode: clock source AHB or HSI with        */
      /* selectable prescaler                                                 */
      MODIFY_REG(hadc->Instance->CFGR2    ,
                 ADC_CFGR2_CKMODE         ,
                 hadc->Init.ClockPrescaler );
    }
      
    /* Configuration of ADC:                                                  */
    /*  - discontinuous mode                                                  */
    /*  - LowPowerAutoWait mode                                               */
    /*  - LowPowerAutoPowerOff mode                                           */
    /*  - continuous conversion mode                                          */
    /*  - overrun                                                             */
    /*  - external trigger to start conversion                                */
    /*  - external trigger polarity                                           */
    /*  - data alignment                                                      */
    /*  - resolution                                                          */
    /*  - scan direction                                                      */
    /*  - DMA continuous request                                              */
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
    
    /* Enable discontinuous mode only if continuous mode is disabled */
    if (hadc->Init.DiscontinuousConvMode == ENABLE)
    {
      if (hadc->Init.ContinuousConvMode == DISABLE)
      {
        /* Enable the selected ADC group regular discontinuous mode */
        tmpCFGR1 |= ADC_CFGR1_DISCEN;
      }
      else
      {
        /* ADC regular group discontinuous was intended to be enabled,        */
        /* but ADC regular group modes continuous and sequencer discontinuous */
        /* cannot be enabled simultaneously.                                  */
        
        /* Update ADC state machine to error */
        SET_BIT(hadc->State, HAL_ADC_STATE_ERROR_CONFIG);
        
        /* Set ADC error code to ADC IP internal error */
        SET_BIT(hadc->ErrorCode, HAL_ADC_ERROR_INTERNAL);
      }
    }
    
    /* Enable external trigger if trigger selection is different of software  */
    /* start.                                                                 */
    /* Note: This configuration keeps the hardware feature of parameter       */
    /*       ExternalTrigConvEdge "trigger edge none" equivalent to           */
    /*       software start.                                                  */
    if (hadc->Init.ExternalTrigConv != ADC_SOFTWARE_START)
    {
      tmpCFGR1 |= ( hadc->Init.ExternalTrigConv    |
                    hadc->Init.ExternalTrigConvEdge );
    }
    
    /* Update ADC configuration register with previous settings */
    hadc->Instance->CFGR1 |= tmpCFGR1;
    
    /* Channel sampling time configuration */
    /* Management of parameters "SamplingTimeCommon" and "SamplingTime"       */
    /* (obsolete): sampling time set in this function if parameter            */
    /*  "SamplingTimeCommon" has been set to a valid sampling time.           */
    /* Otherwise, sampling time is set into ADC channel initialization        */
    /* structure with parameter "SamplingTime" (obsolete).                    */
    if (IS_ADC_SAMPLE_TIME(hadc->Init.SamplingTimeCommon))
    {
      /* Channel sampling time configuration */
      /* Clear the old sample time */
      hadc->Instance->SMPR &= ~(ADC_SMPR_SMP);
      
      /* Set the new sample time */
      hadc->Instance->SMPR |= ADC_SMPR_SET(hadc->Init.SamplingTimeCommon);
    }
    
    /* Check back that ADC registers have effectively been configured to      */
    /* ensure of no potential problem of ADC core IP clocking.                */
    /* Check through register CFGR1 (excluding analog watchdog configuration: */
    /* set into separate dedicated function, and bits of ADC resolution set   */
    /* out of temporary variable 'tmpCFGR1').                                 */
    if ((hadc->Instance->CFGR1 & ~(ADC_CFGR1_AWDCH | ADC_CFGR1_AWDEN | ADC_CFGR1_AWDSGL | ADC_CFGR1_RES))
         == tmpCFGR1)
    {
      /* Set ADC error code to none */
      ADC_CLEAR_ERRORCODE(hadc);
      
      /* Set the ADC state */
      ADC_STATE_CLR_SET(hadc->State,
                        HAL_ADC_STATE_BUSY_INTERNAL,
                        HAL_ADC_STATE_READY);
    }
    else
    {
      /* Update ADC state machine to error */
      ADC_STATE_CLR_SET(hadc->State,
                        HAL_ADC_STATE_BUSY_INTERNAL,
                        HAL_ADC_STATE_ERROR_INTERNAL);
      
      /* Set ADC error code to ADC IP internal error */
      SET_BIT(hadc->ErrorCode, HAL_ADC_ERROR_INTERNAL);
      
      tmp_hal_status = HAL_ERROR;
    }
  
  }
  else
  {
    /* Update ADC state machine to error */
    SET_BIT(hadc->State, HAL_ADC_STATE_ERROR_INTERNAL);
        
    tmp_hal_status = HAL_ERROR;
  }
  
  /* Return function status */
  return tmp_hal_status;
    }
};

} /* namespace adc */
} /* namespace hal */