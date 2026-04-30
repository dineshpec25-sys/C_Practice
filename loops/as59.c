// i want to print the sum of two-digit numbers whoes one's digit is 5

// 1. assign the i to a temp 
// 2. from temp remove the last digit by divide it by 10
// 3. check temp by if
// 4. if true add to sum

#include<stdio.h>

int main()
{
    int sum = 0;
    for(int i = 11; i < 100; i++)
    {
        int temp = i%10;
        if(temp == 5)
        {
            printf("%d\n", i);
            sum = sum + i;
        }
    }
    printf("%d\n", sum);
    return 0;
}