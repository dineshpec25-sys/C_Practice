#include <stdio.h>

struct student
{
    int roll;
    float marks;
};

void dis(struct student *ptr)
{
    printf("The student roll number : %d\n", ptr->roll);
    printf("The student's marks : %.2f\n", ptr->marks);

    return;
}

int main()
{
    struct student s;
    struct student *p;

    p=&s;

    printf("Enter the roll number : ");
    scanf("%d", &p->roll);
    printf("Enter the marks : ");
    scanf("%f", &p->marks);

    dis(p);

    return 0;
}