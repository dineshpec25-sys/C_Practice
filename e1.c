#include <stdio.h>
int main()
{
    int x ;
    x = 1;

    loop: if(x < 20)
    {
        if(((x%2) != 0) && ((x/10) != 0)){
            printf("%d\n", x);
        }
        x++;
        goto loop;
    }
}