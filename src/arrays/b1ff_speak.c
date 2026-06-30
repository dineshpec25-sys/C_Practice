#include <stdio.h>

void get_string(char string[])
{
	printf("Enter the input : ");
	fgets(string, 100, stdin);
}
void replacer(char string[])
{
	for(int i=0; string[i]!='\0'; i++)
	{
		if(string[i] == 'a')
			string[i] = '4';
		else if(string[i]== 'b')
			string[i] = '8';
		else if(string[i]== 'e')
			string[i] = '3';
		else if(string[i]== 'i')
			string[i] = '1';
		else if(string[i]== 'o')
			string[i] = '0';
		else if(string[i]== 's')
			string[i] = '5';
	}
}

void uppercase(char string[])
{
	for(int i=0; string[i]!='\0';i++)
	{
		if(string[i] > 96 && string[i] < 123)
			string[i] = string[i] - 32;
	}
}

void print(char string[])
{
	printf("%s\n", string);
}
int main(){
	char string[100];
	char *str=string;
	get_string(str);
	replacer(str);
	uppercase(str);
	print(str);
}
