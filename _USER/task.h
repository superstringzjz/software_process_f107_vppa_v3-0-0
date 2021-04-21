#ifdef  __cplusplus
extern "C" {
#endif

#ifndef __TASK_H
#define __TASK_H
#include "stm32f10x.h"
#include "stm32f10x_conf.h"
#include "Interface.h"
#include "task.h"

#define TIMEOUT 0	
#define TRIGGER 1
#define DISCARE 2
	
extern u16 TASK_ID;
	
void task_0(u8 type,u16 time); 
void task_1(u8 type,u16 time); 
void task_2(u8 type,u16 time); 
void task_3(u8 type,u16 time); 
void task_4(u8 type,u16 time); 
void task_5(u8 type,u16 time); 
void task_6(u8 type,u16 time); 
void task_7(u8 type,u16 time); 
void task_8(u8 type,u16 time); 
void task_9(u8 type,u16 time); 

#endif
#ifdef  __cplusplus
}  
#endif
