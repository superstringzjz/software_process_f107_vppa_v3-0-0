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
	m_cprocontroller->process_io_set();
}
void ctrl_controller_io_scan(void){
	m_cprocontroller->process_io_scan();
}
void ctrl_controller_da_set(void){
	m_cprocontroller->process_da_set();
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
/*****************************************/

/*****************************************/
void ctrl_controller_current(void){
	m_cprocontroller->process_current();
}
/*****************************************/
