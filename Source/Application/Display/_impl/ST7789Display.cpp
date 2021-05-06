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
#include "ST7789Display.h"
#include "Drivers/ST7789/ST7789.h"

ST7789Display::ST7789Display(uint16_t x, uint16_t y, IST7789Spi& spi, IST7789Pin& rstPin, IST7789Pin& dcPin, uint8_t* buf)
: IDisplay(x,y), st7789(spi, rstPin, dcPin, buf)
{
    st7789.Init();
}

void ST7789Display::Refresh(void)
{
    st7789.RefreshDisplay();
}
