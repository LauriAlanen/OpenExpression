#include "../Include/utils.h"

void Error_Handler(void)
{
    __disable_irq();

    while (1) 
    {
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, 1);
    }
}
