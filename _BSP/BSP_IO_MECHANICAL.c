#include "BSP_Config.h"

bool bsp_mechanical_io_init(void){
	bool status;									            //��ʱ����
	status = MSP_IO_MECHANICAL_Init();
	status = bsp_mechanical_input_init();     //�̵��������ʼ��
	if(status == false) return false;         //��ʼ��ʧ�����˳�
	status = bsp_mechanical_output_init();    //�̵��������ʼ��
	if(status == false) return false;         //��ʼ��ʧ�����˳�
	return true;
}

bool bsp_mechanical_input_init(void){
	return true;
}

bool bsp_mechanical_output_init(void){
	GPIO_ResetBits(GPIOE,GPIO_Pin_7);	 //�̵���1���0
	GPIO_ResetBits(GPIOD,GPIO_Pin_11); //�̵���2���0
	GPIO_ResetBits(GPIOD,GPIO_Pin_3);	 //�̵���3���0
	GPIO_ResetBits(GPIOD,GPIO_Pin_4);  //�̵���4���0
	return true;

}

bool bsp_mechanical_input_1_read(void){
	bool gpio_val = GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_2); //���̵���1
	if(gpio_val) return false;
	else	       return true;
}

bool bsp_mechanical_input_2_read(void){
	bool gpio_val = GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_3); //���̵���2
	if(gpio_val) return false;
	else	       return true;
}


void bsp_mechanical_output_1_set(bool status){
	if(status == true)GPIO_SetBits(GPIOE,GPIO_Pin_7);   //�̵���1���1
	else              GPIO_ResetBits(GPIOE,GPIO_Pin_7); //�̵���1���0
}

void bsp_mechanical_output_2_set(bool status){
	if(status == true)GPIO_SetBits(GPIOD,GPIO_Pin_11);  //�̵���2���1
	else              GPIO_ResetBits(GPIOD,GPIO_Pin_11);//�̵���2���0
}

void bsp_mechanical_output_3_set(bool status){
	if(status == true)GPIO_SetBits(GPIOD,GPIO_Pin_3);   //�̵���3���1
	else              GPIO_ResetBits(GPIOD,GPIO_Pin_3); //�̵���3���0
}

void bsp_mechanical_output_4_set(bool status){
	if(status == true)GPIO_SetBits(GPIOD,GPIO_Pin_4);   //�̵���4���1
	else              GPIO_ResetBits(GPIOD,GPIO_Pin_4); //�̵���4���0
}
