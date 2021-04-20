#ifdef  __cplusplus
extern "C" {
#endif
	
#ifndef __BSP_ADC_H
#define __BSP_ADC_H
#include "MSP_ADC_Config.h"

bool bsp_adc_init(void);
bool bsp_adc_parameter_init(void);
u16 bsp_adc_1_get_channel6(void);
u16 bsp_adc_1_get_channel7(void);
u16 bsp_adc_1_get_channel(u8 channel);

#endif
#ifdef  __cplusplus
}  
#endif
