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
	while (temp != NULL)
	{
    		struct node *next = temp->next;  // save next BEFORE freeing temp
    		free(temp);
    		temp = next;
	}

}

int main()
{
	node *head, *tail, *second;

	head = malloc(sizeof(node));
	tail = malloc(sizeof(node));
	second = malloc(sizeof(node));


	head->data = 9;
	second->data = 10;
	tail->data = 12;

	head->next = second;
	second->next = tail;
	tail->next = NULL;

	node *temp;
	int pos;

	printf("Enter the data : ");
	scanf("%d", temp->data);
	printf("Enter the position : ");
	scanf("%d", &pos);

	int tep=0;
	node *tmp=head;
	node *tmp2;
	while(tep != pos)
	{
		tep++;
		tmp2->next=temp->next;
		temp->next=tmp->next;
		tmp=tmp->next
	}

	tmp2


}