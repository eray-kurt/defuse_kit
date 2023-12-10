/**
  ******************************************************************************
  * @file           : common.h
  * @brief          : Header file of common definitions and types
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 Rubigtech.
  * All rights reserved.
  *
  ******************************************************************************
  */

#ifndef COMMON_HEADER
#define COMMON_HEADER

#define bool 			int
#define TRUE 			1
#define FALSE			0

#define FAN_LOW_POWER 10
#define FAN_HIGH_POWER 70
#define FAN_PERCENTAGE_MULTIPLIER 10


/*CAN TX MESSAGE STRUCT*/
typedef struct CanTxMessage
{
	/*byte 0*/
	uint8_t powerButtonState 	: 1;
	uint8_t upButtonState 		: 1;
	uint8_t downButtonState 	: 1;
	uint8_t fanButtonState 		: 1;
	uint8_t soundButtonState 	: 1;
	uint8_t lampButtonState 	: 1;
	uint8_t turboButtonState 	: 1;
	uint8_t demisterButtonState : 1;

	/*byte 1 - 8 */
	uint8_t padding[7];
} CanTxMessage;

/*CAN RX MESSAGE STRUCT*/
typedef struct CanRxMessage
{
	/*byte 0*/
	uint8_t padding0 : 8;
	/*byte 1*/
	uint8_t padding1 : 8;

	/*byte 2*/
	uint8_t powerLedPin 		: 1;
	uint8_t fanLedPin 			: 1;
	uint8_t soundLedPin 		: 1;
	uint8_t lampLedPin 			: 1;
	uint8_t lamp2LedPin 		: 1;
	uint8_t turboLedPin 		: 1;
	uint8_t demisterLedPin 		: 1;
	uint8_t faultLedPin 		: 1;

	/*byte 3*/
	uint8_t padding2[5];
} CanRxMessage;

typedef enum ModuleStatus
{
	OFF = 0,
	ON = 1,
	MODULE_ERROR = 2,
} ModuleStatus;


#define	BATTERY_FULL 					13.0
#define BATTERY_PERCENT90 				10.7
#define	BATTERY_PERCENT80 				10.4
#define	BATTERY_PERCENT70 				10.1
#define	BATTERY_PERCENT60 				9.8
#define	BATTERY_PERCENT50 				9.5
#define	BATTERY_PERCENT40 				9.2
#define	BATTERY_PERCENT30 				8.9
#define	BATTERY_PERCENT20 				8.6
#define	BATTERY_PERCENT10 				8.3


#endif /*COMMON_HEADER END*/
