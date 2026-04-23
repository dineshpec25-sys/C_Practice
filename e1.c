#include <stdio.h>
int main()
{
    int x ;
    x = 1;

    loop: if(x < 100)
    {
        if(((x%2) != 0) && ((x/10) != 0)){
            int lastdigit = x % 10;
            int firstdigit = x / 10;
            if((lastdigit + firstdigit) == 7)
            {
                printf("%d\n", x);
            }
        }
        x++;
        goto loop;
    }
}