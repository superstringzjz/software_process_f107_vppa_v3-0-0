#include "com.h"
//COM_RX com_usart1_rx = {{0},0,0,0,0};

extern "C" void USART1_IRQHandler(void){
//  u8 RxMessage;
//	if(USART_GetFlagStatus(USART1,USART_IT_RXNE)!=RESET){
//		RxMessage =USART_ReceiveData(USART1);
//		if(com_usart1_rx.rx_len<RX_LEN){
//			com_usart1_rx.buff[com_usart1_rx.w][0]=RxMessage;
//			com_usart1_rx.w=(com_usart1_rx.w+1)%RX_LEN;
//			com_usart1_rx.rx_len++;
//		}
//		else com_usart1_rx.flag = 1;
//	}
}

void can1_annular_data(u8 *rx_data){
//	if(com_usart1_rx.rx_len!=0 && com_usart1_rx.flag != 1){
//		rx_data = com_usart1_rx.buff[com_usart1_rx.r];
//		com_usart1_rx.r = (com_usart1_rx.r+1)%RX_LEN;
//		com_usart1_rx.rx_len--;
//	}
}
