#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
	int re = fork();
	printf("PID: %d, Return value of fork(): %d\n", getpid(), re);
	if (re == 0)
	{
		while(1){}
	}
	else
	{
		wait(NULL);
		printf("Child process is dead!\n");
	}	
	return 0;
}

