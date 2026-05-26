#include <stdio.h>

typedef struct student 
{
    int roll_number;
    char name[100];
} student ;

void search(student s[],int roll_number);

int main()
{
    student s[5];

    for(int i = 0; i < 5; i++)
    {
        printf("Enter the roll number : ");
        scanf("%d", &s[i].roll_number);

        getchar();
        
        printf("Enter the Name : ");
        fgets(s[i].name, 100, stdin);
    }

    int target_roll_number;
    printf("Enter the roll number to find the name : ");
    scanf("%d", &target_roll_number);

    search(s,target_roll_number);

    return 0;
}

void search(student s[],int roll_number)
{

    for(int i = 0; i < 5; i++)
    {
        if(roll_number == s[i].roll_number)
        {
            printf("The student Name : %s", s[i].name);
            break;
        }
    }

    return ;
}