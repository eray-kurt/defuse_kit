/**
  ******************************************************************************
  * @file           : demister.c
  * @brief          : Source file of demister peripherals and functions
  * @peripherals	: GPIO (PB2)
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 Rubigtech.
  * All rights reserved.
  *
  ******************************************************************************
  */

#include "demister.h"

void demister_init(void)
{
 /*no init since gpio inited at main*/
}

void demister_process(defuseKitMgr* self)
{
	static uint8_t currentState = LOW;
	static uint8_t prevState = LOW;
	currentState = self->canRxMessage.demisterButtonState;
	if(currentState != prevState && currentState == HIGH)
	{
		if(self->status.demisterStatus == OFF)
		{
			demister_open();
			self->status.demisterStatus = ON;
		}
		else if(self->status.demisterStatus == ON)
		{
			demister_close();
			self->status.demisterStatus = OFF;
		}
		else
		{
			/*DEMISTER_STATUS_ERROR*/
		}

	}

	prevState = currentState;
}

void demister_toggle(void)
{
	HAL_GPIO_TogglePin(DEMISTER_GPIO_Port, DEMISTER_Pin);
}

void demister_open(void)
{
	HAL_GPIO_WritePin(DEMISTER_GPIO_Port, DEMISTER_Pin, GPIO_PIN_SET);
}

void demister_close(void)
{
	HAL_GPIO_WritePin(DEMISTER_GPIO_Port, DEMISTER_Pin, GPIO_PIN_RESET);
}

/*TODO create demister_write function*/
