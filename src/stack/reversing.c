#include <stdio.h>
#include<string.h>
#define MAX 100
int top = -1;
char stack[MAX];

void PUSH(int data)
{
	if(top == MAX-1)
	{
		printf("Stack Overflow\n");
		return ;
	}
	stack[++top]=data;
}

int POP()
{
	if(top == -1)
	{
		printf("Stack Underflow\n");
		return 0;
	}
	int temp = stack[top];
	top--;
	return temp;
}

int main()
{
	char str[MAX];
	printf("Enter the string : ");
	fgets(str, MAX, stdin);

	str[strcspn(str, "\n")] = '\0'; // To remove the '\n' at the end of the string
	int count = strlen(str);	
	for(int i = 0; str[i] != '\0'; i++)
	{
		PUSH(str[i]);
	}

	for(int i = 0; i < count; i++)
	{
		str[i] = POP();
	}
	printf("The string : %s\n", str);
	return 0;
}

