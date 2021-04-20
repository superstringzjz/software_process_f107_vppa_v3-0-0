#include "stm32f10x_conf.h"
#include "class_process_controller.h"
#include "class_board.h"
#include "class_decode.h"
#include "class_power.h"

CProcontroller::CProcontroller(void){
	time_process_now = 0;
}

CProcontroller::~CProcontroller(void){
}

void CProcontroller::process_init(void){
	m_board.board_init();
	m_decode.decode_init();
	m_power.power_init();
}

void CProcontroller::process_io_set(void){
	m_board.board_io_set();
}

void CProcontroller::process_io_scan(void){
	m_board.board_io_scan();
}

void CProcontroller::process_da_set(void){
	m_decode.decode_current(this->m_power.current_set);
	m_board.value_dac1 = this->m_decode.da_current_set; 
	m_board.value_dac2 = 0;
	m_board.board_dac_set();
}
		
void CProcontroller::process_timming_fast(void){
	bool temp;
	temp = m_decode.decode_time_fast();
	if(temp == true){
		m_power.time_now = m_power.time_now + 1;
		m_power.time_k = m_power.time_k + 1;
	}
}

void CProcontroller::process_timming_slow(void){
	bool temp;
	temp = m_decode.decode_time_slow();
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
	m_power.time_k = 0;
}

void CProcontroller::process_current(void){
	m_power.power_process();
}

void CProcontroller::process_vppa_power_on(void){
	if(m_board.io_in[0] == 1){
		m_power.power_on();
	}
}

void CProcontroller::process_vppa_pre_gas(void){

}

void CProcontroller::process_vppa_ignite(void){
	if(m_power.status_ignit_on==true){
		m_power.power_dc(80);
		m_board.io_out[4] = true;
		m_board.io_out[0] = true;
	}
}

void CProcontroller::process_vppa_init(void){
	m_power.power_ac(60,72,120,21,4,1);
	if(m_power.status_power_ac_now==DCEN)	m_board.io_out[4] = true;
	if(m_power.status_power_ac_now==DCEP) m_board.io_out[4] = false;
}

void CProcontroller::process_vppa_raise(u16 time){
		m_power.power_ac_raise(80,96,time,50);
		if(m_power.status_power_ac_now==DCEN)	m_board.io_out[4] = true;
		if(m_power.status_power_ac_now==DCEP) m_board.io_out[4] = false;
}

void CProcontroller::process_vppa_welding(void){
		m_power.power_ac(80,96,120,21,4,1);
		if(m_power.status_power_ac_now==DCEN)	m_board.io_out[4] = true;
		if(m_power.status_power_ac_now==DCEP) m_board.io_out[4] = false;
}

void CProcontroller::process_vppa_fall(u16 time){
		m_power.power_ac_fall(60,72,time,50);
		if(m_power.status_power_ac_now==DCEN)	m_board.io_out[4] = true;
		if(m_power.status_power_ac_now==DCEP) m_board.io_out[4] = false;
}
void CProcontroller::process_vppa_fill(void){
		m_power.power_ac(60,72,120,21,4,1);
		if(m_power.status_power_ac_now==DCEN)	m_board.io_out[4] = true;
		if(m_power.status_power_ac_now==DCEP) m_board.io_out[4] = false;
}
void CProcontroller::process_vppa_delaygas(void){
		m_power.power_dc(0);
		m_board.io_out[4] = true;
		m_board.io_out[0] = false;
}












