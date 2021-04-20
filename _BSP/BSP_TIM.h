#ifdef  __cplusplus
extern "C" {
#endif

#ifndef __BSP_TIM_H
#define __BSP_TIM_H
#include "stm32f10x.h"
#include "stm32f10x_conf.h"
#include "MSP_Config.h"
#include "BSP_Config.h"

bool bsp_tim_2_init(void); //tim2初始化
bool bsp_tim_3_init(void); //tim3初始化

	
bool bsp_time2_start(void);//开启tim2
bool bsp_time3_start(void);//开启tim3

#endif
#ifdef  __cplusplus
}  
#endif
