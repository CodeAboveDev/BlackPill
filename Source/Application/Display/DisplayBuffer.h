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
    union Buffer
    {
        uint8_t u8[X*Y*2];
        uint16_t u16[X*Y];
    } buf;

    struct Dimension
    {
        constexpr static uint16_t x = X;
        constexpr static uint16_t y = Y;
    } dim;
};

#endif // DisplayBuffer_H