#include<stdio.h>
#include<stdlib.h>

int *check_odd();

int main()
{
    int *p = check_odd();
    for(int i = 0; i < 3; i++)
    {
        printf("%d\n", p[i]);
    }
    
    free(p);
    
    return 0;
}

int *check_odd()
{
    int *odd_arr = malloc(3 * sizeof(int));
    int count = 0;
    for(int i = 10; i < 100; i++)
    {
        if(!((i % 2) == 0))
        {
            int last = i % 10;
            int first = i / 10;
            if((first + last) == 7)
            {
                odd_arr[count++] = i;
            }
        }
    }
    return odd_arr;
}