/**
  ******************************************************************************
  * @file           : lamp.h
  * @brief          : Header file of lamp peripherals and functions
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
#include "common.h"

void lamp_init();
void lamp_process(defuseKitMgr* self);
void lamp_set_pwm(uint16_t pwm);

#endif /*LED_HEADER END*/
