/**
  ******************************************************************************
  * @file           : battery.h
  * @brief          : Header file of battery peripherals and functions
  * @peripherals	: ADC2_IN3 (PA3) | ADC2_IN4 (PA4)
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

/*ADC_HandleTypeDef* batteryOps = &hadc1;*/
/*ADC_HandleTypeDef* batteryUps = &hadc2;*/

void battery_init(void);

#endif /*BATTERY_HEADER END*/
