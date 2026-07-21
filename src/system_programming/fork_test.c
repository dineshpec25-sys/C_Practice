#include<stdio.h>
#include<unistd.h>

int main()
{
	printf("Before fork()\n");
	fork();
	printf("After fork()\n");
	return 0;
}
