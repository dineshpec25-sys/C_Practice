#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

void display(struct node *temp)
{
	while(temp != NULL)
	{
		printf("%d\n", temp->data);
		temp=temp->next;
	}
}

void swap(struct node *a, struct node *b)
{
	int temp = a->data;
	a->data = b->data;
	b->data = temp;
}

int main()
{
	struct node *head, *second;
	head = malloc(sizeof(struct node));
	second = malloc(sizeof(struct node));
	
	head->data = 10;
	head->next = second;

	second->data = 11;
	second->next = NULL;

	display(head);

	struct node *new_node;
	new_node = malloc(sizeof(struct node));
	new_node->data = 9;

	swap(new_node, head);

	new_node->next = head->next;
	head->next = new_node;

	display(head);
	
	free(head);
	free(second);
	free(new_node);

	return 0;
}
