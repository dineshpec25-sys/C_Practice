#include<stdio.h>
#include<string.h>

#define MAX_INPUT 50
void get_input(char string[MAX_INPUT])
{
    scanf("%s", string);
}

void vowel_swap(char string[MAX_INPUT], int size)
{
    int left=0;
    int right=size-1;
    while(left<right)
    {
        if(!(string[left]=='a' || 
           string[left]=='e' ||
           string[left]=='i' ||
           string[left]=='o'||
           string[left]=='u'))
                left++;
        else if(!((string[right]=='a' || 
           string[right]=='e' ||
           string[right]=='i' ||
           string[right]=='o'||
           string[right]=='u')))
                right--;
        else
        {
            char temp;
            temp=string[left];
            string[left]=string[right];
            string[right]=temp;

            left++;
            right--;
        }
    }
}

void display_string(char string[MAX_INPUT])
{
    printf("%s\n", string);
}
int main()
{
    char input_string[MAX_INPUT];
    get_input(input_string);
    int size=strlen(input_string);
    vowel_swap(input_string, size);
    display_string(input_string);
}