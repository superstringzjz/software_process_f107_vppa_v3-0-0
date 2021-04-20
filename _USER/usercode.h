#ifdef  __cplusplus
extern "C" {
#endif

#ifndef __USERCODE_H
#define __USERCODE_H
#include "stm32f10x.h"
#include "stm32f10x_conf.h"
#include "os.h"
#include "class_board.h"	
	
bool user_init(void);
void user_once(void);
void user_ntr(void);
void thread_hmi_5000us(void);
void thread_process_500us(void);
#endif
#ifdef  __cplusplus
}  
#endif
