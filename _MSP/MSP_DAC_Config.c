#include "MSP_Config.h"

bool MSP_DAC_Init(void){
	/*DAC��ʼ��*/
	/*GPIOA.4,5ģ��IO����ģʽ*/
	GPIO_InitTypeDef GPIO_InitStructure;                   //GPIO�ṹ��
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5; //����4��5
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;          //��������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;      //�ٶ�50Hz
	GPIO_Init(GPIOA,&GPIO_InitStructure);                  //��ʼ��GPIOA4��5
	GPIO_SetBits(GPIOA,GPIO_Pin_4);                        //GPIO4��1
	GPIO_SetBits(GPIOA,GPIO_Pin_5);                        //GPIO5��1
	return true;
}
