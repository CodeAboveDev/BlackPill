#include <stdint.h>
#include "stm32f411xe.h"

int main(void)
{
    // Enable GPIOC
    // *(uint32_t *)(0x40023800+0x30) |= (1 << 2);
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;

    // Output mode
    // *(uint32_t *)(0x40020800) &= ~(0b11 << (2*13));
    // *(uint32_t *)(0x40020800) |= (0b01 << (2*13));
    GPIOC->MODER &= ~(GPIO_MODER_MODER13_Msk);
    GPIOC->MODER |= GPIO_MODER_MODE13_0;

    // Output type push-pull
    // *(uint32_t *)(0x40020800+0x4) &= ~(0b01 << 13);
    GPIOC->OTYPER &= ~(GPIO_OTYPER_OT13_Msk);

    // Output speed low
    // Reset value for GPIOC OSPEEDR is low
    // *(uint32_t *)(0x40020800+0x8) &= ~(0b11 << (2*13));
    GPIOC->OSPEEDR &= ~(GPIO_OSPEEDR_OSPEED13_Msk);

    // Reset PC13 - LED ON
    // *(uint32_t *)(0x40020800+0x10) &= ~(1 << 13);
    GPIOC->ODR &= ~(GPIO_ODR_OD13_Msk);

    while(1)
    {
    }
}