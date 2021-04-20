#ifdef  __cplusplus
extern "C" {
#endif

#ifndef __COM_H
#define __COM_H

#include "stm32f10x.h"
#include "stm32f10x_conf.h"
#include "MSP_Config.h"
#include "BSP_Config.h"
	
#define RX_LEN 200
#define TX_LEN 200
typedef struct{
	u8 buff[RX_LEN][8];
	u8 rx_len;
	u8 flag;
	u8 w;
	u8 r;
}COM_RX;

typedef struct{
	u8 buff[TX_LEN][8];
	u8 rx_len;
	u8 flag;
	u8 w;
	u8 r;
}COM_TX;
#endif
#ifdef  __cplusplus
}  
#endif
