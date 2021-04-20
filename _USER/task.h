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
	
void task_0(u8 type,u16 time); //起弧
void task_1(u8 type,u16 time); //送气
void task_2(u8 type,u16 time); //直流
void task_3(u8 type,u16 time); //初始
void task_4(u8 type,u16 time); //上升
void task_5(u8 type,u16 time); //焊接
void task_6(u8 type,u16 time); //下降
void task_7(u8 type,u16 time); //填充
void task_8(u8 type,u16 time); //延时

#endif
#ifdef  __cplusplus
}  
#endif
