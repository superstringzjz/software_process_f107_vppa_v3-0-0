#ifdef  __cplusplus
extern "C" {
#endif

#ifndef __BSP_NORMAL_PWM_H
#define __BSP_NORMAL_PWM_H
#include "BSP_Config.h"

bool bsp_normal_pwm_init(void);                 //��������pwm��ʼ��
void bsp_normal_pwm_on(void);                   //����pwm���
void bsp_normal_pwm_off(void);                  //�ر�pwm���
void bsp_normal_pwm_duty_set(u16 user_pwm_duty_1,u16 user_pwm_duty_2,u16 user_pwm_duty_3,u16 user_pwm_duty_4);
#endif
#ifdef  __cplusplus
}  
#endif
