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

#define HIGH			1
#define LOW				0


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

#define FAN_MAX							100
#define FAN_MIN							0
#define FAN_STEP						10
#define FAN_UPPER_DEFAULT				60
#define FAN_LOWER_DEFAULT				10
#define FAN_TURBO_DEFAULT				90

#define LED_STEP						10
#define LED_UPPER_DEFAULT				100
#define LED_LOWER_DEFAULT				0

typedef enum ModuleStatus
{
	OFF = 0,
	ON = 1,
	FAULT = 2,
} ModuleStatus;

typedef enum ActiveModule
{
	FAN = 0,
	TURBO = 1,
	LED = 2,
	SOUND = 3,
}ActiveModule;
/*CAN TX MESSAGE STRUCT*/
typedef struct CanRxMessage
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

	/*byte 1 - 7 */
	uint8_t padding[7];
} CanRxMessage;

/*CAN RX MESSAGE STRUCT*/
typedef struct CanTxMessage
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
	uint8_t padding2;

	/*byte 4*/
	uint8_t LED_BAR1_Pin 		: 1;
	uint8_t LED_BAR2_Pin 		: 1;
	uint8_t LED_BAR3_Pin 		: 1;
	uint8_t LED_BAR4_Pin 		: 1;
	uint8_t LED_BAR5_Pin 		: 1;
	uint8_t LED_BAR6_Pin 		: 1;
	uint8_t LED_BAR7_Pin 		: 1;
	uint8_t LED_BAR8_Pin 		: 1;

	/*byte 5*/
	uint8_t LED_BAR9_Pin 		: 1;
	uint8_t LED_BAR10_Pin 		: 1;
	uint8_t padding3	 		: 6;

	/*byte 6 - 7*/
	uint8_t padding4[2];
} CanTxMessage;

typedef struct fanMgr
{
	uint8_t fanUpperLimit;
	uint8_t fanLevel;
	uint8_t fanLowerLimit;
	uint8_t turboLevel;
}fanMgr;

typedef struct soundMgr
{
	uint8_t soundUpperLimit;
	uint8_t soundLevel;
	uint8_t soundLowerLimit;
}soundMgr;

typedef struct ledMgr
{
	uint8_t ledUpperLimit;
	uint8_t ledLevel;
	uint8_t ledLowerLimit;
}ledMgr;



typedef struct defuseKitStatus
{
	ModuleStatus powerStatus;
	ModuleStatus batteryStatus;
	ModuleStatus fanStatus;
	ModuleStatus turboFanStatus;
	ModuleStatus lampStatus;
	ModuleStatus soundStatus;
	ModuleStatus demisterStatus;
	ActiveModule lastActiveModule;

}defuseKitStatus;

typedef struct defuseKitMgr
{
	CanTxMessage canTxMessage;
	CanRxMessage canRxMessage;
	float batteryLevel;
	fanMgr fanMgr;
	ledMgr ledMgr;
	soundMgr soundMgr;
	defuseKitStatus status;
}defuseKitMgr;


#endif /*COMMON_HEADER END*/
