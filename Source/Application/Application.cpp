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
#include "Application.h"
#include "../Led.h"
#include "../Mcu/Gpio.h"

Application::Application(Led& led, IDisplay& disp)
: display(disp), heartbeat(led)
{

}

void Application::Perform(void)
{
    // Async tasks
    timebase.Refresh();


    // 1ms tasks
    if(timebase.Is1msPassed())
    {

    }

    // 10ms tasks
    if(timebase.Is10msPassed())
    {

    }

    // 100ms tasks
    if(timebase.Is100msPassed())
    {
        heartbeat.Perform();
    }

    // 1000ms tasks
    if(timebase.Is1000msPassed())
    {
        display.Refresh(); //TODO: Takes too much times, slows down system
    }
}
