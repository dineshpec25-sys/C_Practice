#include <stdio.h>
#include <stdlib.h>

struct student
{
    int roll;
    float marks;
    float attendencse;
};

int main()
{
    struct student *ptr;

    int n;
    printf("Enter the  count of the student : ");
    scanf("%d", &n);

    ptr = malloc(n * sizeof(struct student));

    for(int i = 0; i < n; i++)
    {
        printf("Enter the Roll number of the student : ");
        scanf("%d", &ptr[i].roll);

        printf("Enter the marks : ");
        scanf("%e", &ptr[i].marks);

        printf("Enter the attendence percentage : ");
        scanf("%e", &ptr[i].attendencse);
    }

    float avg = 0;
    float sum=0;
    for(int i = 0; i < n; i++)
    {
        sum = sum + ptr[i].marks;
    }

    avg = sum/n;

    printf("The avg : %.2f\n", avg);

    free(ptr);
    
    return 0;
}