#ifdef  __cplusplus
extern "C" {
#endif

#ifndef __MSP_CORE_CONF_H
#define __MSP_CORE_CONF_H
#include "stm32f10x.h"
#include "stm32f10x_conf.h"
#include "MSP_Config.h"
	
bool MSP_SYSTEM_CLOCK_Init(void);                               //ϵͳʱ���趨
bool MSP_DEVICE_CLOCK_Init(void);                               //Ƭ������ʱ�ӿ��� 
bool MSP_IO_REMAP_Init(void);	
bool MSP_NVIC_PriorityGroupConfig(uint32_t NVIC_PriorityGroup); //ϵͳ�ж����ȼ��趨
bool MSP_NVIC_Init(void);                                       //ϵͳ�жϳ�ʼ��

#endif
#ifdef  __cplusplus
}  
#endif
