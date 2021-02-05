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
#include <type_traits>

class Spi
{
public:


private:
    union CR1_register
    {
        struct CR1_bits
        {
            uint8_t CPHA : 1;
            uint8_t CPOL : 1;
            uint8_t MSTR : 1;
            uint8_t BR : 3;
            uint8_t SPE : 1;
            uint8_t LSBFIRST : 1;
            uint8_t SSI : 1;
            uint8_t SSM : 1;
            uint8_t RXONLY : 1;
            uint8_t DFF : 1;
            uint8_t CRCNEXT : 1;
            uint8_t CRCEN : 1;
            uint8_t BIDIOE : 1;
            uint8_t BIDIMODE : 1;
        };

        uint32_t value;
        struct CR1_bits bits;
    };

    volatile union CR1_register CR1;
    volatile uint32_t SR;
    volatile uint32_t DR;
    volatile uint32_t CRCPR;
    volatile uint32_t RXCRCR;
    volatile uint32_t TXCRCR;
    volatile uint32_t I2SCFGR;
    volatile uint32_t I2SPR;

};

static_assert(std::is_standard_layout<Spi>::value, "SPI class is NOT standard layout");

#endif // Spi_H