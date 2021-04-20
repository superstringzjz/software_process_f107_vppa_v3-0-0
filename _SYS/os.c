#include "stm32f10x_conf.h"
#include "os.h"
#include "usercode.h"

u32  counter_system_run;     //用于提示系统运行指示灯的软件计数器   

bool os_init(void){
	bool status;
	/**************************************************************/
	status = bsp_core_init();                         //bsp回调函数
	/**************************************************************/
	status = os_led_init();                           //led灯初始化
	/**************************************************************/
	return status;
}

bool os_thread_start(void){
	bool status;
	status = bsp_tim_2_init();                        //bsp回调函数
	status = bsp_tim_3_init();                        //bsp回调函数

	status = bsp_time2_start();
	if(status == false) return false;         
	status = bsp_time3_start();
	if(status == false) return false;
	
	return true;

}
bool os_led_init(void){
	bool status;
	/**************************************************************/
	status = bsp_osled_init();           //bsp回调函数
	/**************************************************************/
	counter_system_run = 0;              //指示系统运行状态的计数器
	return status;
}

void os_led_run(){
	counter_system_run++;
	if(counter_system_run>0 && counter_system_run <80000)
		bsp_osled_on();
	else if(counter_system_run >80000)
		bsp_osled_off();
	if(counter_system_run == 160000)
		counter_system_run = 0;
}

void os_once(void){
	os_thread_start();                       //系统线程启动
}
void os_nrt(void){
	os_led_run();
}
void os_5000us(void){
}
void os_500us(void){
}
void os_50us(void){
}
