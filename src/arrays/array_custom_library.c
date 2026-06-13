#include<stdio.h>
#include<stdlib.h>

void get_input(int array[], int size)
{
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }
}

int find_max (int array[], int size)
{
    int max=array[0];
    for(int i =1; i< size; i++)
    {
        if(max<array[i])
            max=array[i];
    }
    return max;
}

int find_min (int array[], int size)
{
    int min=array[0];
    for(int i =1; i< size; i++)
    {
        if(min>array[i])
            min=array[i];
    }
    return min;
}

int sumarray (int array[], int size)
{
    int sum=0;
    for(int i =0; i<size;i++)
    {
        sum=sum+array[i];
    }
    return sum;
}

void reverse_array (int array[], int size)
{
    int left=0;
    int right=size-1;
    while(left<right)
    {
        int temp=array[right];
        array[right]=array[left];
        array[left]=temp;

        left++;
        right--;
    }
}

void display_array(int array[], int size)
{
    for(int i =0;i<size;i++)
    {
        printf("%d ", array[i]);
    }
}
int main()
{
    int *array;
    int array_size;
    printf("Size of the array : ");
    scanf("%d", &array_size);
    array=malloc(array_size * sizeof(int));
    get_input(array, array_size);
    int array_max=find_max(array, array_size);
    int array_min=find_min(array, array_size);
    int array_sum=sumarray(array, array_size);
    reverse_array(array, array_size);
    printf("Max = %d\n", array_max);
    printf("Min = %d\n", array_min);
    printf("Sum = %d\n", array_sum);
    display_array(array, array_size);
    free(array);
    return 0;
}