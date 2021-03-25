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
#ifndef ST7789Spi_H
#define ST7789Spi_H

#include "../ST7789/ST7789.h"
#include "../../Mcu/Spi.h"

class ST7789Spi : public IST7789Spi
{
public:
    ST7789Spi(Spi& spi) : spi(spi) {};

    void Write(uint8_t byte) override
    {
        spi.Write(byte);
    };

    void Write(const uint8_t* buffer, size_t size) override
    {
        spi.Write(buffer, size);
    };

private:
    Spi& spi;
};

#endif // ST7789Spi_H