#ifndef __CLASS_PROCESSBOARD_H
#define __CLASS_PROCESSBOARD_H

#include "stm32f10x.h"
#include "stm32f10x_conf.h"
#include "MSP_Config.h"
#include "BSP_Config.h"

#define NULL 0

class	CProcessBorad{
public:
	bool io_in[9];  //IO�ź�����˿�
	bool io_out[9]; //IO�ź�����˿�
	u16  dac1_raw;
	u16  dac2_raw;
	CProcessBorad(void);                   //���캯��
	~CProcessBorad(void);                  //��������
	bool	board_init(void);                //�װ��ʼ��
	void  board_io_scan(void);             //io�˿�ɨ��
	void  board_io_set(void);              //io�˿��趨
	void  board_dac_set(void);             //dac�趨
};

#endif
