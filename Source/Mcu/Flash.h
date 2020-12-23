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
#ifndef Flash_H
#define Flash_H

#include <stdint.h>
#include <type_traits>

class Flash
{
public:
    enum WaitStates
    {
        WS_0, // 1 CPU cycle
        WS_1, // 2 CPU cycles
        WS_2, // 3 CPU cycles
        WS_3, // 4 CPU cycles
        WS_4, // 5 CPU cycles
        WS_5, // 6 CPU cycles
        WS_6  // 7 CPU cycles
    };

    void SetLatency(WaitStates ws);

private:
    volatile uint32_t ACR;
    volatile uint32_t KEYR;
    volatile uint32_t OPTKEYR;
    volatile uint32_t SR;
    volatile uint32_t CR;
    volatile uint32_t OPTCR;
};

static_assert(std::is_standard_layout<Flash>::value, "Flash class is NOT standard layout");

#endif // Flash_H