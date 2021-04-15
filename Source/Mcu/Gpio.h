#ifndef Gpio_H
#define Gpio_H

#include <stdint.h>
#include <type_traits>

class Gpio
{
public:
    enum class Pin : uint8_t
    {
        Pin_0, Pin_1, Pin_2, Pin_3,
        Pin_4, Pin_5, Pin_6, Pin_7,
        Pin_8, Pin_9, Pin_10, Pin_11,
        Pin_12, Pin_13, Pin_14, Pin_15
    };

    enum class Mode : uint8_t
    {
        Input, // = 0b00
        Output, // = 0b01
        AlternateFunction, // = 0b10
        Analog // = 0b11
    };

    void SetPinMode(const Pin pin, const Mode mode);

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

#endif // Gpio_H