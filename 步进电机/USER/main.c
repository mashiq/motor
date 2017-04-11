#include "motor.h"
#include "gpio.h"
#include "key.h"
#include "stm32f10x_conf.h"
#include "delay.h"

#define PLY_1 GPIO_Pin_4
#define BUTTON_STOP   PLY_1

int main(void)
	{
		int reverse = 0;
		int stop = 0;
		SystemInit();  
		init_stepmotor_GPIO();	
		delay_init(72);
	  while (1)
	  {
		switch(is_key_pressed(BUTTON_STOP))
			{
			case 1:
						stop = !stop;
						reverse = reverse;
						break;
			case 0:
						reverse = !reverse;
						stop = stop;
						break;
			case 2:
						stop = stop;
						reverse = reverse;
						break;
			}
		if(!stop)
			{
				if(!reverse)
				{
				motor_forward_a_step();
				}
				else
				{
				motor_backward_a_step();
				}
			}
		 else
			{
		delay_ms(2);
			}
	  }
}
