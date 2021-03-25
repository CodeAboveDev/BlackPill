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
#ifndef ST7789Pin_H
#define ST7789Pin_H

#include "../ST7789/ST7789.h"
#include "../../Mcu/Gpio.h"

class ST7789Pin : public IST7789Pin
{
public:
    ST7789Pin(GpioPin& pin) : pin(pin) {};

    void Set(void) override
    {
        pin.Set();
    };
    
    void Reset(void) override
    {
        pin.Reset();
    };

private:
    GpioPin& pin;
};

#endif // ST7789Pin_H