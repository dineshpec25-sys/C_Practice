#include<stdio.h>
#include<stdlib.h>

int random_number()
{
	while(1)
	{
		int x=rand();
		if(x>0 && x<101)
			return x;
	}
}
void guess(int target, int *count)
{
	int status=0;
	while(status==0)
	{
		(*count)++;
		int user_num=0;
		printf("Enter guess: ");
		scanf("%d", &user_num);
		if(user_num > target) printf("Too high; try again.\n");
		else if(user_num < target) printf("Too low: try again.\n");
		else if(user_num == target) return;
	}
}
int main()
{
	printf("Guess the secret number between 1 and 100.\n");
	char choice = 'Y';
	while(choice == 'Y')
	{
		int secret_number = random_number();
		int try=0;
		guess(secret_number, &try);
		printf("You won in %d guesses!\n\n", try);
		printf("Play again? (Y/N)");
		scanf("%c", &choice);
	}
}

