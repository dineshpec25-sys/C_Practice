#include<stdio.h>
#include<string.h>
#include<stdbool.h>

void get_input(char input[50])
{
    scanf("%s", input);
}

void duplicate_string(char string1[50], char string2[50])
{
    strcpy(string2, string1);
}

void reverse_string(char string[50], int size)
{
    int left=0;
    int right=size-1;
    while(left<right)
    {   //swap
        char temp;
        temp=string[left];
        string[left]=string[right];
        string[right]=temp;

        left++;
        right--;
    }
    printf("%s", string);
}

bool compare_string(char string1[50], char string2[50])
{
    if(!strcmp(string1, string2))
        return true;
    return false;
}

int main()
{
    char input_string[50];
    get_input(input_string);
    char work_string[50];
    duplicate_string(input_string, work_string);
    int size=strlen(work_string);
    reverse_string(work_string, size);
    if(compare_string(input_string, work_string))
        printf("True");
    else
        printf("false");
    return 0;
}