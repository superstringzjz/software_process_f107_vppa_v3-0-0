#include "usercode.h"
#include "task.h"
#include "Interface.h"

u16  TASK_ID = 0;
bool TASK_ONCE_LOG = true;
bool TASK_LOOP_LOG = true;

void task_0(u8 type,u16 time){
	bool status = false;
	if(TASK_ID == 0){
		if(TASK_ONCE_LOG){
			/******ǰ�˽ӿں���******/
			
			/******ǰ�˽ӿں���******/
			TASK_ONCE_LOG = false;
		}
		if(TASK_LOOP_LOG){
			/******ǰ�˽ӿں���******/
			
			/******ǰ�˽ӿں���******/
		}
		if(type == TRIGGER){
			if(status) TASK_ID = TASK_ID + 1;
			ctrl_time_clear();
			TASK_ONCE_LOG = true;
		}
		else if(type == TIMEOUT){
			if(ctrl_timeout(time)) TASK_ID = TASK_ID + 1;
			ctrl_time_clear();
			TASK_ONCE_LOG = true;
		}
	}
}
