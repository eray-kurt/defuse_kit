/**
  ******************************************************************************
  * @file           : defuseKitMgr.h
  * @brief          : Header file of defuse kit manager
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 Rubigtech.
  * All rights reserved.
  *
  ******************************************************************************
  */
#ifndef DEFUSEKITMGR_HEADER
#define DEFUSEKITMGR_HEADER

#include <string.h>
#include <stdio.h>
#include "cmsis_os.h"
#include "main.h"
#include "common.h"
#include "battery.h"
#include "can_bus.h"
#include "demister.h"
#include "fan.h"
#include "speaker.h"

#include "lamp.h"


void defuseKitMgr_init(void);

void defuseKitMgr_readTask(void);
void defuseKitMgr_mgrTask(void);
void defuseKitMgr_writeTask(void);

void powerStatus_process(void);
void faultStatus_process(void);
int buttonstate_process(uint8_t buttonValue);

#endif /*DEFUSEKITMGR_HEADER END*/
