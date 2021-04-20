#ifdef  __cplusplus
extern "C" {
#endif

#ifndef __BSP_ZVZCS_PWM_H
#define __BSP_ZVZCS_PWM_H
#include "BSP_Config.h"

extern REG reg_zvzcs_pwm_status[8];
extern u16 zvzcs_pwm_duty;
extern u16 zvzcs_pwm_duty_shadow;

bool bsp_zvzcs_pwm_init(void);                 //��������pwm��ʼ��
bool bsp_zvzcs_pwm_parameter_init(void);

void bsp_zvzcs_pwm_on(void);                   //����pwm���
void bsp_zvzcs_pwm_off(void);                  //�ر�pwm���
void bsp_zvzcs_pwm_duty_set(u16 user_pwm_duty);//����pwmռ�ձ�
#endif
#ifdef  __cplusplus
}  
#endif
