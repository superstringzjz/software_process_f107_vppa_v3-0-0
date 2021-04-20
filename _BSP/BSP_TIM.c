#include "BSP_Config.h"

/*TIM2初始化*/
bool bsp_tim_2_init(void){                        
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;             //定时器结构体
	TIM_TimeBaseStructure.TIM_Period =499;                     //5000us定时
	TIM_TimeBaseStructure.TIM_Prescaler = 719;                 /********/
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;    /********/
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;//向上计模式
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseStructure);             //定时器初始化
	TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE);                   //允许定时器2更新中断
	return true;
}
/*TIM3初始化*/
bool bsp_tim_3_init(void){
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;             //定时器结构体
	TIM_TimeBaseStructure.TIM_Period =49;                      //500us中断
	TIM_TimeBaseStructure.TIM_Prescaler = 719;                 /********/
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;    /********/
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;//向上计数模式
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseStructure);             //定时器初始化
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);                   //允许定时3更新中断
	return true;
}


/*启动TIM2*/
bool bsp_time2_start(void){
	TIM_Cmd(TIM2,ENABLE); //开启定时器2
	return true;
}

/*启动TIM3*/
bool bsp_time3_start(void){
	TIM_Cmd(TIM3,ENABLE); //开启定时3
	return true;
}
