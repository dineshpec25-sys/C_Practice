#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    struct Node *head;
    struct Node *middle;
    struct Node *tail;

    head = malloc(sizeof(struct Node));
    middle = malloc(sizeof(struct Node));
    tail = malloc(sizeof(struct Node));

    head->data = 5;
    head->next = middle;

    middle->data = 10;
    middle->next = tail;

    tail->data = 15;
    tail->next = NULL;

    struct Node *temp = head;

    while(temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }

    free(head);
    free(middle);
    free(tail);

    return 0;
}