#ifdef  __cplusplus
extern "C" {
#endif

#ifndef __BSP_IO_OSLED_H
#define __BSP_IO_OSLED_H
#include "stm32f10x.h"
#include "stm32f10x_conf.h"
#include "MSP_Config.h"
#include "BSP_Config.h"

//���ڰ���ϵͳ����ָʾ��GPIO
bool bsp_osled_init(void); //led��ʼ��

bool bsp_osled_on(void);   //led��
bool bsp_osled_off(void);  //led��

#endif
#ifdef  __cplusplus
}  
#endif
