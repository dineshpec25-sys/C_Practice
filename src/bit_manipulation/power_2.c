#include <stdio.h>

int power_2(int target)
{
    return target > 0 && !(target & (target - 1));
}

int power_4(int target)
{
    return target > 0 &&
           !(target & (target - 1)) &&
           (target & 0x55555555);
}

int power_8(int target)
{
    return target > 0 &&
           !(target & (target - 1)) &&
           (target & 0x49249249);
}

int power_16(int target)
{
    return target > 0 &&
           !(target & (target - 1)) &&
           (target & 0x11111111);
}

int main()
{
    int number;

    printf("Enter the number: ");
    scanf("%d", &number);

    if (power_2(number))
        printf("It is power of 2\n");

    if (power_4(number))
        printf("It is power of 4\n");

    if (power_8(number))
        printf("It is power of 8\n");

    if (power_16(number))
        printf("It is power of 16\n");

    return 0;
}
