#ifndef __MOTOR__H
#define __MOTOR__H

#include "sys.h"
#include "stm32f10x.h"
#include "delay.h"

#define PLY_1 GPIO_Pin_4

#define MOTOR_PIN_A  GPIO_Pin_3
#define MOTOR_PIN_B  GPIO_Pin_5
#define MOTOR_PIN_C  GPIO_Pin_9
#define MOTOR_PIN_D  GPIO_Pin_10

void motor_forward_a_step(void);

void motor_backward_a_step(void);
void set_motor_pin(int a,int value);
void motor_forward_steps(int steps);
#endif 

