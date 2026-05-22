#include <stdio.h>

struct bank_acc
{
    int acc_num;
    int balance;
};

int main()
{
    struct bank_acc *p;
    struct bank_acc customer[5];
    p = customer;

    FILE *fp;
    fp = fopen("src/structure/file/customer.txt", "w");

    if(fp == NULL)
    {
        printf("File not created");
        return 1;
    }

    for(int i = 0; i < 5; i++)
    {
        printf("Enter the account number:");
        scanf("%d", &p[i].acc_num);

        printf("Enter the current balance:");
        scanf("%d", &p[i].balance);

        fprintf(fp, "%d %d\n" , p[i].acc_num, p[i].balance);
    }
    fclose(fp);

    printf("\nData saved successfully\n");

    return 0;

}