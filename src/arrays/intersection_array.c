#include<stdio.h>
#include<stdlib.h>
int compare(const void *a, const void *b)
{
	int x=*(int*)a;
	int y=*(int*)b;
	return x-y;
}
void display_array(int arr[])
{
	for(int i =0; i < 4; i++)
	{
		printf("%d", arr[i]);
	}
}

int main()
{
	int arr1[4];
	int arr2[2];
	qsort(arr1, 4, sizeof(int), compare);
	display_array(arr1);
	return 0;
}
