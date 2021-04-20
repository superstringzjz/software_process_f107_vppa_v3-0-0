#include "MSP_Config.h"

bool MSP_IO_MECHANICAL_Init(void){
	GPIO_InitTypeDef GPIO_InitStructure;
	//用于机械开关的输入输出
	/*GPIOC.2下拉输入******************/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
	GPIO_Init(GPIOC,&GPIO_InitStructure);
	/*GPIOC.3下拉输入******************/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
	GPIO_Init(GPIOC,&GPIO_InitStructure);
	/*GPIOE.7通用推挽输出最高50Mhz*****/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOE,&GPIO_InitStructure);
	/*GPIOD.11通用推挽输出最高50Mhz*****/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOD,&GPIO_InitStructure);
	/*GPIOD.3通用推挽输出最高50Mhz*****/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOD,&GPIO_InitStructure);
	/*GPIOD.4通用推挽输出最高50Mhz*****/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOD,&GPIO_InitStructure);
	return true;
}
