#include "key.h"
#include "stm32f10x_conf.h"
#include "delay.h"

int is_key_pressed(int pin)
{    
		int i=0;
		int flag=0;
	  static int last_io_ture_value[32] ={0};
		if(GPIO_ReadInputDataBit(GPIOB, pin)==0&flag==0)//按下按键
		{
				if(i<15)
				{
					i++;
					delay_ms(100);
				}
				
				if(GPIO_ReadInputDataBit(GPIOB, pin) == last_io_ture_value[pin])//长按
				{
					i=0;
					flag=1;
					last_io_ture_value[pin] = 0;
					return 1;//停止						
				}
				if(GPIO_ReadInputDataBit(GPIOB, pin))//短按
				{
					i=0;
					flag=1;
					return 0;//反向
				}
		}
		if(GPIO_ReadInputDataBit(GPIOB, pin) && flag)//如果两次都是高电平,恢复所有标志位
		{
			i=0;
			flag=0;
			last_io_ture_value[pin] = 0;
		}
		return 2;
}
