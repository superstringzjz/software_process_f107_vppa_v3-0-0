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
	task_1(TRIGGER,DISCARE);//开始焊接
	task_2(TIMEOUT,1000);//送气
	task_3(TIMEOUT,1000);//预热
	task_4(TIMEOUT,1000);//初始
	task_5(TIMEOUT,1000);//上升
	task_6(TRIGGER,DISCARE);//焊接
	task_7(TIMEOUT,1000);//下降
	task_8(TIMEOUT,1000);//填充
	task_9(TIMEOUT,1000);//延时送气
}

void thread_process_500us(void){
	ctrl_timming_fast();
	ctrl_controller_io_scan();
	ctrl_controller_current();
	ctrl_decode_current();
	ctrl_controller_da_set();
	ctrl_controller_io_set();
}
