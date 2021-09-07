#include <stdint.h>
#include "Mcu/Flash.h"
#include "Mcu/Gpio.h"
#include "Mcu/Pwr.h"
#include "Mcu/Rcc.h"
#include "stm32f411xe.h"

int main(void)
{
    Gpio& gpioA = *reinterpret_cast<Gpio*>(GPIOA_BASE);
    Gpio& gpioC = *reinterpret_cast<Gpio*>(GPIOC_BASE);
    Rcc& rcc = *reinterpret_cast<Rcc*>(RCC_BASE);

    Flash &flash = *reinterpret_cast<Flash*>(FLASH_R_BASE);
    flash.SetLatency(Flash::WaitStates::WS_3);

    Pwr &pwr = *reinterpret_cast<Pwr*>(PWR_BASE);
    pwr.SetRegulatorVoltageScaling(Pwr::RegulatorVoltageScaling::Scale_1);

    rcc.SetPllClockSource(Rcc::PllClockSource::HSE);
    rcc.SetPllFactors(Rcc::PllFactors(12, 96, Rcc::PllFactorP::P_2));
    rcc.SetPrescalers(Rcc::Prescalers(Rcc::AhbPrescaler::Prescaler_1, Rcc::Apb1Prescaler::Prescaler_2, Rcc::Apb2Prescaler::Prescaler_1));
    rcc.EnableHighSpeedExternalClock();
    rcc.EnablePll();
    rcc.SetSystemClockSource(Rcc::SystemClockSource::PLL);

    // Enable GPIOA and GPIOC
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;

    // PC13 - Output mode
    gpioC.SetPinMode(Gpio::Pin::Pin_13, Gpio::Mode::Output);

    // PC13 - Output type push-pull
    gpioC.SetOutputType(Gpio::Pin::Pin_13, Gpio::OutputType::PushPull);

    // PC13 - Output speed low
    // Reset value for GPIOC OSPEEDR is low
    gpioC.SetOutputSpeed(Gpio::Pin::Pin_13, Gpio::OutputSpeed::Low);

    // PA0 - Input mode
    gpioA.SetPinMode(Gpio::Pin::Pin_0, Gpio::Mode::Input);

    // PA0 - Enable pull-up register
    gpioA.SetPinPull( Gpio::Pin::Pin_0 , Gpio::Pull::Up);

    while(1)
    {
        // Switch pressed -> input is low
        if(!(gpioA.ReadPin(Gpio::Pin::Pin_0)))
        {
            // Output low -> LED On
            gpioC.ResetPin(Gpio::Pin::Pin_13);
        }
        else
        {
            // Output high -> LED Off
            gpioC.SetPin(Gpio::Pin::Pin_13);
        }   
    }
}