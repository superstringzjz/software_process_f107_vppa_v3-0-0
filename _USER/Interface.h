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

void ctrl_controller_io_1_set(bool status);
void ctrl_controller_io_2_set(bool status);
void ctrl_controller_io_3_set(bool status);
void ctrl_controller_io_4_set(bool status);
void ctrl_controller_io_5_set(bool status);
void ctrl_controller_io_6_set(bool status);
void ctrl_controller_io_7_set(bool status);
void ctrl_controller_io_8_set(bool status);

void ctrl_controller_current(void);
bool ctrl_trigger(void);
bool ctrl_timeout(u16 time);
void ctrl_time_clear(void);

bool ctrl_vppa_arcon(void);
void ctrl_vppa_pregas(void);
void ctrl_vppa_ignite(void);
void ctrl_vppa_init(void);
void ctrl_vppa_raise(u16 time);
void ctrl_vppa_welding(void);
void ctrl_vppa_fall(u16 time);
void ctrl_vppa_fill(void);
void ctrl_vppa_delaygas(void);

void debug_ctrl_io_4_set(bool status);
	
#endif
#ifdef  __cplusplus
}  
#endif
