#include "MSP_Config.h"

bool MSP_ADC_Init(void){
	/*ADC初始化*/
	/*GPIOA.6,7模拟IO输入模式*/
	GPIO_InitTypeDef GPIO_InitStructure;                   //GPIO结构体
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7; //引脚6、7
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;          //复用输入
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;      //速度50Hz
	GPIO_Init(GPIOA,&GPIO_InitStructure);                  //初始化GPIOA6、7
	GPIO_SetBits(GPIOA,GPIO_Pin_6);                        //GPIO6置1
	GPIO_SetBits(GPIOA,GPIO_Pin_7);                        //GPIO7置1
	return true;
}
