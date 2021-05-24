/*****************************************************************
 * Copyright (c) 2021 CodeAbove.
 * All rights reserved.
 *
 * This software component is licensed by CodeAbove under
 * BSD 3-Clause license, the 'License'. You may not use
 * this file except in compliance with the License. You
 * may obtain a copy of the License at:
 *                  opensource.org/licenses/BSD-3-Clause
 ****************************************************************/
#include "I2c.h"

#include <stdint.h>

void I2c::SetClockSpeed(uint32_t speed, uint32_t pclk1ClockFrequency)
{
    // Hz to MHz
    uint8_t freqRange = pclk1ClockFrequency / 1000000;

    CR2.bits.FREQ = freqRange;

    if(speed <= StandardSpeedMax_kHz)
    {
        TRISE.bits.TRISE = freqRange + 1;
    }
    else
    {
        TRISE.bits.TRISE = (((freqRange * 300U) / 1000U) + 1U);
    }
}

void I2c::SetClockSpeedMode(ClockSpeedMode mode)
{
    CCR.bits.FS = mode;
}

void I2c::SetControlClockRegister(uint32_t speed, uint32_t pclk1ClockFrequency, DutyCycle dutyCycle)
{
    if(CCR.bits.FS == ClockSpeedMode::Standard)
    {
        CCR.bits.CCR = (uint32_t)(((((pclk1ClockFrequency)/((speed) << 1u)) & CCR.bits.CCR) < 4u)? 4u:((pclk1ClockFrequency) / ((speed) << 1u)));

    }
    else
    {
        if(dutyCycle == DutyCycle::DC_2)
        {
            CCR.bits.CCR = (((((pclk1ClockFrequency) / ((speed) * 3u)) & CCR.bits.CCR) == 0u)? 1u : ((pclk1ClockFrequency) / ((speed) * 3u)));
        }
        else
        {
            CCR.bits.CCR = (((((pclk1ClockFrequency) / ((speed) * 25u)) & CCR.bits.CCR) == 0u)? 1u : ((pclk1ClockFrequency) / ((speed) * 25u)));
            
        }
        
    }    
}

void I2c::SetOwnAddress1(uint8_t address)
{

}

void I2c::Enable(void)
{

}

void I2c::Write(uint8_t byte)
{
    DR.bits.DR = byte;
}

uint8_t I2c::Read(void)
{
    return DR.bits.DR;
}
