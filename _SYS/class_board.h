#ifndef __CLASS_PROCESSBOARD_H
#define __CLASS_PROCESSBOARD_H

#include "stm32f10x.h"
#include "stm32f10x_conf.h"
#include "MSP_Config.h"
#include "BSP_Config.h"

#define NULL 0

class	CProcessBorad{
public:
	bool io_in[9];  //IO信号输入端口
	bool io_out[9]; //IO信号输出端口
	u16  dac1_raw;
	u16  dac2_raw;
	CProcessBorad(void);                   //构造函数
	~CProcessBorad(void);                  //析构函数
	bool	board_init(void);                //底板初始化
	void  board_io_scan(void);             //io端口扫描
	void  board_io_set(void);              //io端口设定
	void  board_dac_set(void);             //dac设定
};

#endif
