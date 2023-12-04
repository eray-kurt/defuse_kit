/**
  ******************************************************************************
  * @file           : led.h
  * @brief          : Header file of led peripherals and functions
  * @peripherals	: TIM1-CH3(PA10) | TIM1-CH4(PA11)
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 Rubigtech.
  * All rights reserved.
  *
  ******************************************************************************
  */

#ifndef LED_HEADER
#define LED_HEADER
#include "tim.h"

void led_init();
void led_set_pwm(uint16_t pwm);

#endif /*LED_HEADER END*/
