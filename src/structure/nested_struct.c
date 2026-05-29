#include<stdio.h>
#include<stdlib.h>

struct Date
{
    int day;
    int month;
    int year;
};

struct student
{
    int roll;
    struct Date dob;
};

int main()
{
    struct student *s;

    int count = 0;
    printf("Enter the count of the student : ");
    scanf("%d", &count);

    s = malloc(count * sizeof(struct student));

    int c=0;
    do{
        printf("Enter the roll number : ");
        scanf("%d", &s[c].roll);
        printf("Enter the DOB : ");
        scanf("%d %d %d", &s[c].dob.day, &s[c].dob.month, &s[c].dob.year);
        c++;
    }
    while(c < count);

    int tar;
    printf("Enter the target roll : ");
    scanf("%d", &tar);

    for(int i = 0; i < count; i++)
    {
        if(tar == s[i].roll)
        {
            printf("The Birthday of the student is %d/%d/%d\n", s[i].dob.day, s[i].dob.month, s[i].dob.year);
            break;
        }
    }

    return 0;
}