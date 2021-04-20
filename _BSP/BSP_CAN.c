#include "BSP_Config.h"


bool bsp_can_init(void){
	bool status;									            //临时变量
	status = MSP_CAN_Init();
	if(status == false) return false;         //初始化失败则退出
	status = bsp_can_parameter_init();
	if(status == false) return false;         //初始化失败则退出
  return true;

}

bool bsp_can_parameter_init(void){
	CAN_InitTypeDef CAN_InitStructure;
	CAN_FilterInitTypeDef CAN_FilterInitStructure;

	CAN_InitStructure.CAN_Prescaler=4;
  CAN_InitStructure.CAN_Mode= CAN_Mode_Normal;
	CAN_InitStructure.CAN_SJW=CAN_SJW_1tq;
	CAN_InitStructure.CAN_BS1=CAN_BS1_8tq;
	CAN_InitStructure.CAN_BS2=CAN_BS2_7tq;

	CAN_InitStructure.CAN_TTCM=DISABLE; 
	CAN_InitStructure.CAN_ABOM=DISABLE; 
  CAN_InitStructure.CAN_AWUM=DISABLE; 
  CAN_InitStructure.CAN_NART=ENABLE; 
  CAN_InitStructure.CAN_RFLM=DISABLE; 
  CAN_InitStructure.CAN_TXFP=DISABLE; 

	CAN_Init(CAN1, &CAN_InitStructure); 

	CAN_FilterInitStructure.CAN_FilterNumber=0;
	CAN_FilterInitStructure.CAN_FilterMode=CAN_FilterMode_IdMask;
	CAN_FilterInitStructure.CAN_FilterScale=CAN_FilterScale_32bit;
	CAN_FilterInitStructure.CAN_FilterIdHigh=0x0000; 
	CAN_FilterInitStructure.CAN_FilterIdLow=0x0000;
	CAN_FilterInitStructure.CAN_FilterMaskIdHigh=0x0000; 
	CAN_FilterInitStructure.CAN_FilterMaskIdLow=0x0000;
	CAN_FilterInitStructure.CAN_FilterFIFOAssignment=CAN_Filter_FIFO0;
	CAN_FilterInitStructure.CAN_FilterActivation=ENABLE; 
	
	CAN_FilterInit(&CAN_FilterInitStructure); 
	CAN_ITConfig(CAN1,CAN_IT_FMP0,ENABLE);				//FIFO0消息挂号中断允许.		    

  return true;
}

