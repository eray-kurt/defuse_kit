/**
  ******************************************************************************
  * @file           : fan.h
  * @brief          : Source file of fan peripherals and functions
  * @peripherals	: TIM1-CH1(PA8) | TIM1-CH2(PA9) | TIM3-CH1(PA6) | TIM3-CH2(PA7)
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 Rubigtech.
  * All rights reserved.
  *
  ******************************************************************************
  */

#include "fan.h"
#define FAN_1_REGISTER TIM1->CCR1
#define FAN_2_REGISTER TIM1->CCR2
/*extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim3;*/
void fan_init(void)
{
	  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
	  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
	  HAL_TIM_IC_Start(&htim3, TIM_CHANNEL_1);
	  HAL_TIM_IC_Start(&htim3, TIM_CHANNEL_2);
	/*No Timer Init Timer has inited at main*/
}

void fan_set_pwm(uint32_t pwmpercentage)
{
	uint32_t pwmValue = pwmpercentage * FAN_PERCENTAGE_MULTIPLIER;
	FAN_1_REGISTER = pwmValue;
	FAN_2_REGISTER = pwmValue;
}

void fan_read_rpm(uint32_t* rpmspeed)
{

}
