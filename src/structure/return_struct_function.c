#include <stdio.h>

struct book
{
    char name[50];
    int price;
};

struct book Creation();

int main()
{
    struct book b1;

    b1=Creation();

    printf("%s\n", b1.name);
    printf("%d\n", b1.price);

    return 0;
}

struct book Creation()
{
    struct book b;

    printf("Enter the Book name : ");
    scanf("%s", b.name);
    printf("Enter the price of the book : ");
    scanf("%d", &b.price);

    return b;
}