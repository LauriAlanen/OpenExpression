#include "gpio_setup.h"
#include "AS5600.h"

#define LED_BUILTIN_PIN GPIO_PIN_3
#define LED_BUILTIN_PORT GPIOB

void GPIO_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {};

    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;

    GPIO_InitStruct.Pin = LED_BUILTIN_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(LED_BUILTIN_PORT, &GPIO_InitStruct);
}
