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
#ifndef Gpio_H
#define Gpio_H

#include <stdint.h>
#include <type_traits>

class Gpio
{
public:
    enum class Pin : uint8_t
    {
        Pin_0,  Pin_1,  Pin_2,  Pin_3,
        Pin_4,  Pin_5,  Pin_6,  Pin_7,
        Pin_8,  Pin_9,  Pin_10, Pin_11,
        Pin_12, Pin_13, Pin_14, Pin_15
    };

    enum class Mode : uint8_t
    {
        Input,
        Output,
        AlternateFunction,
        Analog
    };

    enum class Pull : uint8_t
    {
        No,
        Up,
        Down
    };

    enum class OutputType : uint8_t
    {
        PushPull,
        OpenDrain
    };

    enum class OutputSpeed : uint8_t
    {
        Low,
        Medium,
        Fast,
        High
    };

    enum class AlternateFunction : uint8_t
    {
        AF00_SYS_AF, 
        AF01_TIM1_TIM2,
        AF02_TIM3_TIM4_TIM5,
        AF03_TIM9_TIM10_TIM11,
        AF04_I2C1_I2C2_I2C3,
        AF05_SPI1_I2S1SPI2_I2S2_SPI3_I2S3,
        AF06_SPI2_I2S2_SPI3_I2S3_SPI4_I2S4_SPI5_I2S5,
        AF07_SPI3_I2S3_USART1_USART2,
        AF08_USART6,
        AF09_I2C2_I2C3,
        AF10_OTG1_FS,
        AF11_,
        AF12_SDIO,
        AF13_,
        AF14_,
        AF15_,
    };

    void SetPinMode(const Pin pin, const Mode mode);
    void SetOutputType(const Pin pin, const OutputType type);
    void SetOutputSpeed(const Pin pin, const OutputSpeed speed);
    void SetPinPull(const Pin pin, const Pull pull);
    void SetPin(const Pin pin);
    bool ReadPin(const Pin pin);
    void ResetPin(const Pin pin);
    void TogglePin(const Pin pin);

    void SetAlternateFunction(const Pin pin, const AlternateFunction function);

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
    void Toggle(void) const;

    bool GetState(void) const;

    void SetMode(const Gpio::Mode mode) const;
    void SetPull(const Gpio::Pull pull) const;
    void SetAlternateFunction(const Gpio::AlternateFunction function) const;

private:
    Gpio& gpio;
    const Gpio::Pin pin;
};

static_assert(std::is_standard_layout<Gpio>::value, "Gpio class is NOT standard layout");

#endif // Gpio_H