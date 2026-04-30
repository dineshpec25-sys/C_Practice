#include<stdio.h>

int main()
{
    int count = 0;
    int target = 0;
    scanf("%d", &target);

    for(int i = 0; target != 0; i++)
    {
        target = target / 10;
        count++;
    }
    printf("%d\n", count);
    return 0;
}