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
#include "stm32f4xx.h"
#include "Gpio.h"

void Gpio::SetPinMode(const Pin pin, const Mode mode)
{
    uint32_t pinMask = (1 << pin);
    MODIFY_REG(MODER, (GPIO_MODER_MODER0 << (POSITION_VAL(pinMask) * 2U)), (mode << (POSITION_VAL(pinMask) * 2U)));
}

void Gpio::SetPin(const Pin pin)
{
    BSRR |= (1 << pin);
}

void Gpio::ResetPin(const Pin pin)
{
    BSRR |= ((1 << pin) << 16);
}
