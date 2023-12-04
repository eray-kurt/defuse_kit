/**
  ******************************************************************************
  * @file           : demister.c
  * @brief          : Source file of demister peripherals and functions
  * @peripherals	: GPIO (PB2)
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 Rubigtech.
  * All rights reserved.
  *
  ******************************************************************************
  */

#include "demister.h"

void demister_init(void)
{
 /*no init since gpio inited at main*/
}

void demister_open(void)
{
	HAL_GPIO_WritePin(DEMISTER_GPIO_Port, DEMISTER_Pin, GPIO_PIN_SET);
}

void demister_close(void)
{
	HAL_GPIO_WritePin(DEMISTER_GPIO_Port, DEMISTER_Pin, GPIO_PIN_RESET);
}

/*TODO create demister_write function*/
