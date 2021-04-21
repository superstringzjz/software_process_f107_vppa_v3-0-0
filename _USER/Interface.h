#ifdef  __cplusplus
extern "C" {
#endif

#ifndef __INTERFACE_H
#define __INTERFACE_H
#include "stm32f10x.h"
#include "stm32f10x_conf.h"
#include "class_process_controller.h"

void ctrl_controller_init(void);	
void ctrl_controller_io_set(void);
void ctrl_controller_io_scan(void);
void ctrl_controller_da_set(void);

void ctrl_timming_fast(void);
void ctrl_timming_slow(void);
void ctrl_time_clear(void);
bool ctrl_timeout(u16 time);

void ctrl_decode_current(void);
	
bool ctrl_current_on();
bool ctrl_current_welding_over();
void ctrl_current_off();
void ctrl_current_dc_switch(Paramater_Current str_current);
void ctrl_current_dc_raise(Paramater_Current str_current);
void ctrl_current_dc_fall(Paramater_Current str_current);
void ctrl_current_ac_switch(Paramater_Current str_current);
void ctrl_current_ac_raise(Paramater_Current str_current);
void ctrl_current_ac_fall(Paramater_Current str_current);


void ctrl_controller_current(void);

#endif
#ifdef  __cplusplus
}  
#endif
