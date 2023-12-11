/**
  ******************************************************************************
  * @file           : demister.h
  * @brief          : Header file of demister peripherals and functions
  * @peripherals	: GPIO (PB2)
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 Rubigtech.
  * All rights reserved.
  *
  ******************************************************************************
  */

#ifndef DEMISTER_HEADER
#define DEMISTER_HEADER

#include "gpio.h"
#include "main.h"
#include "common.h"

void demister_init(void);
void demister_process(defuseKitMgr* self);
void demister_toggle(void);
void demister_open(void);
void demister_close(void);
#endif /*DEMISTER_HEADER END*/
