#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sig_handler(int signo)
{
	if (signo == SIGHUP)
	{
		signal(SIGHUP, sig_handler);
		printf("Signal HUP was caught.\n");
	}
	else if (signo == SIGINT)
	{
		signal(SIGINT, sig_handler);
		printf("Signal INT was caught.\n");
	}
	else if (signo == SIGKILL)
	{
		signal(SIGKILL, sig_handler);
		printf("Signal KILL was caught.\n");
	}
	else if (signo == SIGBUS)
	{
		signal(SIGBUS, sig_handler);
		printf("Signal BUS was caught.\n");
	}
	else if (signo == SIGSEGV)
	{
		signal(SIGSEGV, sig_handler);
		printf("Signal SEGV was caught.\n");
	}
	else if (signo == SIGTERM)
	{
		signal(SIGTERM, sig_handler);
		printf("Signal TERM was caught.\n");
	}
	else if (signo == SIGSTOP)
	{
		signal(SIGSTOP, sig_handler);
		printf("Signal STOP was caught.\n");
	}
}

void main()
{
	int pid = fork();

	if (pid < 0)
	{
		perror("fork");
		exit(1);
	}
	/* child */
	else if (pid == 0)
	{
		signal(SIGHUP, sig_handler);
		signal(SIGINT, sig_handler);
		signal(SIGSEGV, sig_handler);
		signal(SIGBUS, sig_handler);
		signal(SIGQUIT, sig_handler);
		while(1){}
	}
	/* parent */
	else
	{
		/* ensure the creation of the child process*/
		sleep(1);
		
		printf("Parent: Sending SIGHUP.\n");
		kill(pid, SIGHUP);
		
		sleep(3);
		printf("Parent: Sending SIGINT.\n");
		kill(pid, SIGINT);
		
		sleep(3);
		printf("Parent: Sending SIGSEGV.\n");
		kill(pid, SIGSEGV);

		sleep(3);
		printf("Parent: Sending SIGBUS.\n");
		kill(pid, SIGBUS);

		sleep(3);
		printf("Parent: Sending SIGQUIT.\n");
		kill(pid, SIGQUIT);
		sleep(3);
	}
}
