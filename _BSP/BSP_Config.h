#ifdef  __cplusplus
extern "C" {
#endif

#ifndef __BSP_H
#define __BSP_H

#define REG   bool
#define REG8  u8
#define REG16 u16
	
#include "stm32f10x.h"
#include "stm32f10x_conf.h"
#include "MSP_Config.h"
	
#include "BSP_CORE.h"
#include "BSP_TIM.h"
#include "BSP_IO_OSLED.h"

#include "BSP_IO_ELECTRONIC.h"
#include "BSP_IO_MECHANICAL.h"
#include "BSP_DAC.h"
#include "BSP_USART.h"

#endif
#ifdef  __cplusplus
}  
#endif
