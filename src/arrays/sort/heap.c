#include<stdio.h>
#include<stdlib.h>

int *con(char **in, int n)
{
    int *arr = (int*)malloc(sizeof(int)*n);
    if(arr == NULL)
    {
        puts("error");
        return arr;
    }
    for(int i = 0; i < n; i++)
    {
        arr[i]=atoi(in[i+1]);
    }
    return arr;
}

void dis(int *arr, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int *arr, int i, int n)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[largest] < arr[left])
        largest = left;
    if (right < n && arr[largest] < arr[right])
        largest = right;
    if( largest != i)
    {
        swap(&arr[i],&arr[largest]);
        heapify(arr,largest,n);
    }
}
void sort(int *arr, int n)
{
    // Phase 1: build the max heap, bottom-up
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, i, n);

    // Phase 2: move the max to the end, shrink the heap, repair the root
    for (int size = n - 1; size > 0; size--)
    {
        swap(&arr[0], &arr[size]);
        heapify(arr, 0, size);
    }
}
int main(int argc, char **argv)
{
    int n = argc-1;
    int *arr = con(argv, n);
    sort(arr,n);
    dis(arr,n);
    free(arr);
}
