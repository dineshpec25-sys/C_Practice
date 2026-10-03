#include<stdio.h>
#include<stdlib.h>

typedef struct str
{
	int length;
	char *sub_string;
	struct str *next;
}str;

void praser(char string[], int num)
{
	str *head;
	head = (str*)malloc(sizeof(str));
	int status = 0;
	int 	

	for(int i = 0; string[i] != '\0'; i++)
	{
		if(string[i-1] == ' ')
		{
			if(status == 1)
			{
				temp.length = length;
				length = 0;


			length++;

			


int main()
{
	int no_of_strings;
	printf("Entre the number of the strings : ");
	scanf("%d", &no_of_strings);
	getchar();

	char whole_string[100];
	fgets(whole_string, sizeof(whole_string), stdin);

//	printf("%s", whole_string);
	
	praser(whole_string);

	return 0;

}
