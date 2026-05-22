#include <stdio.h>

struct student{
    char student_name[50];
    int student_age;
    int student_mark;
};

int main()
{
    struct student s[5];

    for(int i = 0; i < 4; i++)
    {
        printf("Enter the student name:");
        scanf("%s", s[i].student_name);

        printf("Enter the age of the student:");
        scanf("%d", &s[i].student_age);

        printf("Enter the mark of the student:");
        scanf("%d", &s[i].student_mark);
    }

    int great = s[0].student_mark;
    int count = 0;
    for(int i = 0; i < 5; i++)
    {
        if( s[i].student_mark > great)
        {
            great = s[i].student_mark;
            count = i;
        }
    }

    printf("%s scored the highest mark\n", s[count].student_name);

    return 0;
}