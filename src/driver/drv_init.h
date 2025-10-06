#ifndef DRV_INIT_H
#define DRV_INIT_H

#ifdef __cplusplus
extern "C" {
#endif
#include "driver/drv_battery.h"
#include "driver/drv_led.h"
#include "driver/drv_key.h"
/* Driver initialization functions */
void drv_init(void);
void drv_deinit(void);

#ifdef __cplusplus
}
#endif

#endif /* DRV_INIT_H */