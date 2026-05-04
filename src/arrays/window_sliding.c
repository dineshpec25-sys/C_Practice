#include<stdio.h>
#include<stdlib.h>

void maxmium(int *t, int s, int w, int *res);
int main()
{
    int size = 0;
    
    printf("Enter the size of the array : ");
    scanf("%d", &size);
    
    int *target = malloc(size * sizeof(int));
    
    for(int i = 0; i < size; i++)
    {
        printf("Enter the %dth : ", i);
        scanf("%d", &target[i]);
    }
    
    int win = 0;
    printf("Enter the Window size :");
    scanf("%d", &win);
    
    int result[(size - win) +1];
    int *res = result;
    maxmium(target, size, win, res);
    free(target);
    
    for(int i = 0; i <((size - win) +1); i++)
    {
        printf("%d ", result[i]);
    }
}


void maxmium(int *t, int s, int w, int *res)
{
    for(int i = 0; i < ((s - w) +1); i++)
    {
        int great = t[i];
        res[i] = great;
        for(int j = i; j < i+w; j++)
        {
            if(great < t[j])
            {
                great = t[j];
                res[i] = t[j];
            }
        }
    }
    
}