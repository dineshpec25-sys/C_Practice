#include<stdio.h>
#include<stdint.h>

#define LIMIT 999
#define IS_IN_RANGE(x) (x >= 0 && x <= LIMIT)

int main()
{
	int n = 0;

	printf("Enter the number :");
	scanf("%d", &n);

	if(IS_IN_RANGE(n))
		printf("Within Range!!!");
	else
		printf("Not Within Range!!!");
	return 0;
}
