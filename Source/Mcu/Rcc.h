/*****************************************************************
 * Copyright (c) 2020 CodeAbove.
 * All rights reserved.
 *
 * This software component is licensed by CodeAbove under
 * BSD 3-Clause license, the 'License'. You may not use
 * this file except in compliance with the License. You
 * may obtain a copy of the License at:
 *                  opensource.org/licenses/BSD-3-Claus
 ****************************************************************/
#ifndef Rcc_H
#define Rcc_H

#include <stdint.h>
#include <type_traits>

class Rcc
{
public:
    void EnableHighSpeedInternalClock(void);
    void SetHighSpeedInternalClockTrimming(uint8_t trimming);

    void EnableHighSpeedExternalClock(void);

private:
    union CR_register
    {
        struct CR_bits
        {
            uint8_t HSION : 1;
            const uint8_t HSIRDY : 1;
            const uint8_t Reserved1 : 1;
            uint8_t HSITRIM : 5;
            const uint8_t HSICAL : 8;
            uint8_t HSEON : 1;
            const uint8_t HSERDY : 1;
            uint8_t HSEBYP : 1;
            uint8_t CSSON : 1;
            const uint8_t Reserved2 : 4;
            uint8_t PLLON : 1;
            const uint8_t PLLRDY : 1;
            uint8_t PLLI2SON : 1;
            const uint8_t PLLI2SRDY : 1;
            const uint8_t Reserved3 : 4;
        };

        uint32_t value;
        struct CR_bits bits;
    };

    volatile union CR_register CR;
    volatile uint32_t PLLCFGR;
    volatile uint32_t CFGR;
    volatile uint32_t CIR;
    volatile uint32_t AHB1RSTR;
    volatile uint32_t AHB2RSTR;
    volatile uint32_t Reserved1;
    volatile uint32_t Reserved2;
    volatile uint32_t APB1RSTR;
    volatile uint32_t APB2RSTR;
    volatile uint32_t Reserved3;
    volatile uint32_t Reserved4;
    volatile uint32_t AHB1ENR;
    volatile uint32_t AHB2ENR;
    volatile uint32_t Reserved5;
    volatile uint32_t Reserved6;
    volatile uint32_t APB1ENR;
    volatile uint32_t APB2ENR;
    volatile uint32_t Reserved7;
    volatile uint32_t Reserved8;
    volatile uint32_t AHB1LPENR;
    volatile uint32_t AHB2LPENR;
    volatile uint32_t Reserved9;
    volatile uint32_t Reserved10;
    volatile uint32_t APB1LPENR;
    volatile uint32_t APB2LPENR; 
    volatile uint32_t Reserved11;
    volatile uint32_t Reserved12;
    volatile uint32_t BDCR;
    volatile uint32_t CSR;
    volatile uint32_t Reserved13;
    volatile uint32_t Reserved14;
    volatile uint32_t SSCGR;
    volatile uint32_t PLLI2SCFGR;
    volatile uint32_t Reserved15;
    volatile uint32_t DCKCFGR;
};

static_assert(std::is_standard_layout<Rcc>::value, "Rcc class is NOT standard layout");

#endif // Rcc_H