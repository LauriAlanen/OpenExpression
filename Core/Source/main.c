#include "main.h"

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

    // BUG : When stm32 randomly enters a bugged state the I2C_INIT doesnt even get called
    AS5600_Init();
    
    while(1)
    {
        HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_3);
        HAL_Delay(500);
    }
}
