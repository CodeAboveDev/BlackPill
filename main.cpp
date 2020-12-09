#include <stdint.h>

int main(void)
{
    static uint32_t cnt;

    while(1)
    {
        cnt += 1;
    }
}