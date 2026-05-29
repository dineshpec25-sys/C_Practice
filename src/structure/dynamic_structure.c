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

    ptr = malloc(5 * sizeof(struct student));

    for(int i = 0; i < 5; i++)
    {
        printf("Enter the Roll number of the student : ");
        scanf("%d", &ptr[i].roll);

        printf("Enter the marks : ");
        scanf("%e", &ptr[i].marks);

        printf("Enter the attendence percentage : ");
        scanf("%e", &ptr[i].attendencse);
    }

    printf("Roll Number : %d\n", ptr[3].roll);
    printf("Marks : %.2f\n", ptr[2].marks);
    printf("Attendence : %.2f%%\n", ptr[2].attendencse);

    return 0;
}