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

#include "demister.h"
#define DEMISTER_PIN_BASE 		GPIOB /*base for demister gpio (pb2)*/
#define DEMISTER_PIN_OFFSET 	GPIO_PIN_2 /*offset for demister gpio (pb2)*/

void demister_init(void);
#endif /*DEMISTER_HEADER END*/
