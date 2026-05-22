#include <stdio.h>

struct bank_acc
{
    int acc_num;
    int balance;
}

int witdraw(int existing_amount)
{
    int credit_amount;
    printf("Enter the amount to be credited :");
    scanf("%d", credit_amount);

    return existing_amount - credit_amount;
}

int deposit(int existing_amount)
{
    int deposit_amount;
    printf("Enter the amount to be deposited :");
    scanf("%d", deposit_amount);

    return existing_amount + deposit_amount;
}

void acc_balance(int existing_amount)
{
    printf("%d existing amount\n", existing_amount);

    return 0;
}

int main()
{
    struct bank_acc *p;
    struct bank_acc customer[5];
    p = customer;

    FILE *fp;
    fp = fopen("customer.txt", "w");

    if(fp == NULL)
    {
        printf("File not created");
        return 1;
    }

    for(int i = 0; i < 5; i++)
    {
        printf("Enter the account number:");
        scanf("%d", &p[i]->acc_num);

        printf("Enter the current balance:");
        scanf("%d", &p[i]->balance);

        fprint(fp, "%d %d\n" , *p[i]->acc_num, *p[i]->balance);
    }
    fclose(fp);

    printf("\nData saved successfully");

    return 0;

}