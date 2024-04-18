#include "main.h"

#if SEMIHOSTING_ENABLED
extern void initialise_monitor_handles(void);
extern int printf(const char *format, ...);
#else
    int printf(const char *format, ...)
    {
        (void) format;
        return 0;
    }

#endif

int main(void)
{
#if SEMIHOSTING_ENABLED
    initialise_monitor_handles();
#endif 
    HAL_Init();
    printf("HAL_INIT\n");
    SYSCLK_Init();
    printf("SYSCLK_INIT\n");
    GPIO_Init();
    printf("GPIO_INIT\n");

    // BUG : When stm32 randomly enters a bugged state the I2C_INIT doesnt even get called
    AS5600_Init();
    printf("AS5600_INIT\n");
    
    while(1)
    {
        HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_3);
        HAL_Delay(400);
    }
}
