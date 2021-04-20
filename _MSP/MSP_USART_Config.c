#include "MSP_Config.h"

bool MSP_USART_Init(void){
	/*USART1_MSP初始化*/
	/*GPIOB.6,7*/
	GPIO_InitTypeDef GPIO_InitStructure;									//GPIO结构体
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;             //引脚6
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;       //复用输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;     //输出速度
	GPIO_Init(GPIOB,&GPIO_InitStructure);                 //初始化GPIOB6
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;             //引脚7
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; //悬空输入
	GPIO_Init(GPIOB,&GPIO_InitStructure);                 //初始化GPIOB7
	return true;
}
