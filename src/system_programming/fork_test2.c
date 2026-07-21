#include<stdio.h>
#include<unistd.h>

int main()
{
	pid_t pid = fork();
	
	if(pid > 0)
		printf("Parent: my pid is %d, child pid id %d\n", getpid(), pid);
	else if(pid == 0)
		printf("Child: my pid is %d, parent pid is %d\n", getpid(), getppid());

	return 0;
}
