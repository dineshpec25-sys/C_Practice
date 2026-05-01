#include<stdio.h>

void LCM();

int main()
{
    LCM();
    
    return 0;
}

void LCM()
{
    int num1 = 0;
    scanf("%d", &num1);
    int num2 = 0;
    scanf("%d", &num2);
    
    int result = 0;
    if(num1 > num2)
    {
        result = num2;
    }
    else
    {
        result = num1;
    }
    
    while(1)
    {
        if(((result % num1) == 0) && ((result % num2)==0))
        {
            printf("%d\n", result);
            break;
        }
        result++;
    }
}