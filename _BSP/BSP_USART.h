#ifdef  __cplusplus
extern "C" {
#endif

#ifndef __BSP_USART_H
#define __BSP_USART_H
#include "BSP_Config.h"

bool bsp_usart_init(void);   //���ڳ�ʼ��
bool bsp_usart_1_init(void); //����1��ʼ��
bool bsp_usart_1_send(u8 ch); //����8λ����

#endif
#ifdef  __cplusplus
}  
#endif
