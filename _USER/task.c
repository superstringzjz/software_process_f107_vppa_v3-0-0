#include "usercode.h"
#include "Interface.h"
#include "task.h"


u16  TASK_ID = 1;
bool TASK_ONCE_LOG = true;
bool TASK_LOOP_LOG = true;
/***************************************************/
void task_0(u8 type,u16 time){
	bool status = false;
	/***********用户参数***********/
	/***********用户参数***********/
	if(TASK_ID == 0){
		if(TASK_ONCE_LOG){
			/******前端接口函数******/
			
			/******前端接口函数******/
			TASK_ONCE_LOG = false;
		}
		if(TASK_LOOP_LOG){
			/******前端接口函数******/
			
			/******前端接口函数******/
		}
		if(type == TRIGGER){
			if(status) {
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
/***************************************************/

/***************************************************/
void task_1(u8 type,u16 time){
	bool status = false;
	if(TASK_ID == 1){
		if(TASK_ONCE_LOG){
			/******前端接口函数******/
			
			/******前端接口函数******/
			TASK_ONCE_LOG = false;
		}
		if(TASK_LOOP_LOG){
			/******前端接口函数******/
			status = ctrl_current_on();
			/******前端接口函数******/
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
/***************************************************/

/***************************************************/
void task_2(u8 type,u16 time){
	bool status = false;
	if(TASK_ID == 2){
		if(TASK_ONCE_LOG){
			/******前端接口函数******/
			
			/******前端接口函数******/
			TASK_ONCE_LOG = false;
		}
		if(TASK_LOOP_LOG){
			/******前端接口函数******/
			
			/******前端接口函数******/
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
/***************************************************/

/***************************************************/
void task_3(u8 type,u16 time){
	bool status = false;
	/***********用户参数***********/
	Paramater_Current str_current;
	/***********用户参数***********/
	if(TASK_ID == 3){
		if(TASK_ONCE_LOG){
			/******前端接口函数******/
			str_current.current_dc = 80;
			ctrl_current_dc_switch(str_current);
			/******前端接口函数******/
			TASK_ONCE_LOG = false;
		}
		if(TASK_LOOP_LOG){
			/******前端接口函数******/
			
			/******前端接口函数******/
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
/***************************************************/

/***************************************************/
void task_4(u8 type,u16 time){
	bool status = false;
	/***********用户参数***********/
	Paramater_Current str_current;
	/***********用户参数***********/
	if(TASK_ID == 4){
		if(TASK_ONCE_LOG){
			/******前端接口函数******/
			str_current.current_ac_dcen = 60;
			str_current.current_ac_dcep = 72;
			str_current.current_ac_zero = 120;
			str_current.time_ac_dcen = 20;
			str_current.time_ac_dcep = 3;
			str_current.time_ac_zero = 1;
			ctrl_current_ac_switch(str_current);
			/******前端接口函数******/
			TASK_ONCE_LOG = false;
		}
		if(TASK_LOOP_LOG){
			/******前端接口函数******/
			
			/******前端接口函数******/
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
/***************************************************/

/***************************************************/
void task_5(u8 type,u16 time){
	bool status = false;
	/***********用户参数***********/
	Paramater_Current str_current;
	/***********用户参数***********/
	if(TASK_ID == 5){
		if(TASK_ONCE_LOG){
			/******前端接口函数******/
			str_current.current_ac_dcen = 80;
			str_current.current_ac_dcep = 96;
			str_current.time_raise = time;
			str_current.k_step = 50;
			ctrl_current_ac_raise(str_current);
			/******前端接口函数******/
			TASK_ONCE_LOG = false;
		}
		if(TASK_LOOP_LOG){
			/******前端接口函数******/
			
			/******前端接口函数******/
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
/***************************************************/

/***************************************************/
void task_6(u8 type,u16 time){
	/***********用户参数***********/
	Paramater_Current str_current;
	/***********用户参数***********/
	bool status = false;
	if(TASK_ID == 6){
		if(TASK_ONCE_LOG){
			/******前端接口函数******/
			str_current.current_ac_dcen = 80;
			str_current.current_ac_dcep = 96;
			str_current.current_ac_zero = 120;
			str_current.time_ac_dcen = 20;
			str_current.time_ac_dcep = 3;
			str_current.time_ac_zero = 1;
			ctrl_current_ac_switch(str_current);
			/******前端接口函数******/
			TASK_ONCE_LOG = false;
		}
		if(TASK_LOOP_LOG){
			/******前端接口函数******/
			status = ctrl_current_welding_over();
			/******前端接口函数******/
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
/***************************************************/

/***************************************************/
void task_7(u8 type,u16 time){
	bool status = false;
	/***********用户参数***********/
	Paramater_Current str_current;
	/***********用户参数***********/
	if(TASK_ID == 7){
		if(TASK_ONCE_LOG){
			/******前端接口函数******/
			str_current.current_ac_dcen = 60;
			str_current.current_ac_dcep = 72;
			str_current.time_fall = time;
			str_current.k_step = 50;
			ctrl_current_ac_fall(str_current);
			/******前端接口函数******/
			TASK_ONCE_LOG = false;
		}
		if(TASK_LOOP_LOG){
			/******前端接口函数******/
			
			/******前端接口函数******/
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
/***************************************************/

/***************************************************/
void task_8(u8 type,u16 time){
	bool status = false;
	/***********用户参数***********/
	Paramater_Current str_current;
	/***********用户参数***********/
	if(TASK_ID == 8){
		if(TASK_ONCE_LOG){
			/******前端接口函数******/
			str_current.current_ac_dcen = 60;
			str_current.current_ac_dcep = 72;
			str_current.current_ac_zero = 120;
			str_current.time_ac_dcen = 20;
			str_current.time_ac_dcep = 3;
			str_current.time_ac_zero = 1;
			ctrl_current_ac_switch(str_current);
			/******前端接口函数******/
			TASK_ONCE_LOG = false;
		}
		if(TASK_LOOP_LOG){
			/******前端接口函数******/
			
			/******前端接口函数******/
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
/***************************************************/

/***************************************************/
void task_9(u8 type,u16 time){
	bool status = false;
	/***********用户参数***********/
	Paramater_Current str_current;
	/***********用户参数***********/
	if(TASK_ID == 9){
		if(TASK_ONCE_LOG){
			/******前端接口函数******/
			str_current.current_dc = 0;
			ctrl_current_dc_switch(str_current);
			ctrl_current_off();
			/******前端接口函数******/
			TASK_ONCE_LOG = false;
		}
		if(TASK_LOOP_LOG){
			/******前端接口函数******/
			
			/******前端接口函数******/
		}
		if(type == TRIGGER){
			if(status){
				TASK_ID = 1;
				ctrl_time_clear();
				TASK_ONCE_LOG = true;
			}
		}
		else if(type == TIMEOUT){
			if(ctrl_timeout(time)){
				TASK_ID = 1;
				ctrl_time_clear();
				TASK_ONCE_LOG = true;
			}
		}
	}
}
/***************************************************/
