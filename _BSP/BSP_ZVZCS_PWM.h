#ifdef  __cplusplus
extern "C" {
#endif

#ifndef __BSP_ZVZCS_PWM_H
#define __BSP_ZVZCS_PWM_H
#include "BSP_Config.h"

extern REG reg_zvzcs_pwm_status[8];
extern u16 zvzcs_pwm_duty;
extern u16 zvzcs_pwm_duty_shadow;

bool bsp_zvzcs_pwm_init(void);                 //死区互补pwm初始化
bool bsp_zvzcs_pwm_parameter_init(void);

void bsp_zvzcs_pwm_on(void);                   //开启pwm输出
void bsp_zvzcs_pwm_off(void);                  //关闭pwm输出
void bsp_zvzcs_pwm_duty_set(u16 user_pwm_duty);//更改pwm占空比
#endif
#ifdef  __cplusplus
}  
#endif
