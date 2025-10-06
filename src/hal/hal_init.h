/******************************************************************************/
/** @file hal_init.h
 ** @brief HAL initialization interface header file for C++/C mixed programming
 ** 
 ** @note System hardware abstraction layer initialization
 ******************************************************************************/

#ifndef __HAL_INIT_H__
#define __HAL_INIT_H__

/* C++ compatibility */
#ifdef __cplusplus
extern "C" {
#endif

/* Includes */
#include "main.h"
#include <stdint.h>
#include <stdbool.h>

/* Public types */


/* Public function prototypes */
int hal_init(void);

/* C++ compatibility */
#ifdef __cplusplus
}
#endif

#endif /* __HAL_INIT_H__ */