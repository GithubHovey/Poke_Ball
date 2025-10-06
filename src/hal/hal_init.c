/******************************************************************************/
/** @file hal_init.c
 ** @brief HAL initialization implementation for C++/C mixed programming
 ** 
 ** @note System hardware abstraction layer initialization
 ******************************************************************************/

#include "hal_init.h"
#include "hal_adc.h"
#include "hal_tim.h"
#include <string.h>






/**
 * @brief HAL initialization function
 * @return hal_init_status_t Initialization status
 */
int hal_init(void)
{
    ADC_Init();
    return 0;
}



/* HAL initialization function implementations will be added here */