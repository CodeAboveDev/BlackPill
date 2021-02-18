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

void Spi::Enable_Hardcoded(void)
{
    CR1.value = 0x00000354u;
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

void Spi::SetTransferMode(TransferMode mode)
{
    uint32_t bidimode = 0;
    uint32_t bidioe = 0;
    uint32_t rxonly = 0;

    switch(mode)
    {
    case TransferMode::FullDuplex:
        bidimode = 0;
        bidioe = 0;
        rxonly = 0;
        break;
    case TransferMode::SimplexRx:
        bidimode = 0;
        bidioe = 0;
        rxonly = 1;
        break;
    case TransferMode::HalfDuplexRx:
        bidimode = 1;
        bidioe = 0;
        rxonly = 0;
        break;
    case TransferMode::HalfDuplexTx:
        bidimode = 1;
        bidioe = 1;
        rxonly = 0;
        break;
    }

    CR1.value = ((CR1.value & ~((1 << 15) | (1 << 14) | (1 << 10))) | ((bidimode << 15) | (bidioe << 14) | (rxonly << 10)));
}

void Spi::SetSoftwareNSS(void)
{
    CR1.bits.SSM = 1;
    CR1.bits.SSI = 1;
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
