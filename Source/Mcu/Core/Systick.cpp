/*****************************************************************
 * Copyright (c) 2020 CodeAbove.
 * All rights reserved.
 *
 * This software component is licensed by CodeAbove under
 * BSD 3-Clause license, the 'License'. You may not use
 * this file except in compliance with the License. You
 * may obtain a copy of the License at:
 *                  opensource.org/licenses/BSD-3-Clause
 ****************************************************************/
#include "Systick.h"

void Systick::Enable(void)
{
    CTRL.bits.ENABLE = 1;
}

void Systick::EnableInterrupt(void)
{
    CTRL.bits.TICKINT = 1;
}

void Systick::SetClockSource(const ClockSource source)
{
    CTRL.bits.CLKSOURCE = source;
}

void Systick::SetReload(const uint32_t reload)
{
    // Prevent writing more than 24 bits by 0x00FFFFFF mask
    LOAD.bits.RELOAD = (reload & 0x00FFFFFF);
}

void Systick::SetReload1msTick(const uint32_t clockFrequency)
{
    SetReload((clockFrequency / 1000) - 1);
}
