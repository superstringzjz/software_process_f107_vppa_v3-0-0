#include "MSP_Config.h"

bool MSP_ZVZCS_PWM_Init(void){
	GPIO_InitTypeDef GPIO_InitStructure;
	/*GPIOE.9,11,13,14通用推挽输出最高50Mhz*/
	/*GPIOE.9,11,13,14用于可带死区间PWM输出*/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_11 |GPIO_Pin_13 |GPIO_Pin_14;           
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;     
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	
	GPIO_Init(GPIOE,&GPIO_InitStructure);              
	return true;
}
