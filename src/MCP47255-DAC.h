/*
  @brief: For Setting Voltage Digitally in ADC and getting an Analog value out.
  @logistics: ESP32 MCU, MCP4275, Jumpers
  @project: Lab on a Chip, Seagate
  @attention: Copyright (c) Seagate. All rights reserved.
*/

#include <Arduino.h>
#include <Wire.h>
#include "MCP4725.h"

#define MCP4725_I2C_Addr    0x60
#define MCP4725_I2C_SDA     16
#define MCP4725_I2C_SCL     17

extern bool MCP_state;
extern bool MCP_got_Voltage;
extern float MCP_voltage;
extern int DAC_value;

void MCP4725_I2C_Start_and_Check();
void MCP4725_Get_Voltage();