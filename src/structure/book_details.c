#include <stdio.h>

struct book_details
{
    char book_name[50];
    int book_price;
    int count;
};

int main()
{
    struct book_details book[5];

    for(int i = 0; i < 5; i++)
    {
        printf("Enter the name of the book:");
        scanf("%s", book[i].book_name);

        printf("Enter the price of the book:");
        scanf("%d", &book[i].book_price);

        printf("Enter the count of the book:");
        scanf("%d", &book[i].count);
    }

    int great = book[0].book_price;
    int id = 0;

    for(int i = 0; i < 5; i++)
    {
        if(book[i].book_price > great)
        {
            id = i;
            great = book[i].book_price;
        }
    }

    printf("%s costly book!!!\n", book[id].book_name);

    return 0;
}