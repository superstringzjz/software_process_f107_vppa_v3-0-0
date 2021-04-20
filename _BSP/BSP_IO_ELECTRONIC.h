#ifdef  __cplusplus
extern "C" {
#endif

#ifndef __BSP_ELECTRONIC_IO_H
#define __BSP_ELECTRONIC_IO_H
#include "stm32f10x.h"
#include "stm32f10x_conf.h"
#include "MSP_Config.h"
#include "BSP_Config.h"

bool bsp_electronic_io_init(void);         				//电子IO
bool bsp_electronic_input_init(void);      				//电子IO输入初始化
bool bsp_electronic_output_init(void);     				//电子IO输出初始化

u8 bsp_electronic_input_1_read(void);           //读电子IO1
u8 bsp_electronic_input_2_read(void);           //读电子IO2
u8 bsp_electronic_input_3_read(void);           //读电子IO3
u8 bsp_electronic_input_4_read(void);           //读电子IO4

void bsp_electronic_output_1_set(bool status);    //写电子IO1
void bsp_electronic_output_2_set(bool status);    //写电子IO2
void bsp_electronic_output_3_set(bool status);    //写电子IO3
void bsp_electronic_output_4_set(bool status);    //写电子IO4

#endif
#ifdef  __cplusplus
}  
#endif
