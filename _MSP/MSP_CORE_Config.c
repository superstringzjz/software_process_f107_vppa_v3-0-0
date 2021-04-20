#include "MSP_Config.h"

/*ϵͳʱ���趨*/
bool MSP_SYSTEM_CLOCK_Init(void){
	return true;
}

/*Ƭ������ʱ�ӿ��� */
bool MSP_DEVICE_CLOCK_Init(void){
	/*����APB1����������ʱ��*/
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR,ENABLE);     //PWRʱ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_BKP,ENABLE);     //BKPʱ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_DAC,ENABLE);     //DACʱ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);    //TIM2ʱ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);    //TIM3ʱ��
	
	/*����APB2����������ʱ��*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);   //GPIOAʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);   //GPIOBʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);   //GPIOCʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD,ENABLE);   //GPIODʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);   //GPIOEʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);    //AFIOʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);  //Usart1ʱ��

	return true;
}

/*������ӳ��*/
bool MSP_IO_REMAP_Init(void){
	GPIO_PinRemapConfig(GPIO_Remap_USART1, ENABLE);    //Usart1��ӳ��
	return true;
}

/*�����ж����ȼ�����*/
bool MSP_NVIC_PriorityGroupConfig(uint32_t NVIC_PriorityGroup){
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup);               //�����ж����ȼ�
	return true;
}

/*ϵͳ�жϳ���*/
bool MSP_NVIC_Init(void){
	NVIC_InitTypeDef NVIC_InitStructure;                        //�жϽṹ��
	
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;             //��ʱ��3
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;   //���ȼ�2
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;          //�����ȼ�0
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;             //�����ж�
	NVIC_Init(&NVIC_InitStructure);                             //�жϳ�ʼ��
	
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;             //��ʱ��2�ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;   //���ȼ�3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;          //�����ȼ�0
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;             //�����ж�
	NVIC_Init(&NVIC_InitStructure);                             //�жϳ�ʼ��
	
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;           //Usart1�ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;   //���ȼ�4
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;          //�����ȼ�0
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;             //�����ж�
	NVIC_Init(&NVIC_InitStructure);                             //�жϳ�ʼ��

	return true;
}                                        

