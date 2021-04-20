#include "interface.h"
#include "class_process_controller.h"

CProcontroller* m_cprocontroller = NULL;

void ctrl_controller_init(void){
	m_cprocontroller = new CProcontroller();
	m_cprocontroller->process_init();
}	

void ctrl_controller_io_set(void){
	m_cprocontroller->process_io_set();
}
void ctrl_controller_io_scan(void){
	m_cprocontroller->process_io_scan();
}
void ctrl_controller_da_set(void){
	m_cprocontroller->process_da_set();
}
void ctrl_timming_fast(void){
	m_cprocontroller->process_timming_fast();
}
void ctrl_timming_slow(void){
	m_cprocontroller->process_timming_slow();
}
void ctrl_controller_current(void){
	m_cprocontroller->process_current();
}



bool ctrl_timeout(u16 time){
	bool status;
	status = m_cprocontroller->process_timeout(time);
	return status;
}
void ctrl_time_clear(void){
	m_cprocontroller->process_time_clear();
}
bool ctrl_vppa_arcon(void){
	bool status;
	m_cprocontroller->process_vppa_power_on();
	status = m_cprocontroller->m_power.status_power_on;
	if(status==false) m_cprocontroller->time_process_now = 0;
	return status;
}
void ctrl_vppa_pregas(void){
}

void ctrl_vppa_ignite(void){
	m_cprocontroller->process_vppa_ignite();
}
void ctrl_vppa_init(void){
	m_cprocontroller->process_vppa_init();
}
void ctrl_vppa_raise(u16 time){
	m_cprocontroller->process_vppa_raise(time);
}
void ctrl_vppa_welding(void){
	m_cprocontroller->process_vppa_welding();
}
void ctrl_vppa_fall(u16 time){
	m_cprocontroller->process_vppa_fall(time);
}
void ctrl_vppa_fill(void){
	m_cprocontroller->process_vppa_fill();
}
void ctrl_vppa_delaygas(void){
	m_cprocontroller->process_vppa_delaygas();
}
