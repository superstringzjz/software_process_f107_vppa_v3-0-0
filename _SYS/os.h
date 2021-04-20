#ifdef  __cplusplus
extern "C" {
#endif

#ifndef __OS_H
#define __OS_H

#include "stm32f10x.h"
#include "stm32f10x_conf.h"
#include "MSP_Config.h"
#include "BSP_Config.h"

bool os_init(void);
bool os_thread_start(void);
bool os_led_init(void);
void os_led_run(void);
void os_once(void);
void os_nrt(void);
void os_5000us(void);
void os_500us(void);
void os_50us(void);

#endif
#ifdef  __cplusplus
}  
#endif
