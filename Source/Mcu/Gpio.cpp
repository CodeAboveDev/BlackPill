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
