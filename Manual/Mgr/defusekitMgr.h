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
#include "main.h"
#include "common.h"
void defuseKitMgr_init(void);

void defuseKitMgr_readTask(void);
void defuseKitMgr_writeTask(void);
void defuseKitMgr_managerTask(void);


#endif /*DEFUSEKITMGR_HEADER END*/
