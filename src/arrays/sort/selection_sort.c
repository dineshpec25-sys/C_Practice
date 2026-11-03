#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv)
{
    int n = argc - 1;
    if(n <= 0) return 1;

    int arr[n];
    for(int i = 0; i < n; i++)
    {
        arr[i]=atoi(argv[i+1]);
    }

    for(int i = 0; i < n; i++)
    {
        int min_inx = i;
        for(int j = i+1; j<n;j++ )
        {
            if(arr[j] < arr[min_inx])
                min_inx = j;
        }

        int temp = arr[min_inx];
        arr[min_inx] = arr[i];
        arr[i] = temp;
    }
    
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
