#include "BSP_Config.h"

bool bsp_adc_init(void){
	bool status;									            //临时变量
	status = MSP_ADC_Init();
	if(status == false) return false;         //初始化失败则退出
	status = bsp_adc_parameter_init();
	if(status == false) return false;         //初始化失败则退出

	return status;
}

bool bsp_adc_parameter_init(void){
	ADC_InitTypeDef ADC_InitStructure;
	RCC_ADCCLKConfig(RCC_PCLK2_Div6); 
	ADC_DeInit(ADC1);
	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent; 
	ADC_InitStructure.ADC_ScanConvMode = DISABLE; 
	ADC_InitStructure.ADC_ContinuousConvMode = DISABLE; 
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;

	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right; 
	ADC_InitStructure.ADC_NbrOfChannel = 1; 
	ADC_Init(ADC1, &ADC_InitStructure); 
	ADC_Cmd(ADC1, ENABLE); 
	ADC_ResetCalibration(ADC1); 
	while(ADC_GetResetCalibrationStatus(ADC1)){} 
	ADC_StartCalibration(ADC1); 
	while(ADC_GetCalibrationStatus(ADC1)){}
	return true;
}

u16 bsp_adc_1_get_channel6(void){
	ADC_RegularChannelConfig(ADC1, 6, 1, ADC_SampleTime_7Cycles5 );
	ADC_SoftwareStartConvCmd(ADC1, ENABLE); 
	while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC ));
	return ADC_GetConversionValue(ADC1);
}

u16 bsp_adc_1_get_channel7(void){
	ADC_RegularChannelConfig(ADC1, 7, 1, ADC_SampleTime_7Cycles5 );
	ADC_SoftwareStartConvCmd(ADC1, ENABLE); 
	while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC ));
	return ADC_GetConversionValue(ADC1);
}

u16 bsp_adc_1_get_channel(u8 channel){
	ADC_RegularChannelConfig(ADC1, channel, 1, ADC_SampleTime_7Cycles5 );
	ADC_SoftwareStartConvCmd(ADC1, ENABLE); 
	while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC ));
	return ADC_GetConversionValue(ADC1);
}
