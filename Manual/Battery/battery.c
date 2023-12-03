/**
  ******************************************************************************
  * @file           : battery.c
  * @brief          : Source file of battery peripherals
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 Rubigtech.
  * All rights reserved.
  *
  ******************************************************************************
  */

#include "battery.h"


void battery_init(void)
{
	batteryOps = &hadc1;
	batteryUps = &hadc2;

	MX_ADC1_Init();
	MX_ADC2_Init();
}
