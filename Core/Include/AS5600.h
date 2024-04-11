#ifndef AS5600_H
#define AS5600_H

#include "stm32l4xx_hal.h"

// --------- AS5600 ADDRESS START -------------------
#define AS5600_ADDRESS 0x36
// --------- AS5600 ADDRESS END ------------------- 

// --------- AS5600 COMMUNICATION START -------------------
#define AS5600_MAX_FREQUENCY 10000000UL
#define AS5600_RX_BITS 12
#define AS5600_I2C_SCL_PIN_Pos 9U
#define AS5600_I2C_SCL_PORT GPIOA
#define AS5600_I2C_SDA_PIN_Pos 10U
#define AS5600_I2C_SDA_PORT GPIOA
#define AS5600_DIR_PIN_Pos 0U
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


HAL_StatusTypeDef AS5600_Init(void);

#endif
