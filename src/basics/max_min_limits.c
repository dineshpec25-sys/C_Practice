#include <stdio.h>
#include <limits.h>

void int_range()
{
	int x = INT_MIN;
	int y = INT_MAX;
	printf("The smalles value of int : %d\n", x);
	printf("The greates value of int : %d\n", y);
	unsigned int z = 0;
	unsigned int w = UINT_MAX;
	printf("The smallest value of unsigned int : %u\n", z);
	printf("The greatest value of unsigned int : %u\n", w);
}
void long_range()
{	
	long int x = LONG_MIN;
	long int y = LONG_MAX;
	printf("The smalles value of long int : %ld\n", x);
	printf("The greates value of long int : %ld\n", y);
	unsigned long int z = 0;
	unsigned long int w = ULONG_MAX;
	printf("The smallest value of unsigned long int : %lu\n", z);
	printf("The greatest value of unsigned long int : %lu\n", w);
}

void short_range()
{
        short int x = SHRT_MIN;
	short int y = SHRT_MAX;
	printf("The smalles value of short int : %hd\n", x);
	printf("The greates value of short int : %hd\n", y);
	unsigned short int z = 0;
	unsigned short int w = USHRT_MAX;
	printf("The smallest value of unsigned short int : %hu\n", z);
	printf("The greatest value of unsigned short int : %hu\n", w);
}

int main()
{
	int_range();
	long_range();
	short_range();
}
