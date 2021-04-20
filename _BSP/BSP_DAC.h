#ifdef  __cplusplus
extern "C" {
#endif
#ifndef __BSP_DAC_H
#define __BSP_DAC_H
#include "stm32f10x.h"
#include "stm32f10x_conf.h"
#include "MSP_Config.h"
#include "BSP_Config.h"

bool bsp_dac_init(void);
bool bsp_dac_parameter_init(void);

bool bsp_dac_channel1_output(u16 val);
bool bsp_dac_channel2_output(u16 val);

#endif
#ifdef  __cplusplus
}  
#endif
