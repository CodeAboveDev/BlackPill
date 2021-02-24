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
#ifndef TimeBase_H
#define TimeBase_H

#include <stdint.h>

class TimeBase
{
public:
    static void Tick(void);
    bool IsIntervalPassed(void);

private:
    static constexpr uint8_t IntervalTime { 1u };

    static uint32_t Time_ms;

    uint32_t LastIntervalPassedTime { 0u };

};

#endif // TimeBase_H