#include <stdint.h>
#include "Mcu/Gpio.h"
#include "Led.h"
#include "Switch.h"
#include "stm32f4xx.h"

int main(void)
{
    Gpio &gpioC = *reinterpret_cast<Gpio *>(GPIOC_BASE);
    Gpio &gpioA = *reinterpret_cast<Gpio *>(GPIOA_BASE);
    GpioPin pinC13 {gpioC, Gpio::Pin::Pin_13};
    GpioPin pinA0 {gpioA, Gpio::Pin::Pin_0};

    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;

    Led blueLed(pinC13);
    Switch userSwitch(pinA0);
    blueLed.On();
    blueLed.Off();

    while(1)
    {
        if(userSwitch.GetState() == true)
        {
            blueLed.On();
        }
        else
        {
            blueLed.Off();
        }
        
    }
}