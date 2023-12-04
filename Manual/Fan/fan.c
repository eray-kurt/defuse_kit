/**
  ******************************************************************************
  * @file           : fan.h
  * @brief          : Source file of fan peripherals and functions
  * @peripherals	: TIM1-CH1(PA8) | TIM1-CH2(PA9)
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 Rubigtech.
  * All rights reserved.
  *
  ******************************************************************************
  */

#include "fan.h"
uint32_t* FAN_1_REGISTER = &TIM1->CCR1;
uint32_t* FAN_2_REGISTER = &TIM1->CCR2;
void fan_init(void)
{
	/*No Timer Init Timer has inited at main*/
}

void fan_set_pwm(uint16_t pwm)
{

}
