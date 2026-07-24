#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

int main()
{
	struct node *head; //pointer to the node
	head = malloc(sizeof(struct node)); //allocate the memory to the heap
	
	head->data = 10; // used -> because head is pointer
	head->next = NULL; //there is no next node 

	struct node *second_node; //creating a second node
	second_node = malloc(sizeof(struct node)); //allocating memory for second node in heap
	
	second_node->data = 11;
	second_node->next = NULL; // now this node points to nowhere

	head->next = second_node; // assigning address of the second node to next pointer of the head
	
	struct node *temp = head;
	while(temp != NULL)
	{
		printf("%d\n", temp->data);
		temp=temp->next;
	}
	free(head);
	free(second_node);

	return 0;
}
