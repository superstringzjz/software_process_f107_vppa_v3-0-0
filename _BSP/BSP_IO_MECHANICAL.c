#include "BSP_Config.h"

bool bsp_mechanical_io_init(void){
	bool status;									            //临时变量
	status = MSP_IO_MECHANICAL_Init();
	status = bsp_mechanical_input_init();     //继电器输入初始化
	if(status == false) return false;         //初始化失败则退出
	status = bsp_mechanical_output_init();    //继电器输出初始化
	if(status == false) return false;         //初始化失败则退出
	return true;
}

bool bsp_mechanical_input_init(void){
	return true;
}

bool bsp_mechanical_output_init(void){
	GPIO_ResetBits(GPIOE,GPIO_Pin_7);	 //继电器1输出0
	GPIO_ResetBits(GPIOD,GPIO_Pin_11); //继电器2输出0
	GPIO_ResetBits(GPIOD,GPIO_Pin_3);	 //继电器3输出0
	GPIO_ResetBits(GPIOD,GPIO_Pin_4);  //继电器4输出0
	return true;

}

bool bsp_mechanical_input_1_read(void){
	bool gpio_val = GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_2); //读继电器1
	if(gpio_val) return false;
	else	       return true;
}

bool bsp_mechanical_input_2_read(void){
	bool gpio_val = GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_3); //读继电器2
	if(gpio_val) return false;
	else	       return true;
}


void bsp_mechanical_output_1_set(bool status){
	if(status == true)GPIO_SetBits(GPIOE,GPIO_Pin_7);   //继电器1输出1
	else              GPIO_ResetBits(GPIOE,GPIO_Pin_7); //继电器1输出0
}

void bsp_mechanical_output_2_set(bool status){
	if(status == true)GPIO_SetBits(GPIOD,GPIO_Pin_11);  //继电器2输出1
	else              GPIO_ResetBits(GPIOD,GPIO_Pin_11);//继电器2输出0
}

void bsp_mechanical_output_3_set(bool status){
	if(status == true)GPIO_SetBits(GPIOD,GPIO_Pin_3);   //继电器3输出1
	else              GPIO_ResetBits(GPIOD,GPIO_Pin_3); //继电器3输出0
}

void bsp_mechanical_output_4_set(bool status){
	if(status == true)GPIO_SetBits(GPIOD,GPIO_Pin_4);   //继电器4输出1
	else              GPIO_ResetBits(GPIOD,GPIO_Pin_4); //继电器4输出0
}
