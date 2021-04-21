#ifndef __CLASS_DECODE_H
#define __CLASS_DECODE_H

#include "stm32f10x_conf.h"

#define	DA_WIDTH	   3600
#define FULL_CURRENT 300

//自然时间默认单位均为ms
//工艺中断时基500us
#define TIMEBASE     500
//程控中断时基5000us
#define TIMEBASEL    5000
//ms转换us
#define TIMEKMS      1000

class	CDecode{
	public:
	
		CDecode(void); //构造函数
		~CDecode(void);  //析构函数
	
		float real_current;
		u16 da_current_set;
		u16 counter_fast;
		u16 counter_slow;
	
		void decode_init(void);
	  void decode_current(void);
		bool decode_time_fast(void);
		bool decode_time_slow(void);
};

#endif
