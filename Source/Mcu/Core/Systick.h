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
#ifndef Systick_H
#define Systick_H

#include <stdint.h>
#include <type_traits>

class Systick
{
public:
    enum class ClockSource : uint8_t
    {
        AHB_dividedBy8,
        AHB
    };

    void Enable(void);
    void SetClockSource(const ClockSource source);

private:
    union CTRL_register
    {
        struct CTRL_bits
        {
            uint8_t ENABLE : 1;
            uint8_t TICKINT : 1;
            ClockSource CLKSOURCE : 1;
            const uint16_t Reserved1 : 13;
            uint8_t COUNTFLAG : 1;
            const uint16_t Reserved2 : 15;
        };

        uint32_t value;
        struct CTRL_bits bits;
    };

    volatile union CTRL_register CTRL;
    volatile uint32_t LOAD;
    volatile uint32_t VAL;
    volatile uint32_t CALIB;
};

static_assert(std::is_standard_layout<Systick>::value, "Systick class is NOT standard layout");

#endif // Systick_H