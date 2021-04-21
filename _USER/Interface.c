#include "interface.h"
#include "class_process_controller.h"

CProcontroller* m_cprocontroller = NULL;
/*****************************************/
void ctrl_controller_init(void){
	m_cprocontroller = new CProcontroller();
	m_cprocontroller->process_init();
}	
/*****************************************/

/*****************************************/
void ctrl_controller_io_set(void){
	m_cprocontroller->controller_board.board_io_set();
}
void ctrl_controller_io_scan(void){
	m_cprocontroller->controller_board.board_io_scan();
}
void ctrl_controller_da_set(void){
	m_cprocontroller->controller_board.board_dac_set();
}
/*****************************************/

/*****************************************/
void ctrl_timming_fast(void){
	m_cprocontroller->process_timming_fast();
}
void ctrl_timming_slow(void){
	m_cprocontroller->process_timming_slow();
}
bool ctrl_timeout(u16 time){
	return m_cprocontroller->process_timeout(time);
}
void ctrl_time_clear(void){
	m_cprocontroller->process_time_clear();
}
void ctrl_decode_current(){
	m_cprocontroller->process_decode_current();
}

/*****************************************/

/*****************************************/
void ctrl_controller_current(void){
	m_cprocontroller->controller_power.power_process();
}
/*****************************************/

bool ctrl_current_on(){
	return m_cprocontroller->controller_board.io_in[1];
}
void ctrl_current_off(){
}
bool ctrl_current_welding_over(){
	bool status;
	status = m_cprocontroller->controller_board.io_in[1];
	return !status;
}

void ctrl_current_dc_switch(Paramater_Current str_current){
	m_cprocontroller->process_current_dc_switch(str_current);
}
void ctrl_current_dc_raise(Paramater_Current str_current){
		m_cprocontroller->process_current_dc_raise(str_current);
}
void ctrl_current_dc_fall(Paramater_Current str_current){
	m_cprocontroller->process_current_dc_fall(str_current);
}
void ctrl_current_ac_switch(Paramater_Current str_current){
	m_cprocontroller->process_current_ac_switch(str_current);
}
void ctrl_current_ac_raise(Paramater_Current str_current){
	m_cprocontroller->process_current_ac_raise(str_current);
}
void ctrl_current_ac_fall(Paramater_Current str_current){
	m_cprocontroller->process_current_ac_fall(str_current);
}
