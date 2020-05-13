#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
	int re = fork();
	if (re == 0)
	{
		printf("Child process PID: %d.\n", getpid());
		int ppid = getppid();
		while(1)
		{
			if (ppid != getppid())
			{
				printf("Child process: My parent process (PID: %d) is dead, and my new parent PID: %d.\n", ppid, getppid());
				break;
			}
		}
	}
	else
	{

		printf("Parent process PID: %d.\n", getpid());
		while(1){}
	}	
	return 0;
}

