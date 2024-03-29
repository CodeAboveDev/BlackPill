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
#ifndef Spi_H
#define Spi_H

#include <stdint.h>
#include <stdlib.h>
#include <type_traits>

class Spi
{
public:
    enum class BaudRate : uint8_t
    {
        PCLK_div2   = 0b000,
        PCLK_div4   = 0b001,
        PCLK_div8   = 0b010,
        PCLK_div16  = 0b011,
        PCLK_div32  = 0b100,
        PCLK_div64  = 0b101,
        PCLK_div128 = 0b110,
        PCLK_div256 = 0b111,
    };

    enum class ClockPolarity : uint8_t
    {
        CPOL_0,
        CPOL_1,
    };

    enum class ClockPhase : uint8_t
    {
        CPHA_0,
        CPHA_1,
    };

    enum class DataFrameFormat : uint8_t
    {
        Format_8BitData,
        Format_16BitData,
    };

    enum class FrameFormat : uint8_t
    {
        MSB,
        LSB,
    };
    
    enum class MasterSelection : uint8_t
    {
        Slave,
        Master,
    };

    enum class TransferMode : uint8_t
    {
        FullDuplex,
        SimplexRx,
        HalfDuplexRx,
        HalfDuplexTx,
    };

    void Enable(void);
    void Enable_Hardcoded(void);
    void Disable(void);

    void SetBaudRate(BaudRate baudrate);

    void SetClockPolarity(ClockPolarity polarity);
    void SetClockPhase(ClockPhase phase);

    void SetDataFrameFormat(DataFrameFormat format);
    void SetFrameFormat(FrameFormat format);

    void SetMasterSelection(MasterSelection selection);
    void SetTransferMode(TransferMode mode);

    void SetSoftwareNSS(void);

    void Write(uint8_t byte);
    void Write(const uint8_t* buffer, size_t size);

private:
    union CR1_register
    {
        struct CR1_bits
        {
            ClockPhase CPHA : 1;
            ClockPolarity CPOL : 1;
            MasterSelection MSTR : 1;
            BaudRate BR : 3;
            uint8_t SPE : 1;
            FrameFormat LSBFIRST : 1;
            uint8_t SSI : 1;
            uint8_t SSM : 1;
            uint8_t RXONLY : 1;
            DataFrameFormat DFF : 1;
            uint8_t CRCNEXT : 1;
            uint8_t CRCEN : 1;
            uint8_t BIDIOE : 1;
            uint8_t BIDIMODE : 1;
            uint16_t Reserved : 16;
        } __attribute__((packed));

        uint32_t value;
        struct CR1_bits bits;
    };

    union SR_register
    {
        struct SR_bits
        {
            const uint8_t RXNE : 1;
            const uint8_t TXE : 1;
            const uint8_t CHSIDE : 1;
            const uint8_t UDR : 1;
            uint8_t CRCERR : 1;
            const uint8_t MODF : 1;
            const uint8_t OVR : 1;
            const uint8_t BSY : 1;
            const uint8_t FRE : 1;
            const uint32_t Reserved : 23;
        } __attribute__((packed));

        uint32_t value;
        struct SR_bits bits;
    };

    volatile union CR1_register CR1;
    volatile uint32_t CR2;
    volatile union SR_register SR;
    volatile uint32_t DR;
    volatile uint32_t CRCPR;
    volatile uint32_t RXCRCR;
    volatile uint32_t TXCRCR;
    volatile uint32_t I2SCFGR;
    volatile uint32_t I2SPR;

};

static_assert(std::is_standard_layout<Spi>::value, "SPI class is NOT standard layout");

#endif // Spi_H