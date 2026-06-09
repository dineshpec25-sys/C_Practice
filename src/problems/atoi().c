#include <stdio.h>
#include <limits.h>

int ascii_converter(char input[50])
{
    int integer=0;
    int present=1;
    int i = 0;
    for(;input[i] != '\0'; i++)
    {
        if(input[i] == ' ')
        {
            continue;
        }
        else{
            break;
        }
    }
    if(input[i] == '-')
    {    present=-1;
        i++;
    }
    else if(input[i] == '+')
    {
        i++;
    }
    for(; input[i] != '\0'; i++)
{
    if(input[i] >= '0' && input[i] <= '9')
    {
        int digit = input[i] - '0';

        if(integer > (INT_MAX - digit) / 10)
        {
            if(present == 1)
                return INT_MAX;
            else
                return INT_MIN;
        }

        integer = integer * 10 + digit;
    }
    else
    {
        break;
    }
}
    return integer * present;
}
int main()
{
    char input[50];
    fgets(input, 50, stdin);

    int integer = ascii_converter(input);

    printf("%d\n", integer);

    return 0;
}
