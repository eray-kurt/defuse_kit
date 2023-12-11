/**
  ******************************************************************************
  * @file           : defuseKitMgr.c
  * @brief          : Source file of defuse kit manager
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 Rubigtech.
  * All rights reserved.
  *
  ******************************************************************************
  */
#include "defuseKitMgr.h"
defuseKitMgr self;

void defuseKitMgr_init(void)
{
	/*TODO create necessary peripherals and tasks*/
	battery_init();
	can_bus_init();
	demister_init();
	fan_init();
	led_init();
	speaker_init();
	/*TODO set default values or get them from flash*/

	memset(&self.canRxMessage, 0, sizeof(self.canRxMessage));
	memset(&self.canTxMessage, 0, sizeof(self.canTxMessage));

	self.status.powerStatus = OFF;
	self.status.batteryStatus = OFF;
	self.status.fanStatus = OFF;
	self.status.turboFanStatus = OFF;
	self.status.lampStatus = OFF;
	self.status.soundStatus = OFF;
	self.status.demisterStatus = OFF;

	self.batteryLevel = BATTERY_FULL;

	self.fanMgr.fanLowerLimit = FAN_LOWER_DEFAULT;
	self.fanMgr.fanUpperLimit = FAN_UPPER_DEFAULT;
	self.fanMgr.fanLevel = FAN_LOWER_DEFAULT;
	self.fanMgr.turboLevel = FAN_TURBO_DEFAULT;

	self.ledMgr.ledLowerLimit = LED_LOWER_DEFAULT;
	self.ledMgr.ledUpperLimit = LED_UPPER_DEFAULT;
	self.ledMgr.ledLevel = LED_LOWER_DEFAULT;

	/*TODO add sound defaults*/

	/*int a = sizeof(self.canTxMessage);
	int b = sizeof(self.canRxMessage);
	int c = sizeof(self);*/
	/*TODO start the tasks*/
}


void defuseKitMgr_readTask(void)
{
	for(;;)
	{
		/*TODO read from CAN bus and set variables*/
		can_bus_read(&self.canRxMessage);
		osDelay(1);
	}
}

void defuseKitMgr_mgrTask(void)
{
	for(;;)
	{
		/*TODO manage states and variables*/
		powerStatus_process();
		if(self.status.powerStatus == ON)
		{
			battery_process(&self);
			demister_process(&self);
			fan_process(&self);
			led_process(&self);
			speaker_process(&self);
			faultStatus_process();
		}

		osDelay(1);
	}
}

void defuseKitMgr_writeTask(void)
{

	for(;;)
	{
		/*TODO read variables and write to CAN bus & others*/
		can_bus_write(&self.canTxMessage);
		osDelay(1);
	}
}

void powerStatus_process(void)
{
	static uint8_t prevPowerButtonState = LOW;
	static uint8_t currentPowerButtonState = LOW;
	currentPowerButtonState = self.canRxMessage.powerButtonState;
	if(currentPowerButtonState != prevPowerButtonState && currentPowerButtonState == HIGH)
	{
		self.status.powerStatus = !self.status.powerStatus;
		self.canTxMessage.powerLedPin = !self.canTxMessage.powerLedPin;
		if(self.canTxMessage.powerLedPin == LOW)
		{
			memset(&self.canTxMessage, 0, sizeof(self.canTxMessage));
		}
	}
	prevPowerButtonState = currentPowerButtonState;
}

void faultStatus_process(void)
{
	if(self.status.batteryStatus == FAULT)
	{
		self.canTxMessage.faultLedPin = HIGH;
	}
}

/*NOTE: this structure can be changed, let it settle for now 04.12*/
