#include<stdio.h>

int main()
{
    int sum = 0;
    int target = 0;
    scanf("%d", &target);

    for(int i = 0; target != 0; i++)
    {
        int temp = target % 10;
        sum = sum + temp;
        target = target / 10;
    }
    printf("%d\n", sum);
    return 0;
}