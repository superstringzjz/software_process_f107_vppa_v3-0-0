#include "MSP_Config.h"

bool MSP_IO_OSLED_Init(void){
	GPIO_InitTypeDef GPIO_InitStructure;
	/*核心板载GPIO的应用*/
	/*GPIOA.0通用推挽输出最高50Mhz*/
	/*GPIOA.0用于系统led运行指示灯*/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	return true;
}
