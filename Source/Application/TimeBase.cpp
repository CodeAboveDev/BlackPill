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
#include "TimeBase.h"
#include "../Mcu/Core/Systick.h"

void TimeBase::Refresh(void)
{
    ClearTimeFlags();

    if(IsIntervalPassed())
    {
        UpdateTimeFlags();
    }
}

bool TimeBase::Is1msPassed(void)
{
    return TimePassed_1ms;
}

bool TimeBase::Is10msPassed(void)
{
    return TimePassed_10ms;
}

bool TimeBase::Is100msPassed(void)
{
    return TimePassed_100ms;
}

bool TimeBase::IsIntervalPassed(void)
{
    uint32_t systemTime = SystickInterruptHandler::GetSystemTime();

    if((systemTime - LastIntervalPassedTime) >= IntervalTime)
    {
        LastIntervalPassedTime = systemTime;
        return true;
    }

    return false;
}

void TimeBase::ClearTimeFlags(void)
{
    TimePassed_1ms = false;
    TimePassed_10ms = false;
    TimePassed_100ms = false;
}

void TimeBase::UpdateTimeFlags(void)
{
    IntervalsCounter++;

    TimePassed_1ms = true;

    if((IntervalsCounter % 10) == 0u)
    {
        TimePassed_10ms = true;

        if((IntervalsCounter % 100) == 0u)
        {
            TimePassed_100ms = true;

            // Max time reached, reset
            IntervalsCounter = 0u;
        }
    }
}
