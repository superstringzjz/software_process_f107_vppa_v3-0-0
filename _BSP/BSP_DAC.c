#include "BSP_DAC.h"

bool bsp_dac_init(void){
	bool status;									            //临时变量
	status = MSP_DAC_Init();
	if(status == false) return false;         //初始化失败则退出
	status = bsp_dac_parameter_init();
	if(status == false) return false;         //初始化失败则退出
	return status;
}

bool bsp_dac_parameter_init(void){
	bool status;									            //临时变量
	DAC_InitTypeDef DAC_InitType;
	DAC_InitType.DAC_Trigger = DAC_Trigger_None;
	DAC_InitType.DAC_WaveGeneration = DAC_WaveGeneration_None;
	DAC_InitType.DAC_LFSRUnmask_TriangleAmplitude = DAC_LFSRUnmask_Bit0;
	DAC_InitType.DAC_OutputBuffer = DAC_OutputBuffer_Disable;
	DAC_Init(DAC_Channel_1,&DAC_InitType);
	DAC_Init(DAC_Channel_2,&DAC_InitType);
	DAC_Cmd(DAC_Channel_1,ENABLE);
	DAC_Cmd(DAC_Channel_2,ENABLE);
	return status;
}

bool bsp_dac_channel1_output(u16 val){
	if((val>0) && (val<4096)){
		DAC_SetChannel1Data(DAC_Align_12b_R,val);
		return true;
	}
	else	return false;
}

bool bsp_dac_channel2_output(u16 val){
	if((val>0) && (val<4096)){
		DAC_SetChannel2Data(DAC_Align_12b_R,val);
		return true;
	}
	else	return false;
}

