#include <stdio.h>
#include <stdlib.h>

typedef struct node
{	
	int data;
	node *next;
}

void display(node *temp)
{
	while(temp != NULL)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	}
}

void fre(node *temp)
{
		
}

int main()
