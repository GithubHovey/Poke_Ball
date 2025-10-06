/******************************************************************************/
/** @file hal_adc.c
 ** @brief HAL ADC interface implementation for C++/C mixed programming
 ** 
 ** @note Function implementations to be added later
 ******************************************************************************/

#include "hal/hal_adc.h"
#include "adc.h"
static uint16_t adc_buffer[E_ADC_MAX_NUMBER];
int ADC_Init(void)
{
    HAL_ADC_Start_DMA(&hadc1, (uint32_t*)adc_buffer, E_ADC_MAX_NUMBER);
    return 0;
}
uint16_t ADC_Read(AdcBufferPosition position)
{
    return adc_buffer[position];
}
/* ADC HAL function implementations will be added here */