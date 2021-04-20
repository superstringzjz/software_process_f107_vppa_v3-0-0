#include "class_decode.h"

CDecode::CDecode(){
	da_current_set = 0;
	counter_fast = 0;
	counter_slow = 0;
}

CDecode::~CDecode(){
}

void CDecode::decode_init(){
}

void CDecode::decode_current(float current){
	float temp32;
	u32   temp32_2;
	u16   temp16;
	temp32   = current*DA_WIDTH;
	temp32_2 = temp32;
	if((temp32_2%FULL_CURRENT)>=(FULL_CURRENT>>1)) temp16 = temp32_2/FULL_CURRENT+1;
	else                                           temp16 = temp32_2/FULL_CURRENT;
	if(temp16>DA_WIDTH) temp16=DA_WIDTH;
	da_current_set = temp16;
}

bool CDecode::decode_time_fast(void){
	counter_fast = counter_fast + 1;
	if(counter_fast == 2){
		counter_fast = 0;
		return true;
	}
	else
		return false;
}

bool CDecode::decode_time_slow(void){
	counter_slow = counter_slow + 1;
	if(counter_slow == 2){
		counter_slow = 0;
		return true;
	}
	else
		return false;
}

