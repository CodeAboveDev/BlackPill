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
    void Refresh(void);

    bool Is1msPassed(void);
    bool Is10msPassed(void);
    bool Is100msPassed(void);

private:
    static constexpr uint8_t IntervalTime { 1u };

    uint32_t LastIntervalPassedTime { 0u };
    uint32_t IntervalsCounter { 0u };

    bool TimePassed_1ms { false };
    bool TimePassed_10ms { false };
    bool TimePassed_100ms { false };

    bool IsIntervalPassed(void);
    void ClearTimeFlags(void);
    void UpdateTimeFlags(void);
};

#endif // TimeBase_H