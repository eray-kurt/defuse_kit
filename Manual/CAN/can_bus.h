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
#include "common.h"
#define CAN_RX_ID 	0x103
#define CAN_TX_ID 	0x103


void can_bus_init(void);
void can_bus_read(CanRxMessage* can_bus_data);
void can_bus_write(CanTxMessage* can_bus_data);
#endif /*CAN_HEADER END*/
