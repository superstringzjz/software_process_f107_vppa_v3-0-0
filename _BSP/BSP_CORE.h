#ifdef  __cplusplus
extern "C" {
#endif

#ifndef __BSP_CORE_H
#define __BSP_CORE_H

#include "stm32f10x.h"
#include "stm32f10x_conf.h"
#include "MSP_Config.h"
#include "BSP_Config.h"
	
bool bsp_core_init(void);
	
#endif
#ifdef  __cplusplus
}  
#endif
