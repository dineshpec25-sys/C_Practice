#include <stdio.h>
#include <string.h>

int ascii_converter(char input[50])
{
    int integer=0;
    for(int i = 0; input[i] != '\0'; i++)
    {
        if(input[i] >= '0' && input[i] <= '9')
            integer = (input[i] - '0') +(integer*10);
        
    }
    return integer;
}
int main()
{
    char input[50];
    fgets(input, 50, stdin);

    int integer = ascii_converter(input);

    printf("%d\n", integer);

    return 0;
}
