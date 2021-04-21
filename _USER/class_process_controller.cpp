#include "stm32f10x_conf.h"
#include "class_process_controller.h"
#include "class_board.h"
#include "class_decode.h"
#include "class_power.h"

CProcontroller::CProcontroller(void){
	time_process_now = 0;
	time_process_fast = 0;
	time_process_slow = 0;

}

CProcontroller::~CProcontroller(void){
}

void CProcontroller::process_init(void){
	controller_board.board_init();
	controller_decode.decode_init();
	controller_power.power_init();
}

void CProcontroller::process_timming_fast(void){
	bool temp;
	temp = controller_decode.decode_time_fast();
	if(temp == true){
		controller_power.time_now = controller_power.time_now + 1;
		controller_power.time_k = controller_power.time_k + 1;
	}
}

void CProcontroller::process_timming_slow(void){
	bool temp;
	temp = controller_decode.decode_time_slow();
	if(temp == true){
		time_process_now = time_process_now + 1;
	}
}
bool CProcontroller::process_timeout(u16 time){
	if(time_process_now*10 >= time) return true;
	else                            return false;
}
void CProcontroller::process_time_clear(void){
	time_process_now = 0;
	controller_power.time_k = 0;
}
void CProcontroller::process_decode_current(void){
	controller_decode.real_current = controller_power.current_set;
	controller_decode.decode_current();
	controller_board.dac1_raw = controller_decode.da_current_set;
	controller_board.board_dac_set();
}

void CProcontroller::process_current_dc_switch(Paramater_Current str_current){
	controller_power.current_dc_set = str_current.current_dc;
	controller_power.power_dc();
}
void CProcontroller::process_current_dc_raise(Paramater_Current str_current){
}
void CProcontroller::process_current_dc_fall(Paramater_Current str_current){
}
void CProcontroller::process_current_ac_switch(Paramater_Current str_current){
	controller_power.current_ac_dcen_set = str_current.current_ac_dcen;
	controller_power.current_ac_dcep_set = str_current.current_ac_dcep;
	controller_power.current_ac_zero_set = str_current.current_ac_zero;
	controller_power.time_ac_current_dcen = str_current.time_ac_dcen;
	controller_power.time_ac_current_dcep = str_current.time_ac_dcep;
	controller_power.time_ac_current_zero = str_current.time_ac_zero;
	controller_power.power_ac();
}
void CProcontroller::process_current_ac_raise(Paramater_Current str_current){
	controller_power.current_ac_dcen_goal = str_current.current_ac_dcen;
	controller_power.current_ac_dcep_goal = str_current.current_ac_dcep;
	controller_power.k_slope = str_current.k_step;
	controller_power.time_ac_delta = str_current.time_raise;
	controller_power.power_ac_raise();
}
void CProcontroller::process_current_ac_fall(Paramater_Current str_current){
	controller_power.current_ac_dcen_goal = str_current.current_ac_dcen;
	controller_power.current_ac_dcep_goal = str_current.current_ac_dcep;
	controller_power.k_slope = str_current.k_step;
	controller_power.time_ac_delta = str_current.time_fall;
	controller_power.power_ac_fall();
}
