#ifndef __CLASS_POWER_H
#define __CLASS_POWER_H

#define AC    0
#define DC    1

#define DCEN  0
#define DCEP  1
#define ZERO  2

#define POWER_ON       0
#define POWER_OFF      1
#define POWER_DC       2
#define POWER_AC       3
#define POWER_DC_RAISE 4
#define POWER_DC_FALL  5
#define POWER_AC_RAISE 6
#define POWER_AC_FALL  7

class	CPower{
	public:
	
		bool   status_power_on;         //启动开关输入
		bool   status_ignit_on;         //引弧开关输出
	  bool   status_ignite_success;   //引弧成功输入   
		
		u8 status_power_acdc;     //ADDC状态
	
		u8 status_power_old;      //前一个状态
		u8 status_power_now;      //当前状态
		u8 status_power_next;     //下一个状态
		
		u8 status_power_ac_old;   //AC阶段前一个状态
		u8 status_power_ac_now;   //AC阶段当前状态
		u8 status_power_ac_next;  //AC阶段下一个状态

		int time_now;             //当前的周期时间 ms
		int time_k;               //用于变化的时间 ms
	
		int time_ac_current_dcen; //dcen时间   ms
		int time_ac_current_dcep; //dcep时间   ms
		int time_ac_current_zero; //过零时间   ms

		int time_dc_delta;        //dc变化时间 ms
		int time_dc_delta_step;   //dc变化1步需要的时间 ms
		int time_ac_delta;        //ac变化时间 ms
		int time_ac_delta_step;   //ac变化1步需要的时间 ms
	
		float current_set;          //输出电流设定
		float current_dc_set;       //dc电流设定
		float current_ac_dcen_set;  //ac电流dcen设定
		float current_ac_dcep_set;  //ac电流dcep设定
		float current_ac_zero_set;  //ac电流zero设定
		float current_dc_delta;                    //dc变化
		float current_dc_delta_step;
		float current_ac_dcen_delta;               //dcen变化
		float current_ac_dcen_delta_step;
		float current_ac_dcep_delta;               //dcep变化
		float current_ac_dcep_delta_step;
		
		u16 current_ac_dcen_goal;
		u16 current_ac_dcep_goal;
		u16 k_slope;             //单位斜坡因子

		CPower(); //构造函数
		~CPower();  //析构函数

		void power_init();       
		
		void power_dc();
		void power_ac();
		void power_ac_raise();
		void power_ac_fall();

		void power_process();
};

#endif
