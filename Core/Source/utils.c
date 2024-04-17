#include "utils.h"

void Error_Handler(void)
{
    printf("Entered Error Hander!\n");
    __disable_irq();
    while (1) 
    {
    }
}

void HardFault_Handler(void)
{
    while (1) 
    {
    
    }
}
