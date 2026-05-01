// i want to print odd numbers from 1 to 9

// i will give the constrians to the for start = 1 and less than 10
//     i will use a if to find which is even and omit that one
//     in else part only the odd will print while the even will be 
//     omitted using continue statement


#include<stdio.h>

int main()
{
    for(int i = 0; i < 10; i++)
    {
        if(!((i % 2) == 0))
        {
            printf("%d\n", i);
        }
    }

    return 0;
}