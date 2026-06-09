#include<stdio.h>
#include<string.h>
#include<stdbool.h>
void get_input(char string[50])
{
    scanf("%s", string);
}

bool is_palindrome(char string[50], int size)
{
    int left=0;
    int right=size-1;
    while(left<right)
    {
        if(!(string[left]==string[right]))
            return false;
        left++;
        right--;
    }
    return true;
}
int main()
{
    char input_array[50];
    get_input(input_array);
    int size=strlen(input_array);
    if(is_palindrome(input_array, size))
        printf("True");
    else
        printf("false");
    return 0;
}