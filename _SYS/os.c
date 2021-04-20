#include "stm32f10x_conf.h"
#include "os.h"
#include "usercode.h"

u32  counter_system_run;     //������ʾϵͳ����ָʾ�Ƶ����������   

bool os_init(void){
	bool status;
	/**************************************************************/
	status = bsp_core_init();                         //bsp�ص�����
	/**************************************************************/
	status = os_led_init();                           //led�Ƴ�ʼ��
	/**************************************************************/
	return status;
}

bool os_thread_start(void){
	bool status;
	status = bsp_tim_2_init();                        //bsp�ص�����
	status = bsp_tim_3_init();                        //bsp�ص�����

	status = bsp_time2_start();
	if(status == false) return false;         
	status = bsp_time3_start();
	if(status == false) return false;
	
	return true;

}
bool os_led_init(void){
	bool status;
	/**************************************************************/
	status = bsp_osled_init();           //bsp�ص�����
	/**************************************************************/
	counter_system_run = 0;              //ָʾϵͳ����״̬�ļ�����
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
	os_thread_start();                       //ϵͳ�߳�����
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
