#include "usercode.h"
#include "interface.h"
#include "class_board.h"
#include "task.h"

void user_init(void){
	ctrl_controller_init();
}

void user_once(void){
}

void user_ntr(void){
}

void thread_hmi_5000us(void){
	ctrl_timming_slow();
}

void thread_process_500us(void){
	ctrl_controller_io_scan();
	
	ctrl_timming_fast();
	ctrl_controller_da_set();
	ctrl_controller_io_set();
}
