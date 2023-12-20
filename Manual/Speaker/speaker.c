/**
  ******************************************************************************
  * @file           : speaker.c
  * @brief          : Source file of speaker peripherals and functions
  * @peripherals	: SPI (PB12, PB13, PB14, PB15)
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 Rubigtech.
  * All rights reserved.
  *
  ******************************************************************************
  */
#include "speaker.h"
#define SPEAKER_HAL 	hspi2
uint8_t txbuffer[10] ={0,5,4,6,7,222,3,2,1,213};
uint8_t rxbuffer[10];
void speaker_init(void)
{
	MX_SPI2_Init();
}

void speaker_process(defuseKitMgr* self)
{
	HAL_SPI_TransmitReceive(&SPEAKER_HAL, txbuffer, rxbuffer, sizeof(txbuffer), 1000);
}
