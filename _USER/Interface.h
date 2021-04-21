#ifdef  __cplusplus
extern "C" {
#endif

#ifndef __INTERFACE_H
#define __INTERFACE_H
#include "stm32f10x.h"
#include "stm32f10x_conf.h"
#include "class_process_controller.h"

typedef struct{
	u16 current_dc;
	u16 current_ac_dcen;
	u16 current_ac_dcep;
	u16 current_ac_zero;

	u16 time_ac_dcen;
	u16 time_ac_dcep;
	u16 time_ac_zero;

	u16 time_raise;
	u16 time_fall;
	u16 k_step;	

}Paramater_Current;

typedef struct{
	u16 value_gas;
	u16 time_raise;
	u16 time_fall;
	u16 k_step;	
}Paramater_Gas;

void ctrl_controller_init(void);	
void ctrl_controller_io_set(void);
void ctrl_controller_io_scan(void);
void ctrl_controller_da_set(void);

void ctrl_timming_fast(void);
void ctrl_timming_slow(void);
void ctrl_time_clear(void);
bool ctrl_timeout(u16 time);

//bool ctrl_current_on();
//void ctrl_current_off();
//void ctrl_current_dc_switch(Paramater_Current str_current);
//void ctrl_current_dc_raise(Paramater_Current str_current);
//void ctrl_current_dc_fall(Paramater_Current str_current);
//void ctrl_current_ac_switch(Paramater_Current str_current);
//void ctrl_current_ac_raise(Paramater_Current str_current);
//void ctrl_current_ac_fall(Paramater_Current str_current);

//bool ctrl_gas_on();
//void ctrl_gas_off();
//void ctrl_gas_switch(Paramater_Gas str_gas);
//void ctrl_gas_raise(Paramater_Gas str_gas);
//void ctrl_gas_fall(Paramater_Gas str_gas);

void ctrl_controller_current(void);
//void ctrl_controller_gas(void);

//bool ctrl_vppa_arcon(void);
//void ctrl_vppa_pregas(void);
//void ctrl_vppa_ignite(void);
//void ctrl_vppa_init(void);
//void ctrl_vppa_raise(u16 time);
//void ctrl_vppa_welding(void);
//void ctrl_vppa_fall(u16 time);
//void ctrl_vppa_fill(void);
//void ctrl_vppa_delaygas(void);

	
#endif
#ifdef  __cplusplus
}  
#endif
