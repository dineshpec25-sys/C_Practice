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

int *studentdis(struct student *p, int target, int count);
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

    int *dob = studentdis(s, tar, count);

    free(dob);
    free(s);

    printf("The DOB %d/%d/%d\n", dob[0], dob[1], dob[2]);
    return 0;
}

int *studentdis(struct student *p, int target, int count)
{
    int *result;
    result=malloc(3 * sizeof(int));

    for(int i = 0; i < count; i++)
    {
        if(target == p[i].roll)
        {
            result[0]=p[i].dob.day;
            result[1]=p[i].dob.month;
            result[2]=p[i].dob.year;

            break;
        }
    }
    return result;
}