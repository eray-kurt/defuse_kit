/**
  ******************************************************************************
  * @file           : battery.h
  * @brief          : Header file of battery peripherals
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 Rubigtech.
  * All rights reserved.
  *
  ******************************************************************************
  */
#ifndef BATTERY_HEADER
#define BATTERY_HEADER
#include "adc.h"

ADC_HandleTypeDef* batteryOps;
ADC_HandleTypeDef* batteryUps;

void battery_init(void);










#endif /*BATTERY_HEADER END*/
