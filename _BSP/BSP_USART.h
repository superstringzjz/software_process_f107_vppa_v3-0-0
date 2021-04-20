#ifdef  __cplusplus
extern "C" {
#endif

#ifndef __BSP_USART_H
#define __BSP_USART_H
#include "BSP_Config.h"

bool bsp_usart_init(void);   //串口初始化
bool bsp_usart_1_init(void); //串口1初始化
bool bsp_usart_1_send(u8 ch); //发送8位数据

#endif
#ifdef  __cplusplus
}  
#endif
