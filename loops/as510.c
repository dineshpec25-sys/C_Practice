#include<stdio.h>

int main()
{
    int sum = 0;
    for(int i = 11; i < 100; i++)
    {
        if(!((i % 2) == 0))
        {
            int temp = i / 10;
            if(temp == 7)
            {
                sum = sum + i;
            }
        }
    }
    printf("%d\n", sum);
    return 0;
}