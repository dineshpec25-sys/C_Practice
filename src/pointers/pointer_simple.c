#include <stdio.h>

int main()
{
    int x = 10;
    int *y = &x;
    printf("The Value of x = %d\n", x);
    printf("The Value of address of x = %d\n", &x);
    printf("The Value of y = %d\n", y);
    printf("The Value of = %d\n", *y);
    
    scanf("%d", &(*y));
    
    printf("The Value of x = %d", x);
    return 0;
}
