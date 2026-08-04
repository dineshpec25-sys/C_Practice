#include<stdio.h>
#include<stdint.h>

#define LIMIT 9999

int main()
{	
	int x;
	printf("Enter the number :");
	scanf("%d", &x);

	if(x > LIMIT)
	{
		printf("Invalid input");
	}
	else
		printf("Valid input");

	return 0;
}
