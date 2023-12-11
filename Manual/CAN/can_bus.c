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
CAN_TxHeaderTypeDef canTxHeader;
CAN_RxHeaderTypeDef canRxHeader;

uint32_t TxMailbox;
CAN_HandleTypeDef* can_bus_handle = &hcan; /*handler for can bus to use in functions*/
void can_bus_init(void)
{
	  MX_CAN_Init();

	  /*transmit header init*/
	  canTxHeader.DLC = 1;
	  canTxHeader.ExtId = 0;
	  canTxHeader.IDE = CAN_ID_STD;
	  canTxHeader.RTR = CAN_RTR_DATA;
	  canTxHeader.StdId = CAN_TX_ID; /*0x103*/
	  canTxHeader.TransmitGlobalTime = DISABLE;

	  HAL_CAN_Start(can_bus_handle);
}

void can_bus_read(CanRxMessage* can_bus_data)
{
	HAL_CAN_GetRxMessage(can_bus_handle, CAN_RX_FIFO0, &canRxHeader, (uint8_t*)can_bus_data);

}

void can_bus_write(CanTxMessage* can_bus_data)
{
	HAL_CAN_AddTxMessage(can_bus_handle, &canTxHeader, (uint8_t*)can_bus_data, &TxMailbox);
}

/*TODO create write and read functions*/
