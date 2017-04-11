#include "key.h"
#include "stm32f10x_conf.h"
#include "delay.h"

int is_key_pressed(int pin)
{    
		int i=0;
		int flag=0;
	  static int last_io_ture_value[32] ={0};
		if(GPIO_ReadInputDataBit(GPIOB, pin)==0&flag==0)//���°���
		{
				if(i<15)
				{
					i++;
					delay_ms(100);
				}
				
				if(GPIO_ReadInputDataBit(GPIOB, pin) == last_io_ture_value[pin])//����
				{
					i=0;
					flag=1;
					last_io_ture_value[pin] = 0;
					return 1;//ֹͣ						
				}
				if(GPIO_ReadInputDataBit(GPIOB, pin))//�̰�
				{
					i=0;
					flag=1;
					return 0;//����
				}
		}
		if(GPIO_ReadInputDataBit(GPIOB, pin) && flag)//������ζ��Ǹߵ�ƽ,�ָ����б�־λ
		{
			i=0;
			flag=0;
			last_io_ture_value[pin] = 0;
		}
		return 2;
}
