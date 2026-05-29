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

struct student *studentdis(struct student *p, int target, int count);
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

    struct student *found ;
    found = studentdis(s, tar, count);

    printf("The DOB %d/%d/%d\n", found->dob.day, found->dob.month, found->dob.year);
    free(s);
    return 0;
}

struct student *studentdis(struct student *p, int target, int count)
{
    for(int i = 0; i < count; i++)
    {
        if(target == p[i].roll)
        {
            return &p[i];
        }
    }

    return NULL;
}