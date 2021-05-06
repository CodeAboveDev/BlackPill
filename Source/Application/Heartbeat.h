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
#ifndef Heartbeat_H
#define Heartbeat_H

#include "Drivers/Led/Led.h"

class Heartbeat
{
public:
    Heartbeat(Led& led);

    void Perform(void);

private:
    Led& led;
};

#endif // Heartbeat_H
