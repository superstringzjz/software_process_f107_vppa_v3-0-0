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
			TASK_ONCE_LOG = false;
		}
		if(TASK_LOOP_LOG){
			status = ctrl_vppa_arcon();
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

void task_1(u8 type,u16 time){
	bool status = false;
	if(TASK_ID == 1){
		if(TASK_ONCE_LOG == true){
			ctrl_vppa_pregas();
			TASK_ONCE_LOG = false;
		}
		if(TASK_LOOP_LOG){

		}
		if(type == TRIGGER){
			if(status){ 
				TASK_ID = TASK_ID + 1;
				ctrl_time_clear();
				TASK_ONCE_LOG = true;
			}
		}
		else if(type == TIMEOUT){
			if(ctrl_timeout(time)) {
				TASK_ID = TASK_ID + 1;
				ctrl_time_clear();			
				TASK_ONCE_LOG = true;
			}
		}
	}
}
void task_2(u8 type,u16 time){
	bool status = false;
	if(TASK_ID == 2){
		if(TASK_ONCE_LOG == true){
			TASK_ONCE_LOG = false;
		}
		if(TASK_LOOP_LOG){
			ctrl_vppa_ignite();
		}
		if(type == TRIGGER){
			if(status){ 
				TASK_ID = TASK_ID + 1;
				ctrl_time_clear();
				TASK_ONCE_LOG = true;
			}
		}
		else if(type == TIMEOUT){
			if(ctrl_timeout(time)){ 
				TASK_ID = TASK_ID + 1;
				ctrl_time_clear();
				TASK_ONCE_LOG = true;
			}
		}
	}
}
void task_3(u8 type,u16 time){
	bool status = false;
	if(TASK_ID == 3){
		if(TASK_ONCE_LOG == true){
			ctrl_vppa_init();
			TASK_ONCE_LOG = false;
		}
		if(TASK_LOOP_LOG){
		}
		if(type == TRIGGER){
			if(status){ 
				TASK_ID = TASK_ID + 1;
				ctrl_time_clear();
				TASK_ONCE_LOG = true;
			}
		}
		else if(type == TIMEOUT){
			if(ctrl_timeout(time)){ 
				TASK_ID = TASK_ID + 1;
				ctrl_time_clear();
				TASK_ONCE_LOG = true;
			}
		}
	}
}
void task_4(u8 type,u16 time){
	bool status = false;
	if(TASK_ID == 4){
		if(TASK_ONCE_LOG == true){
			ctrl_vppa_raise(time);
			TASK_ONCE_LOG = false;
		}
		if(TASK_LOOP_LOG){
		}
		if(type == TRIGGER){
			if(status){ 
				TASK_ID = TASK_ID + 1;
				ctrl_time_clear();
				TASK_ONCE_LOG = true;
			}
		}
		else if(type == TIMEOUT){
			if(ctrl_timeout(time)){ 
				TASK_ID = TASK_ID + 1;
				ctrl_time_clear();
				TASK_ONCE_LOG = true;
			}
		}
	}
}
void task_5(u8 type,u16 time){
	bool status = false;
	if(TASK_ID == 5){
		if(TASK_ONCE_LOG == true){
			ctrl_vppa_welding();
			TASK_ONCE_LOG = false;
		}
		if(TASK_LOOP_LOG){
		}
		if(type == TRIGGER){
			if(status){ 
				TASK_ID = TASK_ID + 1;
				ctrl_time_clear();
				TASK_ONCE_LOG = true;
			}
		}
		else if(type == TIMEOUT){
			if(ctrl_timeout(time)){ 
				TASK_ID = TASK_ID + 1;
				ctrl_time_clear();
				TASK_ONCE_LOG = true;
			}
		}
	}
}
void task_6(u8 type,u16 time){
	bool status = false;
	if(TASK_ID == 6){
		if(TASK_ONCE_LOG == true){
			ctrl_vppa_fall(time);
			TASK_ONCE_LOG = false;
		}
		if(TASK_LOOP_LOG){
		}
		if(type == TRIGGER){
			if(status){ 
				TASK_ID = TASK_ID + 1;
				ctrl_time_clear();
				TASK_ONCE_LOG = true;
			}
		}
		else if(type == TIMEOUT){
			if(ctrl_timeout(time)){ 
				TASK_ID = TASK_ID + 1;
				ctrl_time_clear();
				TASK_ONCE_LOG = true;
			}
		}
	}
}
void task_7(u8 type,u16 time){
	bool status = false;
	if(TASK_ID == 7){
		if(TASK_ONCE_LOG == true){
			TASK_ONCE_LOG = false;
		}
		if(TASK_LOOP_LOG){
			ctrl_vppa_fill();
		}
		if(type == TRIGGER){
			if(status){ 
				TASK_ID = TASK_ID + 1;
				ctrl_time_clear();
				TASK_ONCE_LOG = true;
			}
		}
		else if(type == TIMEOUT){
			if(ctrl_timeout(time)){ 
				TASK_ID = TASK_ID + 1;
				ctrl_time_clear();
				TASK_ONCE_LOG = true;
			}
		}
	}
}
void task_8(u8 type,u16 time){
	bool status = false;
	if(TASK_ID == 8){
		if(TASK_ONCE_LOG == true){
			TASK_ONCE_LOG = false;
		}
		if(TASK_LOOP_LOG){
			ctrl_vppa_delaygas();
		}
		if(type == TRIGGER){
			if(status){ 
				TASK_ID = 0;
				ctrl_time_clear();
				TASK_ONCE_LOG = true;
			}
		}
		else if(type == TIMEOUT){
			if(ctrl_timeout(time)){ 
				TASK_ID = 0;
				ctrl_time_clear();
				TASK_ONCE_LOG = true;
			}
		}
	}
}

