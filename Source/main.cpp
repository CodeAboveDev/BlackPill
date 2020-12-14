#include <stdint.h>
#include "Mcu/Gpio.h"
#include "stm32f411xe.h"

int main(void)
{
    Gpio &gpioC = *reinterpret_cast<Gpio *>(GPIOC_BASE);

    while(1)
    {
    }
}