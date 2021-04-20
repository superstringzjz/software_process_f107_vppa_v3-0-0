#include "MSP_Config.h"

bool MSP_CAN_Init(void){
	GPIO_InitTypeDef GPIO_InitStructure;                   
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;          
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;     
	GPIO_Init(GPIOD,&GPIO_InitStructure);                  
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;          
	GPIO_Init(GPIOD,&GPIO_InitStructure);                  
	return true;
}
