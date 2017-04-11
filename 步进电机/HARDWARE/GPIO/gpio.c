#include "gpio.h"
#include "stm32f10x_conf.h"

void init_stepmotor_GPIO(void)
{
	GPIO_InitTypeDef GPIO_InitStructure; 

      RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
      GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   
      GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;   
      GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9|GPIO_Pin_10;   //CD
      GPIO_Init(GPIOA,&GPIO_InitStructure);
		
			RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
      GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   
      GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;   
      GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3|GPIO_Pin_5;  	//AB
      GPIO_Init(GPIOB,&GPIO_InitStructure);
	
			GPIO_SetBits(GPIOB,GPIO_Pin_3);		//A
			GPIO_ResetBits(GPIOB,GPIO_Pin_5);	//B
			GPIO_ResetBits(GPIOA,GPIO_Pin_9);	//C
			GPIO_SetBits(GPIOA,GPIO_Pin_10);	//D	
	
			RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
      GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;  
      GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;   
      GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;								//STOP
      GPIO_Init(GPIOB,&GPIO_InitStructure);
}
