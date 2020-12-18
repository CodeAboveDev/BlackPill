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
#ifndef Gpio_H
#define Gpio_H

#include <stdint.h>
#include <type_traits>

class Gpio
{
public:
    enum Pin
    {
        Pin_0,  Pin_1,  Pin_2,  Pin_3,
        Pin_4,  Pin_5,  Pin_6,  Pin_7,
        Pin_8,  Pin_9,  Pin_10, Pin_11,
        Pin_12, Pin_13, Pin_14, Pin_15
    };

    enum Mode
    {
        Input,
        Output,
        AlternateFunction,
        Analog
    };

    enum Pull
    {
        No,
        Up,
        Down
    };

    void SetPinMode(const Pin pin, const Mode mode);
    void SetPinPull(const Pin pin, const Pull pull);
    void SetPin(const Pin pin);
    bool ReadPin(const Pin pin);
    void ResetPin(const Pin pin);

private:
    volatile uint32_t MODER;
    volatile uint32_t OTYPER;
    volatile uint32_t OSPEEDR;
    volatile uint32_t PUPDR;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
    volatile uint32_t BSRR;
    volatile uint32_t LCKR;
    volatile uint32_t AFRL;
    volatile uint32_t AFRH;
};

class GpioPin
{
public:
    GpioPin(Gpio& gpio, const Gpio::Pin pin);

    void Set(void) const;
    void Reset(void) const;

    bool GetState(void) const;

    void SetMode(const Gpio::Mode mode) const;
    void SetPull(const Gpio::Pull pull) const;

private:
    Gpio& gpio;
    const Gpio::Pin pin;
};

static_assert(std::is_standard_layout<Gpio>::value, "Gpio class is NOT standard layout");

#endif // Gpio_H