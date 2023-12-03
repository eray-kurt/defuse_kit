/**
  ******************************************************************************
  * @file           : battery.c
  * @brief          : Source file of battery peripherals and functions
  * @peripherals	: ADC2_IN3 (PA3) | ADC2_IN4 (PA4)
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
	/*MX_ADC1_Init();*/
	MX_ADC2_Init();
}

/*TODO create battery read functions*/
