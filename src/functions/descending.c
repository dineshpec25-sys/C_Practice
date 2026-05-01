#include <stdio.h>
#include <stdlib.h>

int* get();
void put(int *arr);
int* descending(int *arr);

int main()
{
    int *arr = get();
    int *result = descending(arr);
    put(result);
}

int* get()
{
    int *arr = malloc(5 * sizeof(int));
    
    for(int i = 0; i < 5; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    return arr;
}

int* descending(int *arr)
{
    int temp = 0;
    for(int i = 0; i < 5; i++)
    {
        for(int j = i+1; j < 5; j++)
        {
            if(arr[i] < arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    
    return arr;
}

void put(int *arr)
{
    for(int i = 0; i < 5; i++)
    {
        printf("%d\n", arr[i]);
    }
}