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
#ifndef IPS_240x240_H
#define IPS_240x240_H

#include "../Display/IDisplay.h"
#include "../../Drivers/ST7789/ST7789.h"

class IPS_240x240 : public IDisplay
{
public:
    IPS_240x240(IST7789Spi& spi, IST7789Pin& rstPin, IST7789Pin& dcPin, uint8_t* buf);

    void Refresh(void) final override;

private:
    ST7789 st7789;

};

#endif // IPS_240x240_H