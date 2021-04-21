#include "MSP_Config.h"

/*系统时钟设定*/
bool MSP_SYSTEM_CLOCK_Init(void){
	return true;
}

/*片上外设时钟开启 */
bool MSP_DEVICE_CLOCK_Init(void){
	/*开启APB1总线下外设时钟*/
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR,ENABLE);     //PWR时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_BKP,ENABLE);     //BKP时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_DAC,ENABLE);     //DAC时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);    //TIM2时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);    //TIM3时钟
	
	/*开启APB2总线下外设时钟*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);   //GPIOA时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);   //GPIOB时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);   //GPIOC时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD,ENABLE);   //GPIOD时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);   //GPIOE时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);    //AFIO时钟
	return true;
}

/*引脚重映射*/
bool MSP_IO_REMAP_Init(void){
	return true;
}

/*设置中断优先级分组*/
bool MSP_NVIC_PriorityGroupConfig(uint32_t NVIC_PriorityGroup){
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup);               //设置中断优先级
	return true;
}

/*系统中断初化*/
bool MSP_NVIC_Init(void){
	NVIC_InitTypeDef NVIC_InitStructure;                        //中断结构体
	
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;             //定时器3
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;   //优先级2
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;          //子优先级0
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;             //允许中断
	NVIC_Init(&NVIC_InitStructure);                             //中断初始化
	
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;             //定时器2中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;   //优先级3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;          //子优先级0
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;             //允许中断
	NVIC_Init(&NVIC_InitStructure);                             //中断初始化
	
	return true;
}                                        

