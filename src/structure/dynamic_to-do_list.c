#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Task
{
	int id;
	char title[50];
} task;

task *add_task(task t[], int *num)
{
	(*num)++;
	t=realloc(t,(*num)*sizeof(task));
	printf("Task no. %d", *num);
	printf("Title :");
	t[*num-1].id=*num;
	scanf("%s", t[*num-1].title);
	return t;
}

void display_task(task t[], int num)
{
	for(int i = 0;i < num; i++)
	{
		printf("%d. %s", t[i].id, t[i].title);
	}
}

task *delete_task(task t[], int *num)
{
	int id=0;
	printf("Enter the id:");
	scanf("%d", &id);
	for(int i = 0;i<*num;i++)
	{
		if(t[i].id == id)
		{
			for(int j=i+1;j<*num;j++)
			{
				t[j-1]=t[j];
			}
			(*num)--;
			t=realloc(t, (*num)*sizeof(task));
			return t;
		}
	}
}
int main()
{
	task *t=NULL;
	int number_of_task=0;
	while(1)
	{
		int choice;
		printf("1. Add Task\n2. Display Task\n3.Delete Task\n0. Exit");
		scanf("%d", &choice);
		switch(choice)
		{
			case 0: {	free(t);
					return 0;
				}
			case 1: {t=add_task(t, &number_of_task);
				break;}
			case 2: {display_task(t, number_of_task);
				break;}
			case 3: {t=delete_task(t, &number_of_task);
				break;}
		}
	}
}
