#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>

int main()
{
	char *argv[3] = {"Command-line", "-la", NULL};

	int pid = fork();

	if (pid == 0)
	{
		printf("executing child routine.\n");
		execvp("ls", argv);
	}
	else
	{
		sleep(2);
		printf("executing parent routine.\n");
	}
	return 0;
}
