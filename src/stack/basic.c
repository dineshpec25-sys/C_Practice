#include<stdio.h>
#define MAX 10

char stack[MAX];
int top=-1;

void PUSH(int data)
{
	if(top == MAX - 1) 
	{
		printf("Stack Overflow\n");
		return ;
	}
	stack[++top]=data;
}

void dis()
{
	int temp = top;
	for(int i = 0;i <= temp; i++)
	{
		printf("The value : %d\n", stack[i]);
	}
}

int main()
{
	int input_count=0;
	printf("Enter the number of input :");
	scanf("%d", &input_count);

	for(int i =  input_count; i > 0; i--)
	{
		int data;
		printf("Enter the number to add to the stack: ");
		scanf("%d", &data);

		PUSH(data);
	}
	dis();
}
