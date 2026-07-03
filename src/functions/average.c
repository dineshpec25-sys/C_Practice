#include<stdio.h>

double 
average(double a, double b)
{
	return (a+b)/2;
}

int main()
{
	double x=10;
	double y=10;
	printf("The average :%lf", average(x,y));
}
