/*
  @brief: For Setting Voltage Digitally in ADC and getting an Analog value out.
  @logistics: ESP32 MCU, MCP4275, Jumpers
  @project: Lab on a Chip, Seagate
  @attention: Copyright (c) Seagate. All rights reserved.
*/

#include <Arduino.h>
#include "MCP4725.h"
#include "MCP47255-DAC.h"


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  MCP4725_I2C_Start_and_Check();

  MCP4725_Set_Voltage(5.0);
  
  MCP4725_Get_Voltage();
}

void loop() {
  // put your main code here, to run repeatedly:

  MCP4725_Get_Voltage();
  delay(2000);

  // MCP4725_Get_Voltage();
}