#ifndef __CLASS_PROCESS_CONTROLLER_H
#define __CLASS_PROCESS_CONTROLLER_H

#include "class_process_controller.h"
#include "class_board.h"

class	CProcontroller{
	public:
		CProcessBorad*  controller_board;
	
		u16  time_process_fast;
		u16  time_process_slow;
		u16  time_process_now;
	
		CProcontroller(void);
		~CProcontroller(void);
	
		void process_init(void);

		void process_io_set(void);
		void process_io_scan(void);
		void process_da_set(void);
			
		bool process_timeout(u16 time);
		void process_time_clear(void);
		void process_timming_fast(void);
		void process_timming_slow(void);

		void process_vppa_power_on(void);
		void process_vppa_pre_gas(void);
		void process_vppa_ignite(void);
		void process_vppa_init(void);
		void process_vppa_raise(u16 time);
		void process_vppa_welding(void);
		void process_vppa_fall(u16 time);
		void process_vppa_fill(void);
		void process_vppa_delaygas(void);
		
		void process_current(void);
		
};

#endif
