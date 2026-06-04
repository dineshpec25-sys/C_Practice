#include <stdio.h>
#include <stdint.h>

#define bit 8

uint8_t ror(uint8_t reg, int pos);

int main()
{
    int pos;
    uint8_t reg = 0b11111011;

    printf("Enter the position to move : ");
    scanf("%d", &pos);

    uint8_t result = ror(reg, pos);

    printf("%b\n", result);

    return 0;
}

uint8_t ror(uint8_t reg, int pos)
{
    uint8_t reult = (reg >> pos) | (reg << (bit - pos));
    return reult;
}