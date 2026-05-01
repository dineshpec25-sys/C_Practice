#include <stdio.h>
#include <stdlib.h>

int* get();
int sum(int *arr);

int main()
{
    int *arr ;
    arr = get();
    int result;
    result = sum(arr);
    printf("The Sum %d\n", result);

    return 0;
}

int* get()
{
    int *a = (int*) malloc(5 * sizeof(int));
    for(int i = 0; i < 5; i++)
    {
        scanf("%d", &a[i]);
    }
    return a;
}

int sum(int *arr)
{
    int result = 0;
    for(int i = 0; i < 5; i++)
    {
        result = result + arr[i];
    }
    return result;
}