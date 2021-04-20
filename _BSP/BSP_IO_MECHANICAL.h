#ifdef  __cplusplus
extern "C" {
#endif

#ifndef __BSP_MECHANICAL_IO_H
#define __BSP_MECHANICAL_IO_H
#include "stm32f10x.h"
#include "stm32f10x_conf.h"
#include "MSP_Config.h"
#include "BSP_Config.h"

bool bsp_mechanical_io_init(void);                        //继电器初始化
bool bsp_mechanical_input_init(void);                     //继电器输入初始化
bool bsp_mechanical_output_init(void);                    //继电器输出初始化

bool bsp_mechanical_input_1_read(void);                   //读继电器1
bool bsp_mechanical_input_2_read(void);                   //读继电器2

void bsp_mechanical_output_1_set(bool status);            //写继电器1
void bsp_mechanical_output_2_set(bool status);            //写继电器2
void bsp_mechanical_output_3_set(bool status);            //写继电器3
void bsp_mechanical_output_4_set(bool status);            //写继电器4

#endif
#ifdef  __cplusplus
}  
#endif
