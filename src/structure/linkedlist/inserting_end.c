#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node ;

int main()
{
    Node *head;
    Node *second;
    Node *third;
    Node *newNode;

    head=malloc(sizeof(Node));
    second=malloc(sizeof(Node));
    third=malloc(sizeof(Node));
    newNode=malloc(sizeof(Node));

    head->data = 5;
    head->next = second;

    second->data = 10;
    second->next = third;

    third->data = 15;
    third->next = NULL;

    Node *temp;
    temp = head;
    while(temp != NULL)
    {
        printf("%d\n", temp->data);
        temp=temp->next;
    }

    third->next = newNode;
    newNode->data = 20;
    newNode->next = NULL;

    temp = head;
    while(temp != NULL)
    {
        printf("%d\n", temp->data);
        temp=temp->next;
    }

    free(newNode);
    free(third);
    free(second);
    free(head);

    return 0;
}