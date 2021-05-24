/*****************************************************************
 * Copyright (c) 2021 CodeAbove.
 * All rights reserved.
 *
 * This software component is licensed by CodeAbove under
 * BSD 3-Clause license, the 'License'. You may not use
 * this file except in compliance with the License. You
 * may obtain a copy of the License at:
 *                  opensource.org/licenses/BSD-3-Clause
 ****************************************************************/
#ifndef I2c_H
#define I2c_H

#include <stdint.h>
#include <type_traits>

class I2c
{
public:
    enum class ClockSpeedMode : uint8_t
    {
        Standard,
        Fast
    };

    enum class DutyCycle : uint8_t
    {
        DC_2,
        DC_16_9,
    };

    void SetClockSpeed(uint32_t speed, uint32_t pclk1ClockFrequency);
    void SetClockSpeedMode(ClockSpeedMode mode);
    void SetControlClockRegister(uint32_t speed, uint32_t pclk1ClockFrequency, DutyCycle dutyCycle);
    void SetOwnAddress1(uint8_t address);
    void Enable(void);

    void Write(uint8_t byte);
    uint8_t Read(void);

private:
    static constexpr uint32_t StandardSpeedMax_kHz { 100000 }; 
    static constexpr uint32_t FastSpeedMax_kHz { 400000 };

    union CR2_register
    {
        struct CR2_bits
        {
            uint8_t FREQ : 6;
            const uint8_t Reserved1 : 2;
            uint8_t ITERREN : 1;
            uint8_t ITEVTEN : 1;
            uint8_t ITBUFEN : 1;
            uint8_t DMAEN : 1;
            uint8_t LAST : 1;
            uint32_t Reserved2 : 19;
        } __attribute__((packed));

        uint32_t value;
        struct CR2_bits bits;
    };

    union DR_register
    {
        struct DR_bits
        {
            uint8_t DR : 8;
            const uint32_t Reserved : 24;
        } __attribute((packed));

        uint32_t value;
        struct DR_bits bits;
    };

    union CCR_register
    {
        struct CCR_bits
        {
            uint16_t CCR : 12;
            const uint8_t Reserved1 : 2;
            DutyCycle DUTY : 1;
            ClockSpeedMode FS : 1;
            const uint16_t Reserved2 : 16;
        } __attribute__((packed));

        uint32_t value;
        struct CCR_bits bits;
    };

    union TRISE_register
    {
        struct TRISE_bits
        {
            uint8_t TRISE : 6;
            const uint32_t Reserved : 26;
        } __attribute__((packed));

        uint32_t value;
        struct TRISE_bits bits;
    };

    volatile uint32_t CR1;
    volatile union CR2_register CR2;
    volatile uint32_t OAR1;
    volatile uint32_t OAR2;
    volatile union DR_register DR;
    volatile uint32_t SR1;
    volatile uint32_t SR2;
    volatile union CCR_register CCR;
    volatile union TRISE_register TRISE;
    volatile uint32_t FLTR;

};

static_assert(std::is_standard_layout<I2c>::value, "I2C class is NOT standard layout");

#endif // I2c_H