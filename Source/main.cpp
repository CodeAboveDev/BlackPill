#include <stdint.h>
#include "Mcu/Flash.h"
#include "Mcu/Gpio.h"
#include "Mcu/Pwr.h"
#include "Mcu/Rcc.h"
#include "Mcu/Spi.h"
#include "Mcu/Core/Systick.h"
#include "Led.h"
#include "Switch.h"
#include "stm32f4xx.h"

int main(void)
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
    RCC->APB1ENR |= RCC_APB1ENR_PWREN;
    RCC->APB2ENR |= RCC_APB2ENR_SPI1EN;

    Gpio &gpioA = *reinterpret_cast<Gpio *>(GPIOA_BASE);
    Gpio &gpioB = *reinterpret_cast<Gpio *>(GPIOB_BASE);
    Gpio &gpioC = *reinterpret_cast<Gpio *>(GPIOC_BASE);
    GpioPin pinA0 {gpioA, Gpio::Pin::Pin_0}; // User KEY switch
    GpioPin pinA5 {gpioA, Gpio::Pin::Pin_5}; // Display: SCL SPI1
    GpioPin pinA6 {gpioA, Gpio::Pin::Pin_6}; // Display: DC
    GpioPin pinA7 {gpioA, Gpio::Pin::Pin_7}; // Display: SDA SPI1
    GpioPin pinB0 {gpioB, Gpio::Pin::Pin_0}; // Display: RES
    GpioPin pinC13 {gpioC, Gpio::Pin::Pin_13}; // User LED

    Flash &flash = *reinterpret_cast<Flash *>(FLASH_R_BASE);
    flash.SetLatency(Flash::WaitStates::WS_3);

    Pwr &pwr = *reinterpret_cast<Pwr *>(PWR_BASE);
    pwr.SetRegulatorVoltageScaling(Pwr::RegulatorVoltageScaling::Scale_1);

    Rcc &rcc = *reinterpret_cast<Rcc *>(RCC_BASE);
    rcc.EnableHighSpeedExternalClock();
    rcc.ConfigurePll(Rcc::PllClockSource::HSE, Rcc::PllFactors(12, 96, Rcc::PllFactorP::P_2));
    rcc.EnablePll();
    rcc.SetAhbPrescaler(Rcc::AhbPrescaler::Prescaler_1);
    rcc.SetApb1Prescaler(Rcc::Apb1Prescaler::Prescaler_2);
    rcc.SetApb2Prescaler(Rcc::Apb2Prescaler::Prescaler_1);
    rcc.SetSystemClockSource(Rcc::SystemClockSource::PLL);

    Systick &systick = *reinterpret_cast<Systick *>(SysTick_BASE);
    systick.SetReload1msTick(100000000);
    systick.SetClockSource(Systick::ClockSource::AHB);
    systick.EnableInterrupt();
    systick.Enable();

    pinA5.SetMode(Gpio::Mode::AlternateFunction);
    pinA5.SetAlternateFunction(Gpio::AlternateFunction::AF05_SPI1_I2S1SPI2_I2S2_SPI3_I2S3);
    pinA7.SetMode(Gpio::Mode::AlternateFunction);
    pinA7.SetAlternateFunction(Gpio::AlternateFunction::AF05_SPI1_I2S1SPI2_I2S2_SPI3_I2S3);

    Spi &spi1 = *reinterpret_cast<Spi *>(SPI1_BASE);
    spi1.SetBaudRate(Spi::BaudRate::PCLK_div8);
    spi1.SetClockPolarity(Spi::ClockPolarity::CPOL_0);
    spi1.SetClockPhase(Spi::ClockPhase::CPHA_0);
    spi1.SetDataFrameFormat(Spi::DataFrameFormat::Format_8BitData);
    spi1.SetFrameFormat(Spi::FrameFormat::MSB);
    spi1.SetSoftwareNSS();
    spi1.SetTransferMode(Spi::TransferMode::FullDuplex);
    spi1.SetMasterSelection(Spi::MasterSelection::Master);
    spi1.Enable();

    Led blueLed(pinC13);
    Switch userSwitch(pinA0);

    while(1)
    {
        
    }
}

extern "C" void SysTick_Handler(void)
{
    static uint16_t cnt = 0u;
    Gpio &gpioC = *reinterpret_cast<Gpio *>(GPIOC_BASE);
    GpioPin pinC13 {gpioC, Gpio::Pin::Pin_13};
    Led blueLed(pinC13);

    cnt += 1;
    if(cnt == 500)
    {
        blueLed.On();
    }
    else if(cnt == 1000)
    {
        blueLed.Off();
        cnt = 0;
    }
}
