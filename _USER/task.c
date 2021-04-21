#include "usercode.h"
#include "Interface.h"
#include "task.h"


u16  TASK_ID = 1;
bool TASK_ONCE_LOG = true;
bool TASK_LOOP_LOG = true;
/***************************************************/
void task_0(u8 type,u16 time){
	bool status = false;
	/***********�û�����***********/
	/***********�û�����***********/
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
			/******ǰ�˽ӿں���******/
			
			/******ǰ�˽ӿں���******/
			TASK_ONCE_LOG = false;
		}
		if(TASK_LOOP_LOG){
			/******ǰ�˽ӿں���******/
			status = ctrl_current_on();
			/******ǰ�˽ӿں���******/
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
			/******ǰ�˽ӿں���******/
			
			/******ǰ�˽ӿں���******/
			TASK_ONCE_LOG = false;
		}
		if(TASK_LOOP_LOG){
			/******ǰ�˽ӿں���******/
			
			/******ǰ�˽ӿں���******/
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
	/***********�û�����***********/
	Paramater_Current str_current;
	/***********�û�����***********/
	if(TASK_ID == 3){
		if(TASK_ONCE_LOG){
			/******ǰ�˽ӿں���******/
			str_current.current_dc = 80;
			ctrl_current_dc_switch(str_current);
			/******ǰ�˽ӿں���******/
			TASK_ONCE_LOG = false;
		}
		if(TASK_LOOP_LOG){
			/******ǰ�˽ӿں���******/
			
			/******ǰ�˽ӿں���******/
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
	/***********�û�����***********/
	Paramater_Current str_current;
	/***********�û�����***********/
	if(TASK_ID == 4){
		if(TASK_ONCE_LOG){
			/******ǰ�˽ӿں���******/
			str_current.current_ac_dcen = 60;
			str_current.current_ac_dcep = 72;
			str_current.current_ac_zero = 120;
			str_current.time_ac_dcen = 20;
			str_current.time_ac_dcep = 3;
			str_current.time_ac_zero = 1;
			ctrl_current_ac_switch(str_current);
			/******ǰ�˽ӿں���******/
			TASK_ONCE_LOG = false;
		}
		if(TASK_LOOP_LOG){
			/******ǰ�˽ӿں���******/
			
			/******ǰ�˽ӿں���******/
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
	/***********�û�����***********/
	Paramater_Current str_current;
	/***********�û�����***********/
	if(TASK_ID == 5){
		if(TASK_ONCE_LOG){
			/******ǰ�˽ӿں���******/
			str_current.current_ac_dcen = 80;
			str_current.current_ac_dcep = 96;
			str_current.time_raise = time;
			str_current.k_step = 50;
			ctrl_current_ac_raise(str_current);
			/******ǰ�˽ӿں���******/
			TASK_ONCE_LOG = false;
		}
		if(TASK_LOOP_LOG){
			/******ǰ�˽ӿں���******/
			
			/******ǰ�˽ӿں���******/
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
	/***********�û�����***********/
	Paramater_Current str_current;
	/***********�û�����***********/
	bool status = false;
	if(TASK_ID == 6){
		if(TASK_ONCE_LOG){
			/******ǰ�˽ӿں���******/
			str_current.current_ac_dcen = 80;
			str_current.current_ac_dcep = 96;
			str_current.current_ac_zero = 120;
			str_current.time_ac_dcen = 20;
			str_current.time_ac_dcep = 3;
			str_current.time_ac_zero = 1;
			ctrl_current_ac_switch(str_current);
			/******ǰ�˽ӿں���******/
			TASK_ONCE_LOG = false;
		}
		if(TASK_LOOP_LOG){
			/******ǰ�˽ӿں���******/
			status = ctrl_current_welding_over();
			/******ǰ�˽ӿں���******/
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
	/***********�û�����***********/
	Paramater_Current str_current;
	/***********�û�����***********/
	if(TASK_ID == 7){
		if(TASK_ONCE_LOG){
			/******ǰ�˽ӿں���******/
			str_current.current_ac_dcen = 60;
			str_current.current_ac_dcep = 72;
			str_current.time_fall = time;
			str_current.k_step = 50;
			ctrl_current_ac_fall(str_current);
			/******ǰ�˽ӿں���******/
			TASK_ONCE_LOG = false;
		}
		if(TASK_LOOP_LOG){
			/******ǰ�˽ӿں���******/
			
			/******ǰ�˽ӿں���******/
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
	/***********�û�����***********/
	Paramater_Current str_current;
	/***********�û�����***********/
	if(TASK_ID == 8){
		if(TASK_ONCE_LOG){
			/******ǰ�˽ӿں���******/
			str_current.current_ac_dcen = 60;
			str_current.current_ac_dcep = 72;
			str_current.current_ac_zero = 120;
			str_current.time_ac_dcen = 20;
			str_current.time_ac_dcep = 3;
			str_current.time_ac_zero = 1;
			ctrl_current_ac_switch(str_current);
			/******ǰ�˽ӿں���******/
			TASK_ONCE_LOG = false;
		}
		if(TASK_LOOP_LOG){
			/******ǰ�˽ӿں���******/
			
			/******ǰ�˽ӿں���******/
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
	/***********�û�����***********/
	Paramater_Current str_current;
	/***********�û�����***********/
	if(TASK_ID == 9){
		if(TASK_ONCE_LOG){
			/******ǰ�˽ӿں���******/
			str_current.current_dc = 0;
			ctrl_current_dc_switch(str_current);
			ctrl_current_off();
			/******ǰ�˽ӿں���******/
			TASK_ONCE_LOG = false;
		}
		if(TASK_LOOP_LOG){
			/******ǰ�˽ӿں���******/
			
			/******ǰ�˽ӿں���******/
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
