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
uint8_t cbTx[8]; /*canbus tx*/
uint8_t cbRx[8]; /*canbus rx*/

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
	memset(cbTx, 0, 8);
	memset(cbRx, 0, 8);
	/*TODO start the tasks*/
}


void defuseKitMgr_readTask(void)
{
	for(;;)
	{
		/*TODO read from CAN bus and set variables*/
		can_bus_read(cbRx);
		osDelay(1);
	}
}

void defuseKitMgr_mgrTask(void)
{
	for(;;)
	{
		/*TODO manage states and variables*/
		osDelay(1);
	}
}

void defuseKitMgr_writeTask(void)
{

	for(;;)
	{
		/*TODO read variables and write to CAN bus & others*/
		can_bus_write(cbTx);
		osDelay(1);
	}
}


/*NOTE: this structure can be changed, let it settle for now 04.12*/
