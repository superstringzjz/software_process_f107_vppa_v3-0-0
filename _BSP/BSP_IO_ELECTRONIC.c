#include "BSP_Config.h"


bool bsp_electronic_io_init(void){
	bool status;	
	status = MSP_IO_ELETRONIC_Init();
	status = bsp_electronic_input_init();     
	if(status == false) return false;         
	status = bsp_electronic_output_init();    
	if(status == false) return false;         
	return true;
}

bool bsp_electronic_input_init(void){
	return true;
}

bool bsp_electronic_output_init(void){
	bsp_electronic_output_1_set(false); 
	bsp_electronic_output_2_set(false); 
	bsp_electronic_output_3_set(false); 
	bsp_electronic_output_4_set(false); 

	return true;
}

u8 bsp_electronic_input_1_read(void){
	u8 gpio_val = GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1); 
	return gpio_val;
}

u8 bsp_electronic_input_2_read(void){
	u8 gpio_val = GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_0); 
	return gpio_val;
}

u8 bsp_electronic_input_3_read(void){
	u8 gpio_val = GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_5); 
	return gpio_val;
}

u8 bsp_electronic_input_4_read(void){
	u8 gpio_val = GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_4); 
	return gpio_val;
}


void bsp_electronic_output_1_set(bool status){
	if(status == true)GPIO_ResetBits(GPIOC,GPIO_Pin_9);   
	else              GPIO_SetBits(GPIOC,GPIO_Pin_9); 
}

void bsp_electronic_output_2_set(bool status){
	if(status == true)GPIO_ResetBits(GPIOC,GPIO_Pin_8);   
	else              GPIO_SetBits(GPIOC,GPIO_Pin_8); 
}

void bsp_electronic_output_3_set(bool status){
	if(status == true)GPIO_ResetBits(GPIOC,GPIO_Pin_7);   
	else              GPIO_SetBits(GPIOC,GPIO_Pin_7); 
}

void bsp_electronic_output_4_set(bool status){
	if(status == true)GPIO_ResetBits(GPIOC,GPIO_Pin_6);   
	else              GPIO_SetBits(GPIOC,GPIO_Pin_6); 
}

