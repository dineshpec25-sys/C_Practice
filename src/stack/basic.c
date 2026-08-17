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
	int data=10;

	PUSH(data);

	data=11;
	PUSH(data);
	dis();
}
