#include "stm32f10x_conf.h"
#include "process.h"

int main(){
	bool status;
	status = os_init();
	if(status == false) return 1;
	status = user_init();
	if(status == false) return 1;
	os_once();
	user_once();
	for(;;){
		os_nrt();
		user_ntr();
	}
}

extern "C" void TIM2_IRQHandler(void){
	if(TIM_GetITStatus(TIM2,TIM_IT_Update)!=RESET){
		TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
		os_5000us();
		thread_hmi_5000us();
	}
}

extern "C" void TIM3_IRQHandler(void){
	if(TIM_GetITStatus(TIM3,TIM_IT_Update)!=RESET){
		TIM_ClearITPendingBit(TIM3,TIM_IT_Update);
		os_500us();
		thread_process_500us();
	}
}
