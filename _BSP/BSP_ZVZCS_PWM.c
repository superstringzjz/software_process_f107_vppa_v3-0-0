#include "BSP_Config.h"
/*zvzcs pwm 软状态寄存器*/
//reg_zvzcs_pwm_status[0],0强制模式，    1zvzcs模式
//reg_zvzcs_pwm_status[1],ccr2 channel2 0第一个跳变沿，1第二个跳变沿
//reg_zvzcs_pwm_status[2],ccr3 channel3 0第一个跳变沿，1第二个跳变沿
//reg_zvzcs_pwm_status[3],ccr4 channel4 0第一个跳变沿，1第二个跳变沿
//reg_zvzcs_pwm_status[4],保留
//reg_zvzcs_pwm_status[5],保留
//reg_zvzcs_pwm_status[6],保留
//reg_zvzcs_pwm_status[7],保留
REG reg_zvzcs_pwm_status[8];

/*zvzcs pwm用户可以直接操作的pwm占空比寄存器*/
REG16 zvzcs_pwm_duty;

/*影子占空比，真正起作用的占空比寄存器*/
REG16 zvzcs_pwm_duty_shadow;

bool bsp_zvzcs_pwm_init(){
	bool status;									           
	status = MSP_ZVZCS_PWM_Init();
	status = bsp_zvzcs_pwm_parameter_init();
	return status;
}
bool bsp_zvzcs_pwm_parameter_init(void){

	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_OCInitTypeDef       TIM_OCInitStructure;

	reg_zvzcs_pwm_status[0] = 0;
	reg_zvzcs_pwm_status[1] = 0;
	reg_zvzcs_pwm_status[2] = 0;
	reg_zvzcs_pwm_status[3] = 0;

	zvzcs_pwm_duty = 350;
	zvzcs_pwm_duty_shadow = zvzcs_pwm_duty;
	
	TIM_TimeBaseStructure.TIM_Period=3600;           
	TIM_TimeBaseStructure.TIM_Prescaler=0;            
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;    
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseStructure.TIM_RepetitionCounter=0;                       
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);
 
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; 
	TIM_OCInitStructure.TIM_Pulse = 2160; 
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; 
	TIM_OC1Init(TIM1,&TIM_OCInitStructure); 

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_Toggle; 
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; 
	TIM_OCInitStructure.TIM_Pulse = 360; 
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low; 
	TIM_OC2Init(TIM1,&TIM_OCInitStructure); 
	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_Toggle; 
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; 
	TIM_OCInitStructure.TIM_Pulse = 2160;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low; 
	TIM_OC3Init(TIM1,&TIM_OCInitStructure); 

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_Toggle; 
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; 
	TIM_OCInitStructure.TIM_Pulse = 360;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low; 
	TIM_OC4Init(TIM1,&TIM_OCInitStructure); 

	TIM_OC2PreloadConfig(TIM1,TIM_OCPreload_Disable);
	TIM_OC3PreloadConfig(TIM1,TIM_OCPreload_Disable);
	TIM_OC4PreloadConfig(TIM1,TIM_OCPreload_Disable);

	TIM_ARRPreloadConfig(TIM1,ENABLE); 
	TIM_SetCounter(TIM1,0);

	TIM_ITConfig(TIM1,TIM_IT_Update,ENABLE);
	TIM_ITConfig(TIM1,TIM_IT_CC2,ENABLE);
	TIM_ITConfig(TIM1,TIM_IT_CC3,ENABLE);
	TIM_ITConfig(TIM1,TIM_IT_CC4,ENABLE); 
	
	TIM_CtrlPWMOutputs(TIM1,ENABLE);	  //主输出使能
	TIM_Cmd(TIM1,ENABLE);

	TIM_ForcedOC1Config(TIM1,TIM_ForcedAction_Active);  
	TIM_ForcedOC2Config(TIM1,TIM_ForcedAction_InActive);  
	TIM_ForcedOC3Config(TIM1,TIM_ForcedAction_InActive);  
	TIM_ForcedOC4Config(TIM1,TIM_ForcedAction_InActive);  

	return true;
}

void bsp_zvzcs_pwm_on(void){
	if(reg_zvzcs_pwm_status[0] == 0){
		TIM_SetCounter(TIM1,0);
		reg_zvzcs_pwm_status[0] = 1;
		reg_zvzcs_pwm_status[1] = 0;
		reg_zvzcs_pwm_status[2] = 0;
		reg_zvzcs_pwm_status[3] = 0;
		
		TIM_SelectOCxM(TIM1,TIM_Channel_1,TIM_OCMode_PWM1); 
		TIM_SelectOCxM(TIM1,TIM_Channel_2,TIM_OCMode_Toggle); 
		TIM_SelectOCxM(TIM1,TIM_Channel_3,TIM_OCMode_Toggle); 
		TIM_SelectOCxM(TIM1,TIM_Channel_4,TIM_OCMode_Toggle); 

		TIM_CCxCmd(TIM1,TIM_Channel_1,TIM_CCx_Enable); 
		TIM_CCxCmd(TIM1,TIM_Channel_2,TIM_CCx_Enable); 
		TIM_CCxCmd(TIM1,TIM_Channel_3,TIM_CCx_Enable); 
		TIM_CCxCmd(TIM1,TIM_Channel_4,TIM_CCx_Enable); 
	}
	else{
	}
}

void bsp_zvzcs_pwm_off(void){
	if(reg_zvzcs_pwm_status[0] == 1){
		TIM_SetCounter(TIM1,0);
		
		reg_zvzcs_pwm_status[0] = 0;
		reg_zvzcs_pwm_status[1] = 0;
		reg_zvzcs_pwm_status[2] = 0;
		reg_zvzcs_pwm_status[3] = 0;
		
		TIM_ForcedOC1Config(TIM1,TIM_ForcedAction_Active);  
		TIM_ForcedOC2Config(TIM1,TIM_ForcedAction_InActive);  
		TIM_ForcedOC3Config(TIM1,TIM_ForcedAction_InActive);  
		TIM_ForcedOC4Config(TIM1,TIM_ForcedAction_InActive);  
	}
	else{
	}
}

void bsp_zvzcs_pwm_duty_set(u16 user_pwm_duty){
	zvzcs_pwm_duty = user_pwm_duty;
	if(user_pwm_duty > 1400) zvzcs_pwm_duty = 1400;
	if(user_pwm_duty < 350 ) zvzcs_pwm_duty = 350;
}

extern "C" void TIM1_CC_IRQHandler(void){
	if(TIM_GetITStatus(TIM1,TIM_IT_CC2)== SET){
		TIM_ClearITPendingBit(TIM1,TIM_IT_CC2); 		
		if(reg_zvzcs_pwm_status[1]==0){
			TIM_SetCompare2(TIM1,1800);
			reg_zvzcs_pwm_status[1] = 1;
		}
		else if(reg_zvzcs_pwm_status[1]==1){
			TIM_SetCompare2(TIM1,360);
			reg_zvzcs_pwm_status[1] = 0;
		}
	}
	if(TIM_GetITStatus(TIM1,TIM_IT_CC3)== SET){
		TIM_ClearITPendingBit(TIM1,TIM_IT_CC3); 		
		if(reg_zvzcs_pwm_status[2]==0){
			TIM_SetCompare3(TIM1,2160+zvzcs_pwm_duty_shadow);
			reg_zvzcs_pwm_status[2] = 1;
		}
		else if(reg_zvzcs_pwm_status[2]==1){
			TIM_SetCompare3(TIM1,2160);
			reg_zvzcs_pwm_status[2] = 0;
		}
	}
	if(TIM_GetITStatus(TIM1,TIM_IT_CC4)== SET){
		TIM_ClearITPendingBit(TIM1,TIM_IT_CC4); 		
		if(reg_zvzcs_pwm_status[3]==0){
			TIM_SetCompare4(TIM1,360+zvzcs_pwm_duty_shadow);
			reg_zvzcs_pwm_status[3] = 1;
		}
		else if(reg_zvzcs_pwm_status[3]==1){
			TIM_SetCompare4(TIM1,360);
			reg_zvzcs_pwm_status[3] = 0;
		}
	}	
} 

extern "C" void TIM1_UP_IRQHandler(void){
	if(TIM_GetITStatus(TIM1,TIM_IT_Update)== SET){
		TIM_ClearITPendingBit(TIM1,TIM_IT_Update);
		zvzcs_pwm_duty_shadow = zvzcs_pwm_duty;
	}
}
