#include<stdio.h>

typedef struct Update_value_structure
{
    int roll_number;
    int percentage;
} Update_value_structure;

void replace_percentage(Update_value_structure s[], int new_value, int roll_number);

int main()
{
    Update_value_structure s[5];

    for(int i = 0; i < 5; i++)
    {
        printf("========================================\n");
        printf("Enter student roll number : ");
        scanf("%d", &s[i].roll_number);

        printf("Enter the student percenatge : ");
        scanf("%d", &s[i].percentage);
        printf("========================================\n");
    }

    int new = 0;
    int target_roll;
    printf("Enter the roll number of the student to change the roll number : ");
    scanf("%d", &target_roll);
    printf("Enter the new value : ");
    scanf("%d", &new);

    replace_percentage(s, new, target_roll);

    return 0;

}

void replace_percentage(Update_value_structure s[], int new_value, int roll_number)
{
    for(int i = 0; i < 5; i++)
    {
        if(s[i].roll_number == roll_number)
        {
            s[i].percentage = new_value;
            printf("%d the new percentage\n", s[i].percentage);

        }
    }

    return;
}