/**
  ******************************************************************************
  * @file           : can_bus.h
  * @brief          : Header file of can bus peripherals and functions
  * @peripherals	: CAN (PB8, PB9)
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 Rubigtech.
  * All rights reserved.
  *
  ******************************************************************************
  */

#ifndef CAN_HEADER
#define CAN_HEADER
#include "can.h"

CAN_HandleTypeDef* can_bus_handle = &hcan; /*handler for can bus to use in functions*/
void can_bus_init(void);

#endif /*CAN_HEADER END*/
