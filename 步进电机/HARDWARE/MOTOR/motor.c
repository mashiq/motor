#include "motor.h"
#include "stm32f10x_conf.h"

/*������������ÿ������5.625�ȣ���תһȦҪ64����*/

void set_motor_pin(int a,int value)
{
	switch(a)
   {
		 case 0:
		       GPIO_WriteBit(GPIOB, MOTOR_PIN_A, value);//B4
			   break;
		 case 1:
		       GPIO_WriteBit(GPIOB, MOTOR_PIN_B, value);//A9
		       break;
		 case 2:
		       GPIO_WriteBit(GPIOA, MOTOR_PIN_C, value);//A10
		       break;
		 case 3:
		       GPIO_WriteBit(GPIOA, MOTOR_PIN_D, value);//B3
		       break;
   }
}

static void _motor_rorate_a_step(int table[6][4])
{
    
    int i,j;

    for ( i = 0 ; i < 6; i++)
    {  
       for (j =0; j < 4; j++)
       {  
          set_motor_pin(j,table[i][j]);
			 }
       
       delay_ms(2);
    } 

}

void motor_forward_a_step()//��תһ��
{
    int table[][4]= {
					{1,0,0,1},
                    {1,1,0,0},
                    {0,1,1,0},
                    {0,0,1,1},
                    {1,0,0,1},
					{0,0,0,0}
                    };
   _motor_rorate_a_step(table);//תһ��
}

void motor_backward_a_step()//��ת
{
    int table[][4]= {
		             {1,1,0,0},
                     {1,0,0,1},
                     {0,0,1,1},
                     {0,1,1,0},
                     {1,1,0,0},
					 {0,0,0,0}
                    };
   _motor_rorate_a_step(table);  
}


//void motor_forward_steps(int steps)//�涨תstep��
//{
//    int i=0;
//    for(i=0;i< steps;i++)
//    {
//        motor_forward_a_step();
//    }
//}

