#include <stdio.h>

int fact(int count, int mul)
{
    if(count == 0) return mul;

    if(count != 0)
    {
        mul=fact(count, mul)*fact(count-1, mul);
    }
}

int main()
{
    int count;
    printf("Enter the amount : ");
    scanf("%d", &count);

    int ans=0;
    ans=fact(count, ans);
    printf("The factorial : %d", ans);
}