#include "BSP_Config.h"

bool bsp_core_init(void){
	bool status;
	status = MSP_SYSTEM_CLOCK_Init();
	status = MSP_DEVICE_CLOCK_Init();
	status = MSP_IO_REMAP_Init();
	status = MSP_NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
	status = MSP_NVIC_Init();
	return status;
}
