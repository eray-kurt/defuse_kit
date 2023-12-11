/**
  ******************************************************************************
  * @file           : led.h
  * @brief          : Source file of led peripherals and functions
  * @peripherals	: TIM1-CH3(PA10) | TIM1-CH4(PA11)
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 Rubigtech.
  * All rights reserved.
  *
  ******************************************************************************
  */
#include "led.h"
#define LED_1_REGISTER  &TIM1->CCR3
#define LED_2_REGISTER  &TIM1->CCR4
void led_init(void)
{

}

void led_process(defuseKitMgr* self)
{

}

void led_set_pwm(uint16_t pwm)
{

}
