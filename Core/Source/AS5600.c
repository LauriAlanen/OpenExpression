#include "AS5600.h"

I2C_HandleTypeDef hi2c1;

void AS5600_GPIO_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {};
    RCC_PeriphCLKInitTypeDef PeripheralClkInit = {};

    PeripheralClkInit.PeriphClockSelection = RCC_PERIPHCLK_I2C1;
    PeripheralClkInit.I2c1ClockSelection = RCC_I2C1CLKSOURCE_PCLK1;
    if (HAL_RCCEx_PeriphCLKConfig(&PeripheralClkInit) != HAL_OK) 
    {
        Error_Handler();
    }
    
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;

    GPIO_InitStruct.Pin = AS5600_DIR_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(AS5600_DIR_PORT, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = AS5600_I2C_SCL_PIN | AS5600_I2C_SDA_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF4_I2C1;
    HAL_GPIO_Init(AS5600_I2C_PORT, &GPIO_InitStruct);

    RCC->APB1ENR1 |= RCC_APB1ENR1_I2C1EN;
}

void AS5600_I2C_Init(void)
{
    hi2c1.Instance = I2C1;
    hi2c1.Init.Timing = AS5600_I2C_TIMING;
    hi2c1.Init.OwnAddress1 = 0;
    hi2c1.Init.OwnAddress2 = 0;
    hi2c1.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
    hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
    hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
    hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
    hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;

    printf("Entered I2C\n");
    if (HAL_I2C_Init(&hi2c1) != HAL_OK) 
    {
        printf("Error\n");
        Error_Handler();
    }    
    printf("Exited I2C\n");

/*     if (HAL_I2CEx_ConfigAnalogFilter(&hi2c1, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
    {
        Error_Handler();
    }

    if (HAL_I2CEx_ConfigDigitalFilter(&hi2c1, 0) != HAL_OK)
    {
        Error_Handler();
    } */
}

void AS5600_Init(void)
{
    AS5600_GPIO_Init();
    AS5600_I2C_Init();
}
