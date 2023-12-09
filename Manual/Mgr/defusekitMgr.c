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
	/*TODO start the tasks*/
}


void defuseKitMgr_readTask(void)
{
	for(;;)
	{
		/*TODO read from CAN bus and set variables*/
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
	int i = 0;
	uint32_t rpmspeed = 0;
	for(;;)
	{
		/*TODO read variables and write to CAN bus & others*/
	}
}


/*NOTE: this structure can be changed, let it settle for now 04.12*/
