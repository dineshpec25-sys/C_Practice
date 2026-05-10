#include <stdio.h>

int main()
{
    unsigned int base = 9;
    unsigned int LED_status = 0;
    unsigned int Target_LED = 0;

    printf("Enter the number LED which need to be checked :");
    scanf("%u", &LED_status);

    unsigned int mask = (1 << LED_status);

    if(base & mask)
        printf("The LED is ON!!\n");
    else
        printf("The LED is OFF\n");

    printf("Do to want to invert the LED ? (Type 0 for NO and 1 for YES)");
    scanf("%u", &Target_LED);

    if(Target_LED)
    {
        base ^= mask;
    }

    printf("The final Status %u\n", base);
    return 0;
}