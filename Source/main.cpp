#include <stdint.h>
#include "stm32f411xe.h"

int main(void)
{
    // Enable GPIOA and GPIOC
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;

    // PC13 - Output mode
    GPIOC->MODER &= ~(GPIO_MODER_MODER13_Msk);
    GPIOC->MODER |= GPIO_MODER_MODE13_0;

    // PC13 - Output type push-pull
    GPIOC->OTYPER &= ~(GPIO_OTYPER_OT13_Msk);

    // PC13 - Output speed low
    // Reset value for GPIOC OSPEEDR is low
    GPIOC->OSPEEDR &= ~(GPIO_OSPEEDR_OSPEED13_Msk);

    // PA0 - Input mode
    GPIOA->MODER &= ~(GPIO_MODER_MODER0_Msk);

    // PA0 - Enable pull-up register
    GPIOA->PUPDR &= ~(GPIO_PUPDR_PUPD0_Msk);
    GPIOA->PUPDR |= GPIO_PUPDR_PUPD0_0;

    while(1)
    {
        // Switch pressed -> input is low
        if((GPIOA->IDR & GPIO_IDR_ID0_Msk) == 0)
        {
            // Output low -> LED On
            GPIOC->ODR &= ~(GPIO_ODR_OD13);
        }
        else
        {
            // Output high -> LED Off
            GPIOC->ODR |= GPIO_ODR_OD13;
        }   
    }
}