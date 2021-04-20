#include "MSP_Config.h"

bool MSP_NORMAL_PWM_Init(void){
	GPIO_InitTypeDef GPIO_InitStructure;
	/*GPIOD.12,13,14,15通用推挽输出最高50Mhz*/
	/*GPIOD.12,13,14,15用于可带死区间PWM输出*/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 |GPIO_Pin_14 |GPIO_Pin_15;           
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;     
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	
	GPIO_Init(GPIOD,&GPIO_InitStructure);              
	return true;
}
