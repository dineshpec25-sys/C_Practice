#include<stdio.h>

void check_prime();

int main()
{
    check_prime();
    
    return 0;
}

void check_prime()
{
    int target = 0;
    scanf("%d", &target);
    
    if(target <= 1)
    {
        printf("Neither prime nor compsite");
        return;
    }
    
    int prime = 1;
    for(int i = 2; i*i <= target; i++)
    {
        if((target % i) == 0){
            prime = 0;
            break;
        }
    }
    if(prime)
    {
        printf("Prime");
    }
    else
    {
        printf("Not Prime");
    }
}