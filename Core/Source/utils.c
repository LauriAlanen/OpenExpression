#include "../Include/utils.h"

void delay_ms(uint32_t ms_to_delay)
{
    uint32_t start_ticks = msTicks;

    while ((msTicks - start_ticks) < ms_to_delay) {}
}
