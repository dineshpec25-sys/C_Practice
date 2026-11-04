#include<stdio.h>
#include<stdlib.h>

//in insertion sort
int *conversion(char **in, int n)
{
    int *arr = (int*)malloc(sizeof(int)*n);

    for(int i = 0; i < n; i++)
    {
        arr[i] = atoi(in[i+1]);
    }
    return arr;
}

void sortin(int *arr, int n)
{
    for(int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i-1;

        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j = j -1;
        }
        arr[j+1]=key;
    }
}

void display_array(int *arr, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    int n = argc-1;
    int *arr = conversion(argv, n);
    sortin(arr,n);
    display_array(arr, n);
}
