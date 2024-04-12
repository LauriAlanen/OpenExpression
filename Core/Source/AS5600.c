#include "AS5600.h"


void AS5600_GPIO_Init(void)
{
    AS5600_I2C_SCL_PORT->MODER |= (0x03U << AS5600_I2C_SCL_PIN_Pos * 2U);
    AS5600_I2C_SDA_PORT->MODER |= (0x03U << AS5600_I2C_SDA_PIN_Pos * 2U);
    AS5600_I2C_SCL_PORT->OSPEEDR |= (0x03U << AS5600_I2C_SCL_PIN_Pos * 2U);
    AS5600_I2C_SDA_PORT->OSPEEDR |= (0x03U << AS5600_I2C_SDA_PIN_Pos * 2U);
    AS5600_I2C_SCL_PORT->OTYPER |= (0x01U << AS5600_I2C_SCL_PIN_Pos);
    AS5600_I2C_SDA_PORT->OTYPER |= (0x01U << AS5600_I2C_SDA_PIN_Pos);
    AS5600_I2C_SCL_PORT->PUPDR |= (0x01U << AS5600_I2C_SCL_PIN_Pos * 2U);
    AS5600_I2C_SDA_PORT->PUPDR |= (0x01U << AS5600_I2C_SDA_PIN_Pos * 2U);
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
    

    if (HAL_I2C_Init(&hi2c1) != HAL_OK) 
    {
        Error_Handler();
    }    

    if (HAL_I2CEx_ConfigAnalogFilter(&hi2c1, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
    {
        Error_Handler();
    }

    if (HAL_I2CEx_ConfigDigitalFilter(&hi2c1, 0) != HAL_OK)
    {
        Error_Handler();
    }
}


void AS5600_Init(void)
{
    AS5600_GPIO_Init();
    AS5600_I2C_Init();
}
