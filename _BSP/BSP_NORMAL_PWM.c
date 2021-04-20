#include "BSP_Config.h"

bool bsp_normal_pwm_init(){
//	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
//	TIM_OCInitTypeDef       TIM_OCInitStructure;

//	MSP_NORMAL_PWM_Init();
//	
//	TIM_TimeBaseStructure.TIM_Period=3600;           
//	TIM_TimeBaseStructure.TIM_Prescaler=0;            
//	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;    
//	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;
//	TIM_TimeBaseStructure.TIM_RepetitionCounter=0;                       
//	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);
// 
//	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 
//	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; 
//	TIM_OCInitStructure.TIM_Pulse = 1800; 
//	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; 
//	TIM_OC1Init(TIM4,&TIM_OCInitStructure); 

//	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 
//	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; 
//	TIM_OCInitStructure.TIM_Pulse = 1800; 
//	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; 
//	TIM_OC2Init(TIM4,&TIM_OCInitStructure); 
//	
//	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 
//	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; 
//	TIM_OCInitStructure.TIM_Pulse = 1800;
//	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; 
//	TIM_OC3Init(TIM4,&TIM_OCInitStructure); 

//	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 
//	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; 
//	TIM_OCInitStructure.TIM_Pulse = 1800;
//	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; 
//	TIM_OC4Init(TIM4,&TIM_OCInitStructure); 

//	TIM_OC1PreloadConfig(TIM4,TIM_OCPreload_Enable);
//	TIM_OC2PreloadConfig(TIM4,TIM_OCPreload_Enable);
//	TIM_OC3PreloadConfig(TIM4,TIM_OCPreload_Enable);
//	TIM_OC4PreloadConfig(TIM4,TIM_OCPreload_Enable);

//	TIM_ARRPreloadConfig(TIM4,ENABLE); 
//	TIM_SetCounter(TIM4,0);

//	TIM_Cmd(TIM4,DISABLE);

	return true;
}

void bsp_normal_pwm_on(void){
	TIM_SetCounter(TIM4,0);
	TIM_Cmd(TIM4,ENABLE);
}

void bsp_normal_pwm_off(void){
	TIM_Cmd(TIM4,DISABLE);
	TIM_SetCounter(TIM4,0);
}

void bsp_normal_pwm_duty_set(u16 user_pwm_duty_1,u16 user_pwm_duty_2,u16 user_pwm_duty_3,u16 user_pwm_duty_4){
	TIM_SetCompare1(TIM4,user_pwm_duty_1);
	TIM_SetCompare2(TIM4,user_pwm_duty_2);
	TIM_SetCompare3(TIM4,user_pwm_duty_3);
	TIM_SetCompare4(TIM4,user_pwm_duty_4);
}
