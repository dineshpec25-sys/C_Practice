#include<stdio.h>
#include<stdlib.h>
// a function to convert input into array
int *con(char **in, int n)
{
    int *arr=(int*)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++)
    {
        arr[i]=atoi(in[i+1]);
    }
    return arr;
}
int partition(int *arr, int low, int high)
{
    int pv = arr[high];
    int i = low-1;
    for(int j = low;j<high;j++){
        if(arr[j] > pv)
        {
            i++;
            int temp = arr[j];
            arr[j]=arr[i];
            arr[i]=temp;
        }
    }
    i++;
    arr[high]=arr[i];
    arr[i]=pv;
    return i;
}
//the actual the sorting code
void sort(int *arr, int low, int high)
{
    if(low<high)
    {
        int pi=partition(arr, low, high);
        sort(arr, low, pi-1);
        sort(arr, pi+1, high);
    }
}
//to display
void display(int *arr, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(int argc, char **argv){
    int n = argc-1;
    int *arr = con(argv,n);
    sort(arr, 0, n-1);
    display(arr,n);
    return;
}
