#include "sys_init.h"
#include "freertos.h"
#include "driver/drv_init.h"
#include "hal/hal_init.h"
void SystemInit(void)
{
    hal_init();
    drv_init();
}
