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
#ifndef Pwr_H
#define Pwr_H

#include <stdint.h>
#include <type_traits>

class Pwr
{
public:
    enum RegulatorVoltageScaling
    {
        Scale_3 = 0b01,
        Scale_2 = 0b10,
        Scale_1 = 0b11,
    };

    void SetRegulatorVoltageScaling(RegulatorVoltageScaling rvs);

private:
    union CR_register
    {
        struct CR_bits
        {
            uint8_t LPDS                : 1;
            uint8_t PDDS                : 1;
            uint8_t CWUF                : 1;
            uint8_t CSBF                : 1;
            uint8_t PVDE                : 1;
            uint8_t PLS                 : 3;
            uint8_t DBP                 : 1;
            uint8_t FPDS                : 1;
            uint8_t LPLVDS              : 1;
            uint8_t MRLVDS              : 1;
            uint8_t Reserved1           : 1;
            uint8_t ADCDC1              : 1;
            RegulatorVoltageScaling VOS : 2;
            uint8_t Reserved2           : 4;
            uint8_t FMSSR               : 1;
            uint8_t FISSR               : 1;
            uint16_t Reserved3          : 10;
        } __attribute__((packed));

        uint32_t value;
        struct CR_bits bits;
    };
    
    volatile union CR_register CR;
    volatile uint32_t CSR;
};

static_assert(std::is_standard_layout<Pwr>::value, "Pwr class is NOT standard layout");

#endif // Pwr_H