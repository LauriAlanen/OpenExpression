#include "main.h"

#if SEMIHOSTING_ENABLED
#include <stdio.h>
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
        printf("Hello\n");
        HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_3);
        HAL_Delay(1000);
    }
}
