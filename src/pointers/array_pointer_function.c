#include <stdio.h>

void increment(int *arr);
void get(int *arr);
void dis(int *arr);

int main()
{
    int arr[10] = {0};
    int *p = arr;
    get(p);
    increment(p);
    dis(p);
        
    return 0;
}

void get(int *arr)
{
    for(int i = 0; i < 10; i++)
    {
        printf("Enter the %d elements of the array = ", i);
        scanf("%d", &arr[i]);
    }
}

void increment(int *arr)
{
    for(int i = 0; i < 10; i++)
    {
        arr[i]++;
    }
}

void dis(int *arr)
{
    for(int i = 0; i < 10; i++)
    {
        printf("%d\n", arr[i]);
    }
}