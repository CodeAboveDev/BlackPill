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
#ifndef IDisplay_H
#define IDisplay_H

#include <stdint.h>

class IDisplay
{
public:
    IDisplay(uint16_t x, uint16_t y) : Size{x, y} {};
    virtual void Refresh(void) = 0;

protected:
    const struct
    {
        uint16_t x;
        uint16_t y;
    } Size;

private:

};

#endif // IDisplay_H