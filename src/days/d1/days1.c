#include <stdio.h>

int main(void)
{
    int a = 10;
    int b = 20;

    printf("a = %d, address of a = %p\n", a, (void *)&a);
    printf("b = %d, address of b = %p\n", b, (void *)&b);

    return 0;
}
