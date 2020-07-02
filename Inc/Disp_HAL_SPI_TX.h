#ifndef __Disp_HAL_SPI_TX__
#define __Disp_HAL_SPI_TX__

/* Includes ---------------------------------------------------- */
#include "stm32f0xx.h"
#include <stdbool.h>
#include <string.h>
#include <math.h>

/* Private defines ---------------------------------------------------- */

/* Typedef Decleration ---------------------------------------------------- */

/* Fucntion Decleration ---------------------------------------------------- */
static HAL_StatusTypeDef SPI_WaitFifoStateUntilTimeout(SPI_HandleTypeDef *hspi, uint32_t Fifo, uint32_t State,
                                                       uint32_t Timeout, uint32_t Tickstart);

static HAL_StatusTypeDef SPI_WaitFlagStateUntilTimeout(SPI_HandleTypeDef *hspi, uint32_t Flag, FlagStatus State,
                                                       uint32_t Timeout, uint32_t Tickstart);

static HAL_StatusTypeDef SPI_EndRxTxTransaction(SPI_HandleTypeDef *hspi, uint32_t Timeout, uint32_t Tickstart);

HAL_StatusTypeDef disp_HAL_SPI_Transmit(SPI_HandleTypeDef *hspi, uint8_t *pData, uint16_t Size, uint32_t Timeout);

#endif //__Disp_HAL_SPI_TX__
