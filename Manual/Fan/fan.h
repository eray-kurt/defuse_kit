/**
  ******************************************************************************
  * @file           : fan.h
  * @brief          : Header file of fan peripherals and functions
  * @peripherals	: TIM1-CH1(PA8) | TIM1-CH2(PA9)
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 Rubigtech.
  * All rights reserved.
  *
  ******************************************************************************
  */

#ifndef FAN_HEADER
#define FAN_HEADER
#include "tim.h"

void fan_init(void);

void fan_set_pwm(uint16_t pwm);

#endif /*FAN_HEADER END*/
