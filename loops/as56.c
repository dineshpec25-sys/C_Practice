// i want to print the two-digit odd number under 20

// first i need to find which is two-digit by using a if
// inside the for the condion for the if will be number / 10
// it will be 0 for any single digit number
// after finding the two-digit number we need another if 
// for finding which is odd number

#include<stdio.h>

int main()
{
    for(int i = 0; i < 21; i++)
    {
        if(i/10)
        {
            if(!((i % 2) == 0))
            {
                printf("%d\n", i);
            }
        }
    }

    return 0;
}