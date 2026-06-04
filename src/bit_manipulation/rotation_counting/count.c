#include <stdio.h>
#include <stdint.h>
#define bit 8

int set_count(uint8_t reg);
int zero_count(uint8_t reg);

int main()
{
    uint8_t reg = 0b11111000;
    
    int sc = set_count(reg);
    int zc = zero_count(reg);

    printf("The total number of set in the register is %d\n", sc);
    printf("The total number of zero in the register is %d\n", zc);

    return 0;
}

int set_count(uint8_t reg)
{
    int count = 0;
    while(reg)
    {
        reg = reg & (reg-1);
        count++;
    }

    return count;
}

int zero_count(uint8_t reg)
{
    uint8_t result = bit - set_count(reg);

    return result;
}