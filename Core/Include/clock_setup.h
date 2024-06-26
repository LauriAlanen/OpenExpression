#ifndef CLOCK_SETUP_H
#define CLOCK_SETUP_H

#include "stm32l4xx_hal.h"
#include "stm32l4xx_it.h"
#include "globals.h"

void SYSCLK_Init(void);
void Set_SysTick_IRQ_ms(uint32_t IRQ_Interval_ms);

#endif
