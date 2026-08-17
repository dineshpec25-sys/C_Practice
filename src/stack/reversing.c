#include <stdio.h>
#define MAX 100
int top = -1;
char stack[MAX];

void PUSH(int data)
{
	stack[++top]=data;
}

void POP(char *str)
{
	stack[top--]=stack
void reverse(char *str)
{
	for(int i = 0; str[i] != '\0'; i++)
	{	
		PUSH(str[i]);

int main()
{
	char str[MAX];
	fgets(str, MAX, stdin);

	str[strcspn(str, "\n")] = '\0'; // To remove the '\n' at the end of the string
	
	reverse(str);
	display(str);

	return 0;
}

