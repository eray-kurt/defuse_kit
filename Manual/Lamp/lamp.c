/**
  ******************************************************************************
  * @file           : lamp.h
  * @brief          : Source file of lamp peripherals and functions
  * @peripherals	: TIM1-CH3(PA10) | TIM1-CH4(PA11)
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 Rubigtech.
  * All rights reserved.
  *
  ******************************************************************************
  */
#include "lamp.h"
#define LAMP_1_REGISTER  			TIM1->CCR3
#define LAMP_2_REGISTER  			TIM1->CCR4
#define LAMP_PERCENTAGE_MULTIPLIER	10
void lamp_init(void)
{

}

void lamp_process(defuseKitMgr* self)
{
	static uint8_t prevLampButtonState = LOW;
		static uint8_t currentLampButtonState = LOW;
		currentLampButtonState = self->canRxMessage.lampButtonState;
		if(prevLampButtonState != currentLampButtonState && currentLampButtonState == HIGH)
		{
			self->status.lampStatus = ON;
			self->status.lastActiveModule = LAMP;
			self->canTxMessage.lampLedPin = HIGH;
			self->canTxMessage.lamp2LedPin = HIGH;
		}
		if(self->status.lastActiveModule == LAMP)
		{
			if(self->status.upButtonStatus == ON)
			{
				self->lampMgr.lampLevel = (self->lampMgr.lampLevel + LAMP_STEP >= self->lampMgr.lampUpperLimit) ? self->lampMgr.lampUpperLimit : self->lampMgr.lampLevel + LAMP_STEP;
				self->status.upButtonStatus = OFF;
			}
			else if(self->status.downButtonStatus == ON)
			{
				self->lampMgr.lampLevel = (self->lampMgr.lampLevel - LAMP_STEP <= self->lampMgr.lampLowerLimit) ? self->lampMgr.lampLowerLimit : self->lampMgr.lampLevel - LAMP_STEP;
				self->status.downButtonStatus = OFF;
			}
			lamp_set_pwm(self->lampMgr.lampLevel);
		}
		prevLampButtonState = currentLampButtonState;
}

void lamp_set_pwm(uint16_t pwm)
{
	LAMP_1_REGISTER  = pwm * LAMP_PERCENTAGE_MULTIPLIER;
	LAMP_1_REGISTER  = pwm * LAMP_PERCENTAGE_MULTIPLIER;
}
