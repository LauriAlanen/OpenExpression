#include "main.h"

int main(void)
{
    HAL_Init();
    SYSCLK_Init();
    GPIO_Init();
    
    while(1)
    {
        HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_3);
        HAL_Delay(1000);
    }
}
