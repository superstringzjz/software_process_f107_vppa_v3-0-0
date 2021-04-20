#include "BSP_Config.h"

/*TIM2��ʼ��*/
bool bsp_tim_2_init(void){                        
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;             //��ʱ���ṹ��
	TIM_TimeBaseStructure.TIM_Period =499;                     //5000us��ʱ
	TIM_TimeBaseStructure.TIM_Prescaler = 719;                 /********/
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;    /********/
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;//���ϼ�ģʽ
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseStructure);             //��ʱ����ʼ��
	TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE);                   //����ʱ��2�����ж�
	return true;
}
/*TIM3��ʼ��*/
bool bsp_tim_3_init(void){
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;             //��ʱ���ṹ��
	TIM_TimeBaseStructure.TIM_Period =49;                      //500us�ж�
	TIM_TimeBaseStructure.TIM_Prescaler = 719;                 /********/
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;    /********/
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;//���ϼ���ģʽ
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseStructure);             //��ʱ����ʼ��
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);                   //����ʱ3�����ж�
	return true;
}


/*����TIM2*/
bool bsp_time2_start(void){
	TIM_Cmd(TIM2,ENABLE); //������ʱ��2
	return true;
}

/*����TIM3*/
bool bsp_time3_start(void){
	TIM_Cmd(TIM3,ENABLE); //������ʱ3
	return true;
}
