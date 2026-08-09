#include <stdio.h>

void dis(int x, int y)
{
	printf("The value of a : %d\n", x);
	printf("The value of b : %d\n", y);
}

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int main()
{
	int a,b;
	scanf("%d", &a);
	scanf("%d", &b);

	dis(a,b);
	swap(&a,&b);
	dis(a,b);
}
