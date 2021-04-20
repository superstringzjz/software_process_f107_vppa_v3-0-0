#ifdef  __cplusplus
extern "C" {
#endif

#ifndef __MSP_CORE_CONF_H
#define __MSP_CORE_CONF_H
#include "stm32f10x.h"
#include "stm32f10x_conf.h"
#include "MSP_Config.h"
	
bool MSP_SYSTEM_CLOCK_Init(void);                               //系统时钟设定
bool MSP_DEVICE_CLOCK_Init(void);                               //片上外设时钟开启 
bool MSP_IO_REMAP_Init(void);	
bool MSP_NVIC_PriorityGroupConfig(uint32_t NVIC_PriorityGroup); //系统中断优先级设定
bool MSP_NVIC_Init(void);                                       //系统中断初始化

#endif
#ifdef  __cplusplus
}  
#endif
