#include "../Include/clock_setup.h"


void SYSCLK_Init(void)
{
    RCC->CR = RCC_CR_HSION; // Enable The HSI Clock
    while (!(RCC->CR & RCC_CR_HSIRDY)) {} // Wait for HSI to be ready

    RCC->CFGR &= ~RCC_CFGR_SW; // Clear the clock selection bits, so misconfiguration doesn't happen 
    RCC->CFGR |= RCC_CFGR_SW_HSI; // Select The HSI Clock 
    while (!(RCC->CFGR & RCC_CFGR_SWS_HSI)) {} // Wait fo the HSI to be selected as SYSCLOCK

    SystemCoreClockUpdate();
    SysTick_Config(SystemCoreClock / 1000); // ISR Every 1 Second
}

void SysTick_Handler(void)
{
    msTicks++;
}
