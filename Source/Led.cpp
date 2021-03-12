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
#include "Led.h"

Led::Led(GpioPin& pin)
    : pin(pin)
{
    pin.SetMode(Gpio::Mode::Output);
}

void Led::On(void)
{
    pin.Reset();
}

void Led::Off(void)
{
    pin.Set();
}

void Led::Toggle(void)
{
    pin.Toggle();
}
