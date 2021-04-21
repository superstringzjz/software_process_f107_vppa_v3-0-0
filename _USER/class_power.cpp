#include "stm32f10x_conf.h"
#include "class_power.h"

CPower::CPower(void){
}

CPower::~CPower(void){
}

void CPower::power_init(){
		status_power_on = false;   //启动开关输入
		status_ignit_on = false;   //引弧开关输出
	  status_ignite_success = false;     //引弧成功输入   
		status_power_acdc = DC;     //ADDC状态
		status_power_old = POWER_OFF;      //前一个状态
		status_power_now = POWER_OFF;      //当前状态
		status_power_next = POWER_OFF;     //下一个状态
		status_power_ac_old = DCEN;   //AC阶段前一个状态
		status_power_ac_now = DCEN;   //AC阶段当前状态
		status_power_ac_next = DCEN;  //AC阶段下个一个状态
		
		time_now = 0;             //当前的周期时间
		time_k = 0;               //用于变化的时间
		time_ac_current_dcen = 0; //dcen时间
		time_ac_current_dcep = 0; //dcep时间
		time_ac_current_zero = 0; //过零时间
		time_dc_delta = 0;        //dc变化时间 ms
		time_dc_delta_step = 0;   //dc变化1步需要的时间 ms
		time_ac_delta = 0;        //ac变化时间 ms
		time_ac_delta_step = 0;   //ac变化1步需要的时间 ms
		
		current_set = 0;          //输出电流设定
		current_dc_set = 0;       //dc电流设定
		current_ac_dcen_set = 0;  //ac电流dcen设定
		current_ac_dcep_set = 0;  //ac电流dcep设定
		current_ac_zero_set = 0;  //ac电流zero设定
		current_dc_delta = 0;     //dc变化
		current_dc_delta_step = 0;
		current_ac_dcen_delta = 0;//dcen变化
		current_ac_dcen_delta_step = 0;
		current_ac_dcep_delta = 0;//dcep变化
		current_ac_dcep_delta_step = 0;
		
		k_slope = 0;//单位斜坡因子 1s50步
		
}

void CPower::power_dc(){
	time_k = 0;
	status_power_acdc = DC;
	status_power_now = POWER_DC;
}

void CPower::power_ac(){
	status_power_acdc = AC;
	status_power_now = POWER_AC;
}
void CPower::power_ac_raise(){
	time_ac_delta_step = time_ac_delta / k_slope;
	current_ac_dcen_delta = current_ac_dcen_goal - current_ac_dcen_set;
	current_ac_dcen_delta_step = current_ac_dcen_delta / k_slope;
	current_ac_dcep_delta = current_ac_dcep_goal - current_ac_dcep_set;
	current_ac_dcep_delta_step = current_ac_dcep_delta / k_slope;
	status_power_acdc = AC;
	status_power_now = POWER_AC_RAISE;
}
void CPower::power_ac_fall(){
	time_ac_delta_step = time_ac_delta / k_slope;
	current_ac_dcen_delta = current_ac_dcen_set - current_ac_dcen_goal ;
	current_ac_dcen_delta_step = current_ac_dcen_delta / k_slope;
	current_ac_dcep_delta = current_ac_dcep_set - current_ac_dcep_goal;
	current_ac_dcep_delta_step = current_ac_dcep_delta / k_slope;
	status_power_acdc = AC;
	status_power_now = POWER_AC_FALL;
}

void CPower::power_process(){
	switch (status_power_acdc){
  	case DC: //POWER_DC
			current_set = current_dc_set;
  	break;
  	case AC: //POWER_AC
			switch (status_power_ac_now){
				case DCEN:	//POWER_AC_DCEN
					current_set = current_ac_dcen_set;
					if(time_now>=time_ac_current_dcen){
						time_now = 0;
						current_set = current_ac_zero_set;
						status_power_ac_old = DCEN;
						status_power_ac_now = ZERO;
					}
				break;
				case DCEP:	//POWER_AC_DCEP
					current_set = current_ac_dcep_set;
					if(time_now>=time_ac_current_dcep){
						time_now = 0;
						current_set = current_ac_zero_set;
						status_power_ac_old = DCEP;
						status_power_ac_now = ZERO;
					}
				break;
				case ZERO://POWER_AC_ZERO
					current_set = current_ac_zero_set;
					if(time_now>=time_ac_current_zero){
						switch (status_power_ac_old){
							case DCEN:
								time_now = 0;
								current_set = current_ac_dcep_set;
								status_power_ac_old = ZERO;
								status_power_ac_now = DCEP;
							break;
							case DCEP:
								time_now = 0;
								current_set = current_ac_dcen_set;
								status_power_ac_old = ZERO;
								status_power_ac_now = DCEN;
							break;
							default:
							break;
						}
					}
				break;
				default:
				break;
			}
			//POWER_AC_RAISE
			if(status_power_now == POWER_AC_RAISE){
				if(time_k == time_ac_delta_step){
					time_k = 0;
					current_ac_dcen_set+=current_ac_dcen_delta_step;
					current_ac_dcep_set+=current_ac_dcep_delta_step;
				}
			}
			//POWER_AC_FALL
			if(status_power_now == POWER_AC_FALL){
				if(time_k == time_ac_delta_step){
					time_k = 0;
					current_ac_dcen_set-=current_ac_dcen_delta_step;
					current_ac_dcep_set-=current_ac_dcep_delta_step;
				}
			}
		break;
  	default:
  	break;
  }
}
