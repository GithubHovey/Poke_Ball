/******************************************************************************/
/** @file hal_adc.h
 ** @brief HAL ADC interface header file for C++/C mixed programming
 ** 
 ** @note Function declarations to be added later
 ******************************************************************************/

#ifndef __HAL_ADC_H__
#define __HAL_ADC_H__

/* C++ compatibility */
#ifdef __cplusplus
extern "C" {
#endif

/* Includes */
#include "main.h"
#include <stdint.h>
#include <stdbool.h>





typedef enum {
    E_BAT_ADC,
    E_ADC_MAX_NUMBER
} AdcBufferPosition;
int ADC_Init(void);
uint16_t ADC_Read(AdcBufferPosition position);

/* C++ compatibility */
#ifdef __cplusplus
}
#endif

#endif /* __HAL_ADC_H__ */