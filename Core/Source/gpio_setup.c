#include "gpio_setup.h"

void GPIO_Init(void)
{
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN; // Enable CLK For PORTB

    // Output Mode
    GPIOB->MODER |= GPIO_MODER_MODE3_0; 
    GPIOB->MODER &= ~GPIO_MODER_MODE3_1;

    // Input Mode
    GPIOB->MODER &= ~GPIO_MODER_MODE7_0;
    GPIOB->MODER &= ~GPIO_MODER_MODE7_1;
    
    // GPIO Pin Medium Speed
    GPIOB->OSPEEDR &= ~GPIO_OSPEEDR_OSPEED7_0;
    GPIOB->OSPEEDR |= GPIO_OSPEEDR_OSPEED7_1;

    // Enable Pull-up Resistor For Pin 7
    GPIOB->PUPDR |= GPIO_PUPDR_PUPD7_0; 
    GPIOB->PUPDR &= ~GPIO_PUPDR_PUPD7_1; 
}
