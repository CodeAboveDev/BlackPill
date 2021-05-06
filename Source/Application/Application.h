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
#ifndef Application_H
#define Application_H

#include "Heartbeat.h"
#include "TimeBase.h"
#include "Display/Display.h"
#include "Drivers/Led/Led.h"

class Application
{
public:
    Application(Led& led, Display& disp);
    
    void Perform(void);
private:
    Display& display;

    Heartbeat heartbeat;
    TimeBase timebase;


};

#endif // Application_H