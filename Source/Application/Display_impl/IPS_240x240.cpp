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
#include "IPS_240x240.h"

IPS_240x240::IPS_240x240(IST7789Spi& spi, IST7789Pin& rstPin, IST7789Pin& dcPin, uint8_t* buf)
: st7789(spi, rstPin, dcPin, buf)
{
    st7789.Init();
}

void IPS_240x240::Refresh(void)
{
    st7789.RefreshDisplay();
}