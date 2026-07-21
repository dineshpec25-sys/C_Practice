#include<stdio.h>
#include<unistd.h>

int main()
{
	printf("Main: my pid is %d\n", getpid());

	pid_t pid = fork();

	if( pid == 0 )
	{
		printf("My pid Child %d\n", getpid());
		pid_t pid_c = fork();
		
		if(pid_c == 0)
		{
			printf("My parent pid : %d\n", getppid());
			printf("My pid grandchild %d\n", getpid());
		}
	}

	return 0;
}

