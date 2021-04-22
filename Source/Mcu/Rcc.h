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
#ifndef Rcc_H
#define Rcc_H

#include <stdint.h>
#include <type_traits>

class Rcc
{
public:
    enum PllClockSource
    {
        HSI,
        HSE,
    };

    enum PllFactorP
    {
        P_2 = 0b00,
        P_4 = 0b01,
        P_6 = 0b10,
        P_8 = 0b11,
    };

    enum class AhbPrescaler
    {
        Prescaler_1   = 0b0000,
        Prescaler_2   = 0b1000,
        Prescaler_4   = 0b1001,
        Prescaler_8   = 0b1010,
        Prescaler_16  = 0b1011,
        Prescaler_64  = 0b1100,
        Prescaler_128 = 0b1101,
        Prescaler_256 = 0b1110,
        Prescaler_512 = 0b1111,
    };

    enum class Apb1Prescaler
    {
        Prescaler_1  = 0b000,
        Prescaler_2  = 0b100,
        Prescaler_4  = 0b101,
        Prescaler_8  = 0b110,
        Prescaler_16 = 0b111,
    };
    
    enum class Apb2Prescaler
    {
        Prescaler_1  = 0b000,
        Prescaler_2  = 0b100,
        Prescaler_4  = 0b101,
        Prescaler_8  = 0b110,
        Prescaler_16 = 0b111,
    };

    enum class SystemClockSource : uint8_t
    {
        HSI,
        HSE,
        PLL,
    };

    struct PllFactors
    {
        uint8_t m;
        uint16_t n;
        PllFactorP p;
        PllFactors(uint8_t m, uint16_t n, PllFactorP p): m(m), n(n), p(p) {};
    };

    void EnableHighSpeedInternalClock(void);
    void SetHighSpeedInternalClockTrimming(uint8_t trimming);

    void EnableHighSpeedExternalClock(void);

    void EnablePll(void);
    void ConfigurePll(PllClockSource source, PllFactors factors);

    void SetAhbPrescaler(AhbPrescaler prescaler);
    void SetApb1Prescaler(Apb1Prescaler prescaler);
    void SetApb2Prescaler(Apb2Prescaler prescaler);

    void SetSystemClockSource(SystemClockSource source);

    // AHB1ENR functions
    void EnableGpioA(void);
    void EnableGpioB(void);
    void EnableGpioC(void);

    // APB1ENR functions
    void EnablePowerInterface(void);
 
    // APB2ENR functions
    void EnableSpi1(void);

private:
    union CR_register
    {
        struct CR_bits
        {
            uint8_t HSION : 1;
            const uint8_t HSIRDY : 1;
            const uint8_t Reserved1 : 1;
            uint8_t HSITRIM : 5;
            const uint8_t HSICAL : 8;
            uint8_t HSEON : 1;
            const uint8_t HSERDY : 1;
            uint8_t HSEBYP : 1;
            uint8_t CSSON : 1;
            const uint8_t Reserved2 : 4;
            uint8_t PLLON : 1;
            const uint8_t PLLRDY : 1;
            uint8_t PLLI2SON : 1;
            const uint8_t PLLI2SRDY : 1;
            const uint8_t Reserved3 : 4;
        } __attribute__((packed));

        uint32_t value;
        struct CR_bits bits;
    };

    union PLLCFGR_register
    {
        struct PLLCFGR_bits
        {
            uint8_t PLLM : 6;
            uint16_t PLLN : 9;
            const uint8_t Reserved1 : 1;
            uint8_t PLLP : 2;
            const uint8_t Reserved2 : 4;
            PllClockSource PLLSRC : 1;
            const uint8_t Reserved3 : 1;
            uint8_t PLLQ : 4;
            const uint8_t Reserved4 : 4;
        } __attribute__((packed));

        uint32_t value;
        struct PLLCFGR_bits bits;
    };

    union CFGR_register
    {
        struct CFGR_bits
        {
            SystemClockSource SW : 2;
            const SystemClockSource SWS : 2;
            AhbPrescaler HPRE : 4;
            const uint8_t Reserved1 : 2;
            Apb1Prescaler PPRE1 : 3;
            Apb2Prescaler PPRE2 : 3;
            uint8_t RTCPRE : 5;
            uint8_t MCO1 : 2;
            uint8_t I2SSCR : 1;
            uint8_t MCO1PRE : 3;
            uint8_t MCO2PRE : 3;
            uint8_t MCO2 : 2; 
        } __attribute__((packed));

        uint32_t value;
        struct CFGR_bits bits;
    };

    union AHB1ENR_register
    {
        struct AHB1ENR_bits
        {
            uint8_t GPIOAEN : 1;
            uint8_t GPIOBEN : 1;
            uint8_t GPIOCEN : 1;
            uint8_t GPIODEN : 1;
            uint8_t GPIOEEN : 1;
            const uint8_t Reserved1 : 2;
            uint8_t GPIOHEN : 1;
            const uint8_t Reserved2 : 4;
            uint8_t CRCEN : 1;
            const uint8_t Reserved3 : 8;
            uint8_t DMA1EN : 1;
            uint8_t DMA2EN : 1;
            const uint16_t Reserved4 : 9;
        } __attribute__((packed));

        uint32_t value;
        struct AHB1ENR_bits bits;
    };

    union APB1ENR_register
    {
        struct APB1ENR_bits
        {
            uint8_t TIM2EN : 1;
            uint8_t TIM3EN : 1;
            uint8_t TIM4EN : 1;
            uint8_t TIM5EN : 1;
            const uint8_t Reserved1 : 7;
            uint8_t WWDGEN : 1;
            const uint8_t Reserved2 : 2;
            uint8_t SPI2EN : 2;
            uint8_t SPI3EN : 3;
            const uint8_t Reserved3 : 1;
            uint8_t USART2EN : 1;
            const uint8_t Reserved4 : 3;
            uint8_t I2C1EN : 1;
            uint8_t I2C2EN : 1;
            uint8_t I2C3EN : 1;
            const uint8_t Reserved5 : 4;
            uint8_t PWREN : 1;
            const uint8_t Reserved6 : 3;
        } __attribute__((packed));

        uint32_t value;
        struct APB1ENR_bits bits;
    };

    union APB2ENR_register
    {
        struct APB2ENR_bits
        {
            uint8_t TIM1EN : 1;
            const uint8_t Reserved1 : 3;
            uint8_t USART1EN : 1;
            uint8_t USART6EN : 1;
            const uint8_t Reserved2 : 2;
            uint8_t ADC1EN : 1;
            const uint8_t Reserved3 : 2;
            uint8_t SDIO : 1;
            uint8_t SPI1EN : 1;
            uint8_t SPI4EN : 1;
            uint8_t SYSCFGEN : 1;
            const uint8_t Reserved4 : 1;
            uint8_t TIM9EN : 1;
            uint8_t TIM10EN : 1;
            uint8_t TIM11EN : 1;
            const uint8_t Reserved5 : 1;
            uint8_t SPI5EN : 1;
            const uint16_t Reserved6 : 11;
        } __attribute__((packed));

        uint32_t value;
        struct APB2ENR_bits bits;
    };

    volatile union CR_register CR;
    volatile union PLLCFGR_register PLLCFGR;
    volatile union CFGR_register CFGR;
    volatile uint32_t CIR;
    volatile uint32_t AHB1RSTR;
    volatile uint32_t AHB2RSTR;
    volatile uint32_t Reserved1;
    volatile uint32_t Reserved2;
    volatile uint32_t APB1RSTR;
    volatile uint32_t APB2RSTR;
    volatile uint32_t Reserved3;
    volatile uint32_t Reserved4;
    volatile union AHB1ENR_register AHB1ENR;
    volatile uint32_t AHB2ENR;
    volatile uint32_t Reserved5;
    volatile uint32_t Reserved6;
    volatile union APB1ENR_register APB1ENR;
    volatile union APB2ENR_register APB2ENR;
    volatile uint32_t Reserved7;
    volatile uint32_t Reserved8;
    volatile uint32_t AHB1LPENR;
    volatile uint32_t AHB2LPENR;
    volatile uint32_t Reserved9;
    volatile uint32_t Reserved10;
    volatile uint32_t APB1LPENR;
    volatile uint32_t APB2LPENR; 
    volatile uint32_t Reserved11;
    volatile uint32_t Reserved12;
    volatile uint32_t BDCR;
    volatile uint32_t CSR;
    volatile uint32_t Reserved13;
    volatile uint32_t Reserved14;
    volatile uint32_t SSCGR;
    volatile uint32_t PLLI2SCFGR;
    volatile uint32_t Reserved15;
    volatile uint32_t DCKCFGR;

    void SetPllClockSource(PllClockSource source);
    void SetPllFactors(PllFactors factors);
    
};

static_assert(std::is_standard_layout<Rcc>::value, "Rcc class is NOT standard layout");

#endif // Rcc_H