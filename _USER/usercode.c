#include "usercode.h"
#include "interface.h"
#include "class_board.h"
#include "task.h"

bool user_init(void){
	bool status = true;
	ctrl_controller_init();
	if(status == false) return false;
	return true;
}

void user_once(void){
}

void user_ntr(void){
}

void thread_hmi_5000us(void){
	ctrl_timming_slow();
	task_0(TRIGGER,DISCARE);  //��
	task_1(TIMEOUT,1000);     //����ms
	task_2(TIMEOUT,1000);     //ֱ��ms
	task_3(TIMEOUT,1000);     //��ʼms
	task_4(TIMEOUT,1000);     //����ms
	task_5(TIMEOUT,4000);     //����ms
	task_6(TIMEOUT,1000);     //�½�ms
	task_7(TIMEOUT,1000);     //���ms
	task_8(TIMEOUT,1000);     //��ʱms
}

void thread_process_500us(void){
	ctrl_timming_fast();
	ctrl_controller_current();
	ctrl_controller_io_scan();
	ctrl_controller_io_set();
	ctrl_controller_da_set();
}
