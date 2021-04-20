#include "BSP_Config.h"

bool bsp_usart_init(void){
	bool status = true;
	status = MSP_USART_Init();                //回调MSP函数
	if(status == false) return false;         //初始化失败则退出
	status = bsp_usart_1_init();
	if(status == false) return true;
	return true;
}
bool bsp_usart_1_init(void){
	USART_InitTypeDef USART_InitStructure;
	USART_DeInit(USART1);
	USART_InitStructure.USART_BaudRate = 115200;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_Init(USART1,&USART_InitStructure);
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE); 
	USART_Cmd(USART1,ENABLE);
	return true;
}

bool bsp_usart_1_send(u8 ch){
	while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!= SET);
	USART_SendData(USART1,ch);
	return true;
}
