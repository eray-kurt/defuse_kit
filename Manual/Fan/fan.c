/**
  ******************************************************************************
  * @file           : fan.h
  * @brief          : Source file of fan peripherals and functions
  * @peripherals	: TIM1-CH1(PA8) | TIM1-CH2(PA9) | TIM3-CH1(PA6) | TIM3-CH2(PA7)
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 Rubigtech.
  * All rights reserved.
  *
  ******************************************************************************
  */

#include "fan.h"
#define FAN_1_REGISTER 				TIM1->CCR1
#define FAN_2_REGISTER 				TIM1->CCR2
#define FAN_OUTPUT_TIMER			htim1
#define FAN_RPM_TIMER				htim3
#define FAN_PERCENTAGE_MULTIPLIER	10
/*extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim3;*/
void fan_init(void)
{
	  HAL_TIM_PWM_Start(&FAN_OUTPUT_TIMER, TIM_CHANNEL_1);
	  HAL_TIM_PWM_Start(&FAN_OUTPUT_TIMER, TIM_CHANNEL_2);
	  HAL_TIM_IC_Start(&FAN_RPM_TIMER, TIM_CHANNEL_1);
	  HAL_TIM_IC_Start(&FAN_RPM_TIMER, TIM_CHANNEL_2);


	/*No Timer Init Timer has inited at main*/
}

void fan_process(defuseKitMgr* self)
{
	static uint8_t prevFanButtonState = LOW;
	static uint8_t currentFanButtonState = LOW;
	currentFanButtonState = self->canRxMessage.fanButtonState;
	if(prevFanButtonState != currentFanButtonState && currentFanButtonState == HIGH)
	{
		self->status.fanStatus = ON;
		self->status.lastActiveModule = FAN;
		self->canTxMessage.fanLedPin = HIGH;
	}
	if(self->status.lastActiveModule == FAN)
	{
		if(self->status.upButtonStatus == ON)
		{
			self->fanMgr.fanLevel = (self->fanMgr.fanLevel + FAN_STEP >= self->fanMgr.fanUpperLimit) ? self->fanMgr.fanUpperLimit : self->fanMgr.fanLevel + FAN_STEP;
			self->status.upButtonStatus = OFF;
		}
		else if(self->status.downButtonStatus == ON)
		{
			self->fanMgr.fanLevel = (self->fanMgr.fanLevel - FAN_STEP <= self->fanMgr.fanLowerLimit) ? self->fanMgr.fanLowerLimit : self->fanMgr.fanLevel - FAN_STEP;
			self->status.downButtonStatus = OFF;
		}
		fan_set_pwm(self->fanMgr.fanLevel);
	}
	prevFanButtonState = currentFanButtonState;
}

void turbo_process(defuseKitMgr* self)
{
	static uint8_t prevTurboButtonState = LOW;
		static uint8_t currentTurboButtonState = LOW;
		currentTurboButtonState = self->canRxMessage.fanButtonState;
		if(prevTurboButtonState != currentTurboButtonState && currentTurboButtonState == HIGH)
		{
			self->status.turboFanStatus = ON;
			self->status.lastActiveModule = TURBO;
			self->canTxMessage.turboLedPin = HIGH;
			fan_set_pwm(self->fanMgr.turboLevel);
		}
		prevTurboButtonState = currentTurboButtonState;
}

void fan_set_pwm(uint32_t pwmpercentage)
{
	uint32_t pwmValue = pwmpercentage * FAN_PERCENTAGE_MULTIPLIER;
	FAN_1_REGISTER = pwmValue;
	FAN_2_REGISTER = pwmValue;
}

void fan_read_rpm(uint32_t* rpmspeed)
{

}
