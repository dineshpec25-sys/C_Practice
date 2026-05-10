#include<stdio.h>

int main()
{
    unsigned int x = 13; // x = 1101
    unsigned int LED_target = 0;
    printf("Enter the number of LED which is need to switch ON :");
    scanf("%u", &LED_target);

    unsigned int mask = (1 << LED_target);
    printf("The old value :%u\n", x);

    x |= mask;
    printf("The new value :%u\n", x);

    return 0;
}