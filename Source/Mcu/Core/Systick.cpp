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

