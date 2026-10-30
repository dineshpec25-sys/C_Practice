#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x)
{
    if(top == MAX-1)
    {
        puts("stack overflow");
        return;
    }
    
    top++;
    stack[top] = x;
}

int pop()
{
    if(top == -1)
    {
        puts("stack underflow");
        return -1;
    }

    int temp = stack[top];
    top--;
    return temp;
}

int isOperator(char x)
{
    if(x == '+' || x == '-' || x == '*' || x == '/')
    {
        return 1;
    }
    return 0;
}

int eval(char *exp)
{
    for(int i = 0; exp[i] != '\0'; i++)
    {
        if(exp[i] >= '0' && exp[i] <= '9')
        {
            push(exp[i] - '0');
        }
        else if(isOperator(exp[i]))
        {
            int a = pop();
            int b = pop();

            switch(exp[i])
            {
                case '+': push(a+b); break;
                case '-': push(a-b); break;
                case '*': push(a*b); break;
                case '/': 
                     if(b == 0)
                     {
                         puts("Division by zero");
                         return -1;
                     }
                     push(a/b);
                     break;
            }
        }
    }
    if(top != 0)
    {
        puts("Invalid expression");
        return -1;
    }
    return pop();
}

int main()
{
    char exp[100];

    printf("Enter the postfix expression: ");
    fgets(exp, sizeof(exp), stdin);

    int result = eval(exp);
    printf("Result = %d\n", result);

    return 0;
}
