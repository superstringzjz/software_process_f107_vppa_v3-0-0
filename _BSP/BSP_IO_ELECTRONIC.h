#ifdef  __cplusplus
extern "C" {
#endif

#ifndef __BSP_ELECTRONIC_IO_H
#define __BSP_ELECTRONIC_IO_H
#include "stm32f10x.h"
#include "stm32f10x_conf.h"
#include "MSP_Config.h"
#include "BSP_Config.h"

bool bsp_electronic_io_init(void);         				//����IO
bool bsp_electronic_input_init(void);      				//����IO�����ʼ��
bool bsp_electronic_output_init(void);     				//����IO�����ʼ��

u8 bsp_electronic_input_1_read(void);           //������IO1
u8 bsp_electronic_input_2_read(void);           //������IO2
u8 bsp_electronic_input_3_read(void);           //������IO3
u8 bsp_electronic_input_4_read(void);           //������IO4

void bsp_electronic_output_1_set(bool status);    //д����IO1
void bsp_electronic_output_2_set(bool status);    //д����IO2
void bsp_electronic_output_3_set(bool status);    //д����IO3
void bsp_electronic_output_4_set(bool status);    //д����IO4

#endif
#ifdef  __cplusplus
}  
#endif
