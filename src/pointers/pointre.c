#include<stdio.h>

void getnumbers(int *num1, int *num2)
{
	printf("Enter the number :");
	scanf("%d", &(*num1));
	printf("Enter the number :");
	scanf("%d", &(*num2));
}

void addnumbers(int *num1, int *num2, int *result)
{
	*result=(*num1)+(*num2);
}

void print(int *res)
{
	printf("The result : %d", *res);
}

int main()
{
	int number1,number2,result;
	int *xn1 = &number1;
	int *xn2 = &number2;
	int *xr = &result;

	getnumbers(xn1,xn2);
	addnumbers(xn1,xn2,xr);
	print(xr);

}
