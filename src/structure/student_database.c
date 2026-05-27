#include <stdio.h>

typedef struct student 
{
    int roll_number;
    char name[100];
    int age;
    char blood_group[5];
    int height;
    int weight;
} student ;

void addStudent(student s[], int student_count);
void disStudent(student s[]);
void searchstudent(student s[]);

int main()
{
    student s[5];

    int choice;

    printf("\t==============================\n");
    printf("\t1. Add a Student\n");
    printf("\t2. Dispaly students List\n");
    printf("\t3. Search for a Student\n");
    printf("\t==============================\n");
    
    printf("Enter the Choice :");
    scanf("%d", &choice);

    for(int i = 0; i < 5; i++)
    {
        switch(choice)
        {
            case 1:
                addStudent(s, i);
                break;
            case 2:
               disStudent(s);
                break;
            case 3:
                searchstudent(s);
                break;
            default:
                printf("Invalid Choice\n");
                break;
        }
    }
    return 0;
}
// choice
// goto the respective function

void addStudent(student s[], int student_count)
{
    printf("==============================\n");
    printf("Entre the student Name : ");
    getchar();
    fgets(s[student_count].name, 100, stdin);

    printf("Entre the roll number : ");
    scanf("%d", &s[student_count].roll_number);

    printf("Enter the age of the student : ");
    scanf("%d", &s[student_count].age);

    printf("Enter the blood group of the student : ");
    scanf("%s", s[student_count].blood_group);

    printf("Enter the height of the student : ");
    scanf("%d", &s[student_count].height);


    printf("Enter the weight of the student : ");
    scanf("%d", &s[student_count].weight);
}

void disStudent(student s[])
{
    for(int i = 0; i < 5;i++)
    {
        printf("=============================");
        printf("Student Name :        %s\n", s[i].name);
        printf("Roll Number :         %d\n", s[i].roll_number);
        printf("Student Age :         %d\n", s[i].age);
        printf("Student Blood Group : %s\n", s[i].blood_group);
        printf("Student Height :      %d\n", s[i].height);
        printf("Student Weight :      %d\n", s[i].weight);

    }

    return;
}

void searchstudent(student s[])
{
    int target;

    printf("Enter the Roll Number : ");
    scanf("%d", &target);

    for(int i = 0; i< 5; i++)
    {
        if(s[i].roll_number == target)
        {
            printf("=============================");
            printf("Student Name :        %s\n", s[i].name);
            printf("Roll Number :         %d\n", s[i].roll_number);
            printf("Student Age :         %d\n", s[i].age);
            printf("Student Blood Group : %s\n", s[i].blood_group);
            printf("Student Height :      %d\n", s[i].height);
            printf("Student Weight :      %d\n", s[i].weight);

            break;
        }
    }

    return;
}