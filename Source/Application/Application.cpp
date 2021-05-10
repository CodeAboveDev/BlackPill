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
#include "Servo/Servo.h"
#include "Drivers/Led/Led.h"
#include "Mcu/Gpio.h"

using namespace CodeAbove;

Application::Application(Led& led, Display& disp, Servo& servo)
: display(disp), m_Servo(servo), heartbeat(led)
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

        m_Servo.SetAngle(30);
        m_Servo.SetAngle(150);
    }
}
