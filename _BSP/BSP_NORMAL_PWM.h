#ifdef  __cplusplus
extern "C" {
#endif

#ifndef __BSP_NORMAL_PWM_H
#define __BSP_NORMAL_PWM_H
#include "BSP_Config.h"

bool bsp_normal_pwm_init(void);                 //死区互补pwm初始化
void bsp_normal_pwm_on(void);                   //开启pwm输出
void bsp_normal_pwm_off(void);                  //关闭pwm输出
void bsp_normal_pwm_duty_set(u16 user_pwm_duty_1,u16 user_pwm_duty_2,u16 user_pwm_duty_3,u16 user_pwm_duty_4);
#endif
#ifdef  __cplusplus
}  
#endif
