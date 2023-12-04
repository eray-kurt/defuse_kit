/**
  ******************************************************************************
  * @file           : can_bus.c
  * @brief          : Source file of can bus peripherals and functions
  * @peripherals	: CAN (PB8, PB9)
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 Rubigtech.
  * All rights reserved.
  *
  ******************************************************************************
  */
#include "can_bus.h"

CAN_HandleTypeDef* can_bus_handle = &hcan; /*handler for can bus to use in functions*/
void can_bus_init(void)
{
	  MX_CAN_Init();
}

/*TODO create write and read functions*/
