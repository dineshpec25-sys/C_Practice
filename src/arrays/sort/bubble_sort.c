#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv)
{
    if(argc <= 1)
    {
        printf("invalid arugments!");
        return 1;
    }
    int arr[argc-1];
    for(int i = 0; i < argc-1; i++)
    {
        arr[i]=atoi(argv[i+1]);
    }

    for(int i = 0; i < argc-1; i++)
    {
        for(int j = 0; j < (argc-2-i); j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    for(int i = 0; i < argc -1 ; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
