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
ADC_HandleTypeDef* batteryAdcHandler = &hadc2;
ADC_ChannelConfTypeDef sBatteryOpsConfig = {0};
ADC_ChannelConfTypeDef sBatteryUpsConfig = {0};

void battery_init(void)
{
	/*MX_ADC1_Init();*/
	MX_ADC2_Init();

	/*config for battery ops*/
	sBatteryOpsConfig.Channel = ADC_CHANNEL_3;
	sBatteryOpsConfig.Rank = ADC_REGULAR_RANK_1;
	sBatteryOpsConfig.SamplingTime = ADC_SAMPLETIME_1CYCLE_5;

	/*config for battery ups*/
	sBatteryUpsConfig.Channel = ADC_CHANNEL_4;
	sBatteryUpsConfig.Rank = ADC_REGULAR_RANK_1;
	sBatteryUpsConfig.SamplingTime = ADC_SAMPLETIME_1CYCLE_5;
}

void battery_process(defuseKitMgr* self)
{
	self->batteryLevel = battery_voltage_read();

	self->canTxMessage.LED_BAR10_Pin = (self->batteryLevel > BATTERY_PERCENT90 && self->batteryLevel <= BATTERY_FULL) ? HIGH : LOW;
	self->canTxMessage.LED_BAR9_Pin = (self->batteryLevel > BATTERY_PERCENT80 && self->batteryLevel <= BATTERY_PERCENT90) ? HIGH : LOW;
	self->canTxMessage.LED_BAR8_Pin = (self->batteryLevel > BATTERY_PERCENT70 && self->batteryLevel <= BATTERY_PERCENT80) ? HIGH : LOW;
	self->canTxMessage.LED_BAR7_Pin = (self->batteryLevel > BATTERY_PERCENT60 && self->batteryLevel <= BATTERY_PERCENT70) ? HIGH : LOW;
	self->canTxMessage.LED_BAR6_Pin = (self->batteryLevel > BATTERY_PERCENT50 && self->batteryLevel <= BATTERY_PERCENT60) ? HIGH : LOW;
	self->canTxMessage.LED_BAR5_Pin = (self->batteryLevel > BATTERY_PERCENT40 && self->batteryLevel <= BATTERY_PERCENT50) ? HIGH : LOW;
	self->canTxMessage.LED_BAR4_Pin = (self->batteryLevel > BATTERY_PERCENT30 && self->batteryLevel <= BATTERY_PERCENT40) ? HIGH : LOW;
	self->canTxMessage.LED_BAR3_Pin = (self->batteryLevel > BATTERY_PERCENT20 && self->batteryLevel <= BATTERY_PERCENT30) ? HIGH : LOW;
	self->canTxMessage.LED_BAR2_Pin = (self->batteryLevel > BATTERY_PERCENT10 && self->batteryLevel <= BATTERY_PERCENT20) ? HIGH : LOW;
	self->canTxMessage.LED_BAR1_Pin = (self->batteryLevel <= BATTERY_PERCENT10) ? HIGH : LOW;
	self->status.batteryStatus = (self->batteryLevel <= BATTERY_PERCENT30) ? FAULT : ON;
}

float battery_voltage_read(void)
{
	float batteryVoltage = 0.0;
	float batteryOpsValue = 0.0;
	float batteryUpsValue = 0.0;

	batteryOpsValue = ops_battery_read();
	batteryUpsValue = ups_battery_read();

	if(batteryOpsValue >= batteryUpsValue)
	{
		batteryVoltage = batteryOpsValue;
	}
	else
	{
		batteryVoltage = batteryUpsValue;
	}

	return batteryVoltage;
}

float ops_battery_read(void)
{
	float batteryOpsValue = 0.0;

	HAL_ADC_ConfigChannel(batteryAdcHandler, &sBatteryOpsConfig);
	HAL_ADC_Start(batteryAdcHandler);
	HAL_ADC_PollForConversion(batteryAdcHandler, 1);
	batteryOpsValue = HAL_ADC_GetValue(batteryAdcHandler);
	HAL_ADC_Stop(batteryAdcHandler);

	/*TODO add filtering if necessary*/
	return batteryOpsValue;
}

float ups_battery_read(void)
{
	float batteryUpsValue = 0.0;

	HAL_ADC_ConfigChannel(batteryAdcHandler, &sBatteryUpsConfig);
	HAL_ADC_Start(batteryAdcHandler);
	HAL_ADC_PollForConversion(batteryAdcHandler, 1);
	batteryUpsValue = HAL_ADC_GetValue(batteryAdcHandler);
	HAL_ADC_Stop(batteryAdcHandler);

	/*TODO add filtering if necessary*/
	return batteryUpsValue;
}

/*TODO create battery read functions*/
