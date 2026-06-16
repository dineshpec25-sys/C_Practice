#include<stdio.h>
void get_input_string(char str[100])
{
	fgets(str, 100, stdin);
}
int count_vowel(char str[100])
{
	int vowel=0;
	for(int i=0;str[i] != '\0';i++)
	{
		if(str[i] == 'a' ||
		   str[i] == 'A' ||
		   str[i] == 'e' ||
		   str[i] == 'E' ||
		   str[i] == 'i' ||
		   str[i] == 'I' ||
		   str[i] == 'o' ||
		   str[i] == 'O' ||
		   str[i] == 'u' ||
		   str[i] == 'U' )
		{ 
			vowel++;
		}
	}
	return vowel;
}
int count_word(char str[100])
{
	int word=1;
	for(int i=1;str[i]!='\0';i++)
	{
		if(str[i-1] == ' ' &&
		   str[i] != '\n')
			word++;
	}
	return word;
}
int count(char s[100])
{
	int count=0;
	for(int i=0;s[i] != '\0';i++)
	{
		count++;
	}
	return count;
}
void reverse(char s[100])
{
	int left=0;
	int right=count(s)-2;
	while(left<right)
	{
		char temp;
		temp=s[left];
		s[left]=s[right];
		s[right]=temp;

		left++;
		right--;
	}
}
void display_output(int v, int w, char s[100])
{
	printf("Vowel : %d\n", v);
	printf("Word : %d\n", w);
	printf("Reverse: %s\n", s);
}
int main()
{
	char string[100];
	get_input_string(string);
	int vowel;
	vowel=count_vowel(string);
	int word;
	word=count_word(string);
	reverse(string);
	display_output(vowel,word,string);

}
