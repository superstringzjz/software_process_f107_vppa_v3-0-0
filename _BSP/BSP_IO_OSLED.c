#include "BSP_Config.h"


bool bsp_osled_init(void){
	bool status;
	status = MSP_IO_OSLED_Init();
	GPIO_SetBits(GPIOA,GPIO_Pin_0);
	return status;
}
bool bsp_osled_on(void){
	GPIO_SetBits(GPIOA,GPIO_Pin_0);
	return true;
}
bool bsp_osled_off(void){
	GPIO_ResetBits(GPIOA,GPIO_Pin_0);
	return true;
}


