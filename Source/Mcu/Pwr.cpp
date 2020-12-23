/*****************************************************************
 * Copyright (c) 2020 CodeAbove.
 * All rights reserved.
 *
 * This software component is licensed by CodeAbove under
 * BSD 3-Clause license, the 'License'. You may not use
 * this file except in compliance with the License. You
 * may obtain a copy of the License at:
 *                  opensource.org/licenses/BSD-3-Claus
 ****************************************************************/
#include "Pwr.h"

void Pwr::SetRegulatorVoltageScaling(RegulatorVoltageScaling rvs)
{
    CR.bits.VOS = rvs;
}