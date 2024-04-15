#include "../Include/utils.h"

void Error_Handler(void)
{
    printf("Testing!\n");
    __disable_irq();
    while (1) 
    {
    }
}
