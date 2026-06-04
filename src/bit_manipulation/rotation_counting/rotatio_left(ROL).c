#include <stdio.h>
#include <stdint.h>

uint8_t rotate(uint8_t reg, int pos);

int main()
{
    int pos=0;
    uint8_t reg = 0b01001111;
    printf("Enter the position to swap : ");
    scanf("%u", &pos);

    uint8_t result = rotate(reg, pos);

    printf("%b\n", result);

    return 0;
}

uint8_t rotate(uint8_t reg, int pos)
{
    uint8_t result = (reg << pos) | (reg >> (8-pos));
    return result;
}