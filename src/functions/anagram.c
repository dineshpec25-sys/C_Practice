#include<stdio.h>
#include<stdbool.h>
#include<string.h>

void sort(char* arr)
{
	for(int i = 0; arr[i] != '\0'; i++)
	{
		for(int j = i+1; arr[j] != '\0'; j++)
		{
			if(arr[i] > arr[j])
			{
				char temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

bool anagram(char *arr1, char *arr2)
{
	for(int i = 0; arr1[i] != '\0' ; i++)
	{
		int temp1 = arr1[i];
		int temp2 = arr2[i];
		if(temp1 != temp2)
			return false;
	}
	return true;
}

int main()	
{
	char str[10];
	char atr1[10];

	scanf("%s", str);
	scanf("%s", atr1);

	sort(str);
	sort(atr1);

	if(anagram(str, atr1)){
		printf("ANAGRAM\n");
		return 0;
	}

	printf("NOT ANAGRAM");
}


