#include<stdio.h>

void loop(int *num);

int main()
{
    int s_num = 0;
    int *p = &s_num;
    for(int i = 0; i < 5; i++)
    {
        loop(p);
        printf("%d\n", s_num);
    }
}

void loop(int *num)
{
    (*num)++;
}