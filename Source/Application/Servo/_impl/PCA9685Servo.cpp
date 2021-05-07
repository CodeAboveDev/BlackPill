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
#include "PCA9685Servo.h"

using namespace CodeAbove;

PCA9685Servo::PCA9685Servo(PCA9685ServoController *controller, PCA9685ServoChannel channel)
: m_Controller(controller), m_Channel(channel)
{

}

void PCA9685Servo::SetAngle(uint16_t angle)
{
    m_Controller.SetServoAngle(channel, angle);
}

void PCA9685Servo::SetRange(uint16_t min, uint16_t max)
{
    Range.Min = min;
    Range.Max = max
}
