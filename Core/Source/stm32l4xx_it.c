#include "stm32l4xx_it.h"

void Error_Handler(void)
{
    printf("Entered Error Hander!\n");
    //__disable_irq();
    while (1) 
    {
        HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_3);
        HAL_Delay(100);
    }
}

void HardFault_Handler(void)
{
    while (1) 
    {
        HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_3);
        HAL_Delay(10);
    }
}
