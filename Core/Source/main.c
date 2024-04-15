#include "main.h"
#include <stdio.h>

#if SEMIHOSTING_ENABLED
extern void initialise_monitor_handles(void);
#endif

int main(void)
{
#if SEMIHOSTING_ENABLED
    initialise_monitor_handles();
#endif

    HAL_Init();
    SYSCLK_Init();
    GPIO_Init();
    AS5600_Init();
    
    while(1)
    {
        HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_3);
        HAL_Delay(1000);
    }
}
