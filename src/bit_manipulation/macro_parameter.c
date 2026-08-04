#include<stdio.h>
#include<stdint.h>

#define SQUARE(x) x * x

int main()
{
	int temp;
	printf("Enter the number to find the square :");
	scanf("%d", &temp);

	printf("%d\n", SQUARE(temp));
	return 0;
}
