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
#include "Spi.h"

void Spi::Enable(void)
{
    CR1.bits.SPE = 1;
}

void Spi::Disable(void)
{
    //TODO: Implement disabling procedure
    CR1.bits.SPE = 0;
}

void Spi::SetBaudRate(BaudRate baudrate)
{
    CR1.bits.BR = baudrate;
}

void Spi::SetClockPolarity(ClockPolarity polarity)
{
    CR1.bits.CPOL = polarity;
}

void Spi::SetClockPhase(ClockPhase phase)
{
    CR1.bits.CPHA = phase;
}

void Spi::SetDataFrameFormat(DataFrameFormat format)
{
    CR1.bits.DFF = format;
}

void Spi::SetFrameFormat(FrameFormat format)
{
    CR1.bits.LSBFIRST = format;
}

void Spi::SetMasterSelection(MasterSelection selection)
{
    CR1.bits.MSTR = selection;
}

void Spi::Write(uint8_t byte)
{
    DR = byte;
    while(SR.bits.TXE != 1)
    {
        // Wait for it!
    }
    while(SR.bits.BSY != 0)
    {
        // Wait for it!
    }
}
