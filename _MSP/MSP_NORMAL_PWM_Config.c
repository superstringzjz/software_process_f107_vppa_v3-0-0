#include "MSP_Config.h"

bool MSP_NORMAL_PWM_Init(void){
	GPIO_InitTypeDef GPIO_InitStructure;
	/*GPIOD.12,13,14,15ͨ������������50Mhz*/
	/*GPIOD.12,13,14,15���ڿɴ�������PWM���*/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 |GPIO_Pin_14 |GPIO_Pin_15;           
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;     
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	
	GPIO_Init(GPIOD,&GPIO_InitStructure);              
	return true;
}
