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
	
		bool   status_power_on;         //������������
		bool   status_ignit_on;         //�����������
	  bool   status_ignite_success;   //�����ɹ�����   
		
		u8 status_power_acdc;     //ADDC״̬
	
		u8 status_power_old;      //ǰһ��״̬
		u8 status_power_now;      //��ǰ״̬
		u8 status_power_next;     //��һ��״̬
		
		u8 status_power_ac_old;   //AC�׶�ǰһ��״̬
		u8 status_power_ac_now;   //AC�׶ε�ǰ״̬
		u8 status_power_ac_next;  //AC�׶���һ��״̬

		int time_now;             //��ǰ������ʱ�� ms
		int time_k;               //���ڱ仯��ʱ�� ms
	
		int time_ac_current_dcen; //dcenʱ��   ms
		int time_ac_current_dcep; //dcepʱ��   ms
		int time_ac_current_zero; //����ʱ��   ms
		int time_dc_delta;        //dc�仯ʱ�� ms
	
		int time_dc_delta_step;   //dc�仯1����Ҫ��ʱ�� ms
		int time_ac_delta;        //ac�仯ʱ�� ms
		int time_ac_delta_step;   //ac�仯1����Ҫ��ʱ�� ms
	
		float current_set;          //��������趨
		float current_dc_set;       //dc�����趨
		float current_ac_dcen_set;  //ac����dcen�趨
		float current_ac_dcep_set;  //ac����dcep�趨
		float current_ac_zero_set;  //ac����zero�趨
		float current_dc_delta;                    //dc�仯
		float current_dc_delta_step;
		float current_ac_dcen_delta;               //dcen�仯
		float current_ac_dcen_delta_step;
		float current_ac_dcep_delta;               //dcep�仯
		float current_ac_dcep_delta_step;
		
		u16 k_slope;             //��λб������

		CPower(); //���캯��
		~CPower();  //��������

		void power_init();       
    void power_on();
		bool power_ignite_success();
		void power_off();
		
		void power_dc(u16 current);
		void power_ac(u16 current_dcen,u16 current_dcep,u16 current_zero,u16 time_decn,u16 time_dcep,u16 time_zero);
		void power_ac_raise(u16 current_dcen_goal,u16 current_dcep_goal,u16 time,u16 k);
		void power_ac_fall(u16 current_dcen_goal,u16 current_dcep_goal,u16 time,u16 k);

		void power_process();
};

#endif
