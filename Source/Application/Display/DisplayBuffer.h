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
#ifndef DisplayBuffer_H
#define DisplayBuffer_H

#include <stdint.h>

template <uint16_t X, uint16_t Y>
class DisplayBuffer
{
public:
    static union Buffer
    {
        uint8_t u8[X*Y*2];
        uint16_t u16[X*Y];
    } buf;

    static struct Dimension
    {
        constexpr static uint16_t x = X;
        constexpr static uint16_t y = Y;
    } dim;

    static void SetPixel(int16_t x, int16_t y, uint16_t color)
    {
        buf.u8[(y * dim.y + x) * 2] = (color >> 8);
        buf.u8[(y * dim.y + x) * 2 + 1] = (color & 0xFF);
    };
};

template <uint16_t X, uint16_t Y>
class DisplayBuffer<X, Y>::Buffer DisplayBuffer<X, Y>::buf;

#endif // DisplayBuffer_H