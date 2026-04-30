#include<stdio.h>

int main()
{
    for(int i = 0; i < 100; i++)
    {
        if(i/10)
        {
            if(((i % 2) == 0))
            {
                int temp = i;
                int l_temp = i % 10;
                temp = i / 10;
                if((temp + l_temp) == 6)
                {
                    printf("%d\n", i);
                }
            }
        }
    }

    return 0;
}