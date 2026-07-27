#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

void display(struct node *x)
{
	while(x != NULL)
	{
		printf("%d\n", x->data);
		x = x->next;
	}
}
void fre(struct node *temp)
{
	while (temp != NULL) 
	{
    		struct node *next = temp->next;  // save next BEFORE freeing temp
    		free(temp);
    		temp = next;
	}
}

int main()
{
	struct node *head, *second, *tail;

	// allocating memory to the pointers to create a node
	head = malloc(sizeof(struct node));
	second = malloc(sizeof(struct node));
	tail = malloc(sizeof(struct node));

	// assigning a value to data
	head->data = 9;
	second->data = 10;
	tail->data = 11;

	//linking the pointers
	head->next = second;
	second->next = tail;
	tail->next = NULL;

	display(head);

	// creating new node
	struct node *new_node;
	new_node = malloc(sizeof(struct node));
	new_node->data = 12;
	new_node->next = NULL;

	// chaning the next of tail
	tail->next = new_node;

	// changing the tail
	tail = new_node;

	display(head);

	fre(head);	

	return 0;
}
