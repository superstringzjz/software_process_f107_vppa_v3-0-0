#include "MSP_Config.h"

bool MSP_USART_Init(void){
	/*USART1_MSP��ʼ��*/
	/*GPIOB.6,7*/
	GPIO_InitTypeDef GPIO_InitStructure;									//GPIO�ṹ��
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;             //����6
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;       //�������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;     //����ٶ�
	GPIO_Init(GPIOB,&GPIO_InitStructure);                 //��ʼ��GPIOB6
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;             //����7
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; //��������
	GPIO_Init(GPIOB,&GPIO_InitStructure);                 //��ʼ��GPIOB7
	return true;
}
