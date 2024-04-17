#ifndef AS5600_H
#define AS5600_H

#include "stm32l4xx_hal.h"
#include "stm32l4xx_hal_i2c.h"
#include "utils.h"
#include "globals.h"

// --------- AS5600 ADDRESS START -------------------
#define AS5600_ADDRESS 0x36
// --------- AS5600 ADDRESS END ------------------- 

// --------- AS5600 COMMUNICATION START -------------------
#define AS5600_I2C_MAX_FREQUENCY 10000000UL
#define AS5600_I2C_TIMING 0x00404C74
#define AS5600_I2C_SCL_PIN GPIO_PIN_9
#define AS5600_I2C_SDA_PIN GPIO_PIN_10
#define AS5600_I2C_PORT GPIOA
#define AS5600_DIR_PIN GPIO_PIN_0
#define AS5600_DIR_PORT GPIOB
// --------- AS5600 COMMUNICATION END -------------------

// --------- AS5600 CONF REGISTERS START -------------------
#define AS5600_ZMCO 0x00
#define AS5600_ZPOS 0x01
#define AS5600_MPOS 0x03
#define AS5600_MANG 0x05
#define AS5600_CONF 0x07
#define AS5600_RAW_ANGLE 0x0C
#define AS5600_ANGLE 0x0E 
#define AS5600_STATUS 0x0B 
#define AS5600_ASC 0x1A 
#define AS5600_MAGNITUDE 0x1B 
#define AS5600_BURN 0xFF
// --------- AS5600 CONF REGISTERS END -------------------


void AS5600_Init(void);
void AS5600_GPIO_Init(void);
void AS5600_I2C_Init(void);

#endif
