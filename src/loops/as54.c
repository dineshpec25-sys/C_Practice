// i want the sum of numbers between 6 to 1

#include<stdio.h>

int main()
{
    int num = 6;
    int sum = 0;
    for(num; num >= 1; num--)
    {
        sum = sum + num;
    }
    printf("%d\n", sum);
    return 0;
}