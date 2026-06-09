#include <stdio.h>

int main()
{
    int input_array[]={1,2,3,4,5};
    int left=0;
    int right=4;
    while(left<right)
    {
        int temp;
        temp=input_array[left];
        input_array[left]=input_array[right];
        input_array[right]=temp;

        left++;
        right--;
    }

    // transverse a array
    for(int i = 0; i < 5; i++)
    {
        printf("%d\n", input_array[i]);
    }

    return 0;
}