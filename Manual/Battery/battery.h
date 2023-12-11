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
#include "common.h"

/*ADC_HandleTypeDef* batteryOps = &hadc1;*/

void battery_init(void);
void battery_process(defuseKitMgr* self);

float battery_voltage_read(void);
float ops_battery_read(void);
float ups_battery_read(void);

#endif /*BATTERY_HEADER END*/
