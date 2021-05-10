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
#include "Drivers/ServoController/impl/PCA9685ServoController.h"

using namespace CodeAbove;

PCA9685Servo::PCA9685Servo(Drivers::PCA9685ServoController& controller, uint8_t channel)
: m_Controller(controller), m_Channel(channel)
{

}

void PCA9685Servo::SetAngle(uint16_t angle)
{
    m_Controller.SetServoAngle(m_Channel, angle);
}

void PCA9685Servo::SetRange(uint16_t min, uint16_t max)
{
    Range.Min = min;
    Range.Max = max;
}
