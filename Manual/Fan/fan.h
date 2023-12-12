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
#include "common.h"

void fan_init(void);
void fan_process(defuseKitMgr* self);
void turbo_process(defuseKitMgr* self);
void fan_set_pwm(uint32_t pwmpercentage);
void fan_read_rpm(uint32_t* rpmspeed);

#endif /*FAN_HEADER END*/
