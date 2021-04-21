#ifndef __CLASS_PROCESS_CONTROLLER_H
#define __CLASS_PROCESS_CONTROLLER_H

#include "class_process_controller.h"
#include "class_board.h"
#include "class_decode.h"
#include "class_power.h"

typedef struct{
	float current_dc;
	float current_ac_dcen;
	float current_ac_dcep;
	float current_ac_zero;

	u16 time_ac_dcen;
	u16 time_ac_dcep;
	u16 time_ac_zero;

	u16 time_raise;
	u16 time_fall;
	u16 k_step;	

}Paramater_Current;

class	CProcontroller{
	public:
		CProcessBorad controller_board;
		CDecode       controller_decode;
	  CPower        controller_power;
	
		u16  time_process_fast;
		u16  time_process_slow;
		u16  time_process_now;
	
		CProcontroller(void);
		~CProcontroller(void);
	
		void process_init(void);
		
		bool process_timeout(u16 time);
		void process_time_clear(void);
		void process_timming_fast(void);
		void process_timming_slow(void);
		void process_decode_current(void);
	
		void process_current_dc_switch(Paramater_Current str_current);
		void process_current_dc_raise(Paramater_Current str_current);
		void process_current_dc_fall(Paramater_Current str_current);
		void process_current_ac_switch(Paramater_Current str_current);
		void process_current_ac_raise(Paramater_Current str_current);
		void process_current_ac_fall(Paramater_Current str_current);
};

#endif
