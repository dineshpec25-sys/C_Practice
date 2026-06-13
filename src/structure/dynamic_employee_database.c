#include<stdio.h>
#include<stdlib.h>

typedef struct employe
{
    int id;
    char name[50];
    float salary;
} emp;

int options()
{
    int choice;
    printf("=========================\n");
    printf("1. Add Employee \n");
    printf("2. Display Employee\n");
    printf("3. Search Employee bby Id\n");
    printf("4. Exit\n");
    printf("Choice : ");
    scanf("%d", &choice);
    return choice;
}
emp *add_employe(emp e[], int *employee_count)
{
    emp *temp = realloc(e, *employee_count);
    if(temp == NULL)
    {
        printf("Memory failed");
        return e;
    }
    e = temp;
    printf("Enter Employee ID : ");
    scanf("%d", &e[*(employee_count)].id);
    printf("Enter Employee Name : ");
    scanf("%s", e[*(employee_count)].name);
    printf("Enter Employee Salary : ");
    scanf("%f", &e[*(employee_count)].salary);
    (*employee_count)++;
    return e;
}
void display_employe(emp e[], int *employee_count)
{
    printf("Total Number of Employee in the company : %d\n", *employee_count);
    for(int i = 0; i < *employee_count; i++)
    {
        printf("Employee Id: %d\n", e[i].id);
        printf("Employee Name: %s\n", e[i].name);
        printf("Employee Salary: %.2f\n", e[i].salary);
        printf("------------------------------\n");
    }
}
void search_employe_by_id(emp e[], int *employee_count)
{   
    int target=0;
    printf("Enter the id of the Employee :");
    scanf("%d", &target);
    for(int i = 0; i < *employee_count; i++)
    {
        if(e[i].id == target)
        {
        printf("Employee Id: %d\n", e[i].id);
        printf("Employee Name: %s\n", e[i].name);
        printf("Employee Salary: %.2f\n", e[i].salary);
        printf("------------------------------\n");
        }
    }
}


int main()
{
    emp *e=NULL;
    int employee_count=0;
    while(1)
    {
        int choice = options();
        if(choice == 1)
            e=add_employe(e, &employee_count);
        else if(choice == 2)
            display_employe(e, &employee_count);
        else if(choice == 3)
            search_employe_by_id(e, &employee_count);
        else
            return 0;
    }
    return 0;
}