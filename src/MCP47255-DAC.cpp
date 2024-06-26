/*
  @brief: For Setting Voltage Digitally in ADC and getting an Analog value out.
  @logistics: ESP32 MCU, MCP4275, Jumpers
  @project: Lab on a Chip, Seagate
  @attention: Copyright (c) Seagate. All rights reserved.
*/

#include <Arduino.h>
#include <Wire.h>
#include "MCP4725.h"
#include "MCP47255-DAC.h"

bool MCP_state = false;
bool MCP_got_Voltage = false;
float MCP_voltage = 0.0;
int DAC_value = 0;

// Initialise MCP4725 with the I2C Address
MCP4725 MCP(MCP4725_I2C_Addr);

void MCP4725_I2C_Start_and_Check()
{
    // Initializes the Wire library and join the I2C bus as a controller or a peripheral
    MCP_state = Wire.begin(MCP4725_I2C_SDA, MCP4725_I2C_SCL);

    // Begins a transmission to the I2C peripheral device with the given address
    Wire.beginTransmission(MCP4725_I2C_Addr);

    // Complete Transmission w Flag to check if Transmission Succeeded (0-Success etc.)
    MCP_state = Wire.endTransmission();

    // Error Checking for Failing I2C Checks
    if(MCP_state != 0)
    {
        Serial.println("I2C Communications Failed - Cannot Find Sensor.");
    }

    else
    {
        // Indicate I2C Succeeded
        Serial.println("I2C Communications Succeeded - Sensor Found.");
    }
}

void MCP4725_Set_Voltage(float set_voltage)
{
    // Set the Voltage on the MCP4725
    DAC_value = MCP.setVoltage(5.0);

    // Gets the Voltage on the DAC
    MCP_voltage = MCP.getVoltage();

    // Indicate Voltage Set
    Serial.print("Successfully Set DAC to ");
    Serial.print(MCP_voltage);
    Serial.println(" Volts.");
}

void MCP4725_Get_Voltage()
{
    // Gets the Voltage on the DAC
    MCP_voltage = MCP.getVoltage();

    // Flag for checking if managed to get voltage
    if(MCP_voltage)
    {
        MCP_got_Voltage = true;

        // Indicate Voltage Got
        Serial.println("Voltage Retrieved is ");
        Serial.println(MCP_voltage);
    }

    else
    {
        MCP_got_Voltage = false;

        // Indicate inability to retrieve voltage
        Serial.println("Unable to get voltage from DAC");
    }
}