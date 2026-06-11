#include<stdio.h>
#include<stdlib.h>

int compare(const void *a, const void *b)
{
    int x=*(int*)a;
    int y=*(int*)b;

    return x-y;
}
void get_input(int array[5])
{
    for(int i = 0; i < 5; i++)
    {
        scanf("%d", &array[i]);
    }
}
void display_array(int array[5])
{
    for(int i = 0; i < 5; i++)
    {
        printf("%d\t", array[i]);
    }
}
int main()
{
    int input[5];
    get_input(input);
    qsort(input, 5, sizeof(int), compare);
    display_array(input);
    return 0;
}