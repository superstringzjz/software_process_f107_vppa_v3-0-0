#include "MSP_Config.h"

bool MSP_DAC_Init(void){
	/*DAC初始化*/
	/*GPIOA.4,5模拟IO输入模式*/
	GPIO_InitTypeDef GPIO_InitStructure;                   //GPIO结构体
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5; //引脚4、5
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;          //复用输入
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;      //速度50Hz
	GPIO_Init(GPIOA,&GPIO_InitStructure);                  //初始化GPIOA4、5
	GPIO_SetBits(GPIOA,GPIO_Pin_4);                        //GPIO4置1
	GPIO_SetBits(GPIOA,GPIO_Pin_5);                        //GPIO5置1
	return true;
}
