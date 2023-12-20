/**
  ******************************************************************************
  * @file           : speaker.h
  * @brief          : Header file of speaker peripherals and functions
  * @peripherals	: SPI (PB12, PB13, PB14, PB15)
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 Rubigtech.
  * All rights reserved.
  *
  ******************************************************************************
  */
#ifndef SPEAKER_HEADER
#define SPEAKER_HEADER
#include "spi.h"
#include "common.h"

void speaker_init(void);
void speaker_process(defuseKitMgr* self);
#endif /*SPEAKER_HEADER END*/
