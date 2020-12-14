#include <stdint.h>
#include "Mcu/Gpio.h"
#include "stm32f411xe.h"

int main(void)
{
    Gpio &gpioC = *reinterpret_cast<Gpio *>(GPIOC_BASE);

    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
    while(1)
    {
    }
}