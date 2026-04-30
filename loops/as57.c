// i want to print two-odd numbers how sum of digit is 7

// 1. I will find the two-digit numbers
// 2. I will find the odd numbers
// 3. I will assign the two-digit number to a temp variable
// 4. I will pick the last digit of the two-digit number
// 5. I will assign it to an another variable
// 6. I will make the temp into single variable by dividing the number by 10
// 7. In the next if condition i will check the sum
// 8. If true the two-digit number will be printed

#include<stdio.h>

int main()
{
    for(int i = 0; i < 100; i++)
    {
        if(i/10)
        {
            if(!((i % 2) == 0))
            {
                int temp = i;
                int l_temp = i % 10;
                temp = i / 10;
                if((temp + l_temp) == 7)
                {
                    printf("%d\n", i);
                }
            }
        }
    }

    return 0;
}