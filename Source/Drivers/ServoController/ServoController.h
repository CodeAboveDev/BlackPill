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
#ifndef ServoController_H
#define ServoController_H

#include <stdint.h>

namespace CodeAbove::Drivers
{

class ServoController
{
public:
    virtual void SetAngle(uint16_t angle, uint8_t channel) = 0;

private:

};

} // namespace CodeAbove::Drivers

#endif // ServoController_H