#include "MSP_Config.h"

bool MSP_IO_OSLED_Init(void){
	GPIO_InitTypeDef GPIO_InitStructure;
	/*���İ���GPIO��Ӧ��*/
	/*GPIOA.0ͨ������������50Mhz*/
	/*GPIOA.0����ϵͳled����ָʾ��*/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	return true;
}
