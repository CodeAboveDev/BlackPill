/*****************************************************************
 * Copyright (c) 2020 CodeAbove.
 * All rights reserved.
 *
 * This software component is licensed by CodeAbove under
 * BSD 3-Clause license, the 'License'. You may not use
 * this file except in compliance with the License. You
 * may obtain a copy of the License at:
 *                  opensource.org/licenses/BSD-3-Clause
 ****************************************************************/
#ifndef Systick_H
#define Systick_H

#include <stdint.h>
#include <type_traits>

class Systick
{
public:
    enum class ClockSource : uint8_t
    {
        AHB_dividedBy8,
        AHB
    };

    void Enable(void);
    void EnableInterrupt(void);
    void SetClockSource(const ClockSource source);
    void SetReload(const uint32_t reload);
    void SetReload1msTick(const uint32_t clockFrequency);

private:
    union CTRL_register
    {
        struct CTRL_bits
        {
            uint8_t ENABLE : 1;
            uint8_t TICKINT : 1;
            ClockSource CLKSOURCE : 1;
            const uint16_t Reserved1 : 13;
            uint8_t COUNTFLAG : 1;
            const uint16_t Reserved2 : 15;
        };

        uint32_t value;
        struct CTRL_bits bits;
    };

    union LOAD_register
    {
        struct LOAD_bits
        {
            uint32_t RELOAD : 24;
            const uint8_t Reserved : 8;
        };

        uint32_t value;
        struct LOAD_bits bits;
    };

    volatile union CTRL_register CTRL;
    volatile union LOAD_register LOAD;
    volatile uint32_t VAL;
    volatile uint32_t CALIB;
};

class SystickInterruptHandler
{
public:
    SystickInterruptHandler() = delete;
    ~SystickInterruptHandler() = delete;

    static void ISR(void);
    static uint32_t GetSystemTime(void);

private:
    volatile static uint32_t SystemTime;
};

static_assert(std::is_standard_layout<Systick>::value, "Systick class is NOT standard layout");

#endif // Systick_H