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
#ifndef PCA9685Servo_H
#define PCA9685Servo_H

#include <stdint.h>

#include "Application/Servo/Servo.h"
#include "Drivers/ServoController/impl/PCA9685ServoController.h"

namespace CodeAbove
{

class PCA9685Servo : public Servo
{
public:
    PCA9685Servo(Drivers::PCA9685ServoController *controller, PCA9685ServoChannel channel);

    void SetAngle(uint16_t angle) final override;
    void SetRange(uint16_t min, uint16_t max) final override;

private:
    Drivers::PCA9685ServoController& m_Controller; // TODO: Abstract ServoController instead?

    const PCA9685ServoChannel& m_Channel;

};

} // namespace CodeAbove

#endif // PCA9685Servo_H