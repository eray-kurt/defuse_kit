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
	/*TODO set default values or get them from flash*/
	/*TODO start the tasks*/
}


void defuseKitMgr_readTask(void)
{
	while(1)
	{
		/*TODO read from CAN bus and set variables*/
	}
}

void defuseKitMgr_writeTask(void)
{
	while(1)
	{
		/*TODO read variables and write to CAN bus & others*/
	}
}

void defuseKitMgr_managerTask(void)
{
	while(1)
	{
		/*TODO manage states and variables*/
	}
}

/*NOTE: this structure can be changed, let it settle for now 04.12*/
