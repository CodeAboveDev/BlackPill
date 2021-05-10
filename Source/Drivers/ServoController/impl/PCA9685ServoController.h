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
#ifndef PCA9685ServoController_H
#define PCA9685ServoController_H

#include "Drivers/ServoController/ServoController.h"
#include "Libraries/PCA9685/PCA9685.h"

namespace CodeAbove::Drivers
{

class PCA9685ServoController : public ServoController
{
public:
    PCA9685ServoController();

    // TODO: Channel enum class coming from ServoController abstract class?
    // Or something else, but how to limit values?
    void SetServoAngle(uint16_t angle, uint8_t channel) final override;

private:
    Libraries::PCA9685 m_PCA9685;

};

} // namespace CodeAbove::Drivers

#endif // PCA9685ServoController_H