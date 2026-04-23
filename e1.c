#include <stdio.h>
int main()
{
    int x;
    x = 5;

    loop: if(x > 0)
    {
        printf("%d\n", x--);
        goto loop;
    }
}