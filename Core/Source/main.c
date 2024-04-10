#include "main.h"

int main(void)
{
    SYSCLK_Init();
    GPIO_Init();

    while(1)
    {
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, 1);
        HAL_Delay(500);
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, 0);
        HAL_Delay(500);
    }
}
