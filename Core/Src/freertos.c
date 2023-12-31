/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "defuseKitMgr.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
osThreadId defuseKitMgr_readTaskHandle;
osThreadId defuseKitMgr_mgrTaskHandle;
osThreadId defuseKitMgr_writeTaskHandle;
osSemaphoreId mgrTaskBinarySem01Handle;
osSemaphoreId writeTaskBinarySem02Handle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void dkm_readTask(void const * argument);
void dkm_mgrTask(void const * argument);
void dkm_writeTask(void const * argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* GetIdleTaskMemory prototype (linked to static allocation support) */
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize );

/* USER CODE BEGIN PREPOSTSLEEP */
__weak void PreSleepProcessing(uint32_t *ulExpectedIdleTime)
{
/* place for user code */
}

__weak void PostSleepProcessing(uint32_t *ulExpectedIdleTime)
{
/* place for user code */
}
/* USER CODE END PREPOSTSLEEP */

/* USER CODE BEGIN GET_IDLE_TASK_MEMORY */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[configMINIMAL_STACK_SIZE];

void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize )
{
  *ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
  *ppxIdleTaskStackBuffer = &xIdleStack[0];
  *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
  /* place for user code */
}
/* USER CODE END GET_IDLE_TASK_MEMORY */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* Create the semaphores(s) */
  /* definition and creation of mgrTaskBinarySem01 */
  osSemaphoreDef(mgrTaskBinarySem01);
  mgrTaskBinarySem01Handle = osSemaphoreCreate(osSemaphore(mgrTaskBinarySem01), 1);

  /* definition and creation of writeTaskBinarySem02 */
  osSemaphoreDef(writeTaskBinarySem02);
  writeTaskBinarySem02Handle = osSemaphoreCreate(osSemaphore(writeTaskBinarySem02), 1);

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of defuseKitMgr_readTask */
  osThreadDef(defuseKitMgr_readTask, dkm_readTask, osPriorityBelowNormal, 0, 128);
  defuseKitMgr_readTaskHandle = osThreadCreate(osThread(defuseKitMgr_readTask), NULL);

  /* definition and creation of defuseKitMgr_mgrTask */
  osThreadDef(defuseKitMgr_mgrTask, dkm_mgrTask, osPriorityAboveNormal, 0, 128);
  defuseKitMgr_mgrTaskHandle = osThreadCreate(osThread(defuseKitMgr_mgrTask), NULL);

  /* definition and creation of defuseKitMgr_writeTask */
  osThreadDef(defuseKitMgr_writeTask, dkm_writeTask, osPriorityNormal, 0, 128);
  defuseKitMgr_writeTaskHandle = osThreadCreate(osThread(defuseKitMgr_writeTask), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_dkm_readTask */
/**
* @brief Function implementing the defuseKitMgr_readTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_dkm_readTask */
void dkm_readTask(void const * argument)
{
  /* USER CODE BEGIN dkm_readTask */
  /* Infinite loop */
	defuseKitMgr_readTask();
  /* USER CODE END dkm_readTask */
}

/* USER CODE BEGIN Header_dkm_mgrTask */
/**
* @brief Function implementing the defuseKitMgr_mgrTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_dkm_mgrTask */
void dkm_mgrTask(void const * argument)
{
  /* USER CODE BEGIN dkm_mgrTask */
  /* Infinite loop */
	defuseKitMgr_mgrTask();
  /* USER CODE END dkm_mgrTask */
}

/* USER CODE BEGIN Header_dkm_writeTask */
/**
* @brief Function implementing the defuseKitMgr_writeTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_dkm_writeTask */
void dkm_writeTask(void const * argument)
{
  /* USER CODE BEGIN dkm_writeTask */
  /* Infinite loop */
	defuseKitMgr_writeTask();
  /* USER CODE END dkm_writeTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

