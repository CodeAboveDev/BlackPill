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

Application::Application()
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
        static uint16_t cnt = 0u;
        Gpio &gpioC = *reinterpret_cast<Gpio *>(((0x40000000UL + 0x00020000UL) + 0x0800UL));
        GpioPin pinC13 {gpioC, Gpio::Pin::Pin_13};
        Led blueLed(pinC13);

        cnt += 1;
        if(cnt == 10)
        {
            blueLed.On();
        }
        else if(cnt == 20)
        {
            blueLed.Off();
            cnt = 0;
        }
    }
}
