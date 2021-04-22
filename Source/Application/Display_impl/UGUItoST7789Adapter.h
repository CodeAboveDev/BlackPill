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
#ifndef UGUItoST7789Adapter_H
#define UGUItoST7789Adapter_H

#include <stdint.h>
#include "../Display/DisplayBuffer.h"

class UGUItoST7789Adapter
{
public:
    static void Set(int16_t x, int16_t y, uint16_t color)
    {
        db.buf.u8[(y * db.dim.y + x) * 2] = (color >> 8);
        db.buf.u8[(y * db.dim.y + x) * 2 + 1] = (color & 0xFF);
    };

    static DisplayBuffer<240,240> db;
    static union buffer displayBuffer;
};

#endif // UGUItoST7789Adapter_H