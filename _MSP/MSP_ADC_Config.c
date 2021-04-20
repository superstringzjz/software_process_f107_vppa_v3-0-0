#include "MSP_Config.h"

bool MSP_ADC_Init(void){
	/*ADC��ʼ��*/
	/*GPIOA.6,7ģ��IO����ģʽ*/
	GPIO_InitTypeDef GPIO_InitStructure;                   //GPIO�ṹ��
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7; //����6��7
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;          //��������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;      //�ٶ�50Hz
	GPIO_Init(GPIOA,&GPIO_InitStructure);                  //��ʼ��GPIOA6��7
	GPIO_SetBits(GPIOA,GPIO_Pin_6);                        //GPIO6��1
	GPIO_SetBits(GPIOA,GPIO_Pin_7);                        //GPIO7��1
	return true;
}
