#ifdef  __cplusplus
extern "C" {
#endif

#ifndef __BSP_IO_OSLED_H
#define __BSP_IO_OSLED_H
#include "stm32f10x.h"
#include "stm32f10x_conf.h"
#include "MSP_Config.h"
#include "BSP_Config.h"

//用于板载系统运行指示灯GPIO
bool bsp_osled_init(void); //led初始化

bool bsp_osled_on(void);   //led开
bool bsp_osled_off(void);  //led关

#endif
#ifdef  __cplusplus
}  
#endif
