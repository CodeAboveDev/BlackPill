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
#ifndef Servo_H
#define Servo_H

#include <stdint.h>

namespace CodeAbove
{

class Servo
{
public:
    virtual void SetAngle(uint16_t angle) = 0;
    virtual void SetRange(uint16_t min, uint16_t max) = 0;

protected:
    struct 
    {
        uint16_t Min;
        uint16_t Max;
    } Range;

private:


};

} // namespace CodeAbove

#endif // Servo_H