#ifndef __CLASS_DECODE_H
#define __CLASS_DECODE_H

#include "stm32f10x_conf.h"

#define	DA_WIDTH	   3600
#define FULL_CURRENT 300

//��Ȼʱ��Ĭ�ϵ�λ��Ϊms
//�����ж�ʱ��500us
#define TIMEBASE     500
//�̿��ж�ʱ��5000us
#define TIMEBASEL    5000
//msת��us
#define TIMEKMS      1000

class	CDecode{
	public:
	
		CDecode(void); //���캯��
		~CDecode(void);  //��������
	
		u16 da_current_set;
		u16 counter_fast;
		u16 counter_slow;
	
		void decode_init(void);
	  void decode_current(float current);
		bool decode_time_fast(void);
		bool decode_time_slow(void);
};

#endif
