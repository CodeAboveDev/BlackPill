#include "Gpio.h"

template <typename E>
constexpr auto etoi(E const value)
{
    return static_cast<std::underlying_type_t<E>>(value);
}

void Gpio::SetPinMode(const Pin pin, const Mode mode)
{
    MODER = (MODER & ~(0x00000003 << (etoi(pin) * 2))) | (etoi(mode) << (etoi(pin) * 2));
}

void Gpio::SetOutputType(const Pin pin, const OutputType type)
{
    OTYPER = (OTYPER & ~(0x00000001 << etoi(pin))) | (etoi(type) << etoi(pin));
}

void Gpio::SetOutputSpeed(const Pin pin, const OutputSpeed speed)
{
    OSPEEDR = (OSPEEDR & ~(0x00000003 << (etoi(pin) * 2))) | (etoi(speed) << (etoi(pin) * 2));
}

void Gpio::SetPinPull(const Pin pin, const Pull pull)
{
    PUPDR = (PUPDR & ~(0x00000003 << (etoi(pin) * 2))) | (etoi(pull) << (etoi(pin) * 2));
}

bool Gpio::ReadPin(const Pin pin)
{
    return (IDR & (1 << etoi(pin))) == 0 ? false : true;
}

void Gpio::SetPin(const Pin pin)
{
    BSRR |= (1 << etoi(pin));
}

void Gpio::ResetPin(const Pin pin)
{
    BSRR |= ((1 << etoi(pin)) << 16);
}



