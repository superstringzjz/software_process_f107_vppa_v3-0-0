#ifdef  __cplusplus
extern "C" {
#endif

#ifndef __BASE_INTERFACE_H
#define __BASE_INTERFACE_H

#include "stm32f10x.h"
#include "stm32f10x_conf.h"
#include "MSP_Config.h"
#include "BSP_Config.h"
	
bool base_interface_init(void);
void base_io_scan(void);
void base_io_set(void);
void base_dac_set(void);
void base_dac_1_raw_set(u16 value);
void base_dac_2_raw_set(u16 value);
u16  base_dac_1_raw_read(void);
u16  base_dac_2_raw_read(void);
void base_io_signale_set(u8 bit,bool status);
bool base_io_signale_read(u8 bit);

#endif
#ifdef  __cplusplus
}  
#endif
