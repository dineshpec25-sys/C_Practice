#include<stdio.h>

int count1(int num);
void disp_interchange_first_last_digit();

int main()
{
    disp_interchange_first_last_digit();
    
    return 0;
}

int count1(int num)
{
    int count = 0;
    for(int i = 0; num != 0; i++)
    {
        count++;
        num = num / 10;
    }
    return count;
}

void disp_interchange_first_last_digit()
{
    int target = 0;
    int temp = 0;
    scanf("%d", &target);
    int count = 0;
    count = count1(target);
    if(count <= 1)
    {
        printf("%d\n", target);
        return;
    }
    int last = 0;
    last = target % 10;
    target = target - last;
    for(int i = 1; i < count; i++)
    {
       last = last * 10; 
    }
    temp = target;
    for(int i = 0; i < (count-1); i++ )
    {
        temp = temp / 10;
    }
    int first = temp;
    for(int i = 1; i < count; i++)
    {
       temp = temp * 10; 
    }
    target = target - temp;
    target = target + last;
    target = target + first;
    printf("%d\n", target);
}