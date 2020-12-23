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


private:
    uint32_t CR;
    uint32_t PLLCFGR;
    uint32_t CFGR;
    uint32_t CIR;
    uint32_t AHB1RSTR;
    uint32_t AHB2RSTR;
    uint32_t Reserved1;
    uint32_t Reserved2;
    uint32_t APB1RSTR;
    uint32_t APB2RSTR;
    uint32_t Reserved3;
    uint32_t Reserved4;
    uint32_t AHB1ENR;
    uint32_t AHB2ENR;
    uint32_t Reserved5;
    uint32_t Reserved6;
    uint32_t APB1ENR;
    uint32_t APB2ENR;
    uint32_t Reserved7;
    uint32_t Reserved8;
    uint32_t AHB1LPENR;
    uint32_t AHB2LPENR;
    uint32_t Reserved;
    uint32_t Reserved;
    uint32_t APB1LPENR;
    uint32_t APB2LPENR; 
    uint32_t Reserved;
    uint32_t Reserved;
    uint32_t BDCR;
    uint32_t CSR;
    uint32_t Reserved;
    uint32_t Reserved;
    uint32_t SSCGR;
    uint32_t PLLI2SCFGR;
    uint32_t Reserved;
    uint32_t DCKCFGR;
};

static_assert(std::is_standard_layout<Rcc>::value, "Rcc class is NOT standard layout");

#endif // Rcc_H