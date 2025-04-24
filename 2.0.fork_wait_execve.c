#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
/**
 *
 *
 *
 *
 */
int main(void)
{
	int count;
	int max;
	int child_pid;
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};
	int status;
	int my_pid;
	int my_ppid;

	count = 0;
	max = 5;

	while (count < max)
	{
		my_pid = getpid();
		printf("is this the parent: %d\n", my_pid);
		child_pid = fork();
		if (child_pid == 0)
		{
			my_pid = getpid();
			my_ppid = getppid();

			printf("Parent pid:%d\n", my_ppid);
			printf("Child pid:%d\n", my_pid);
			printf("%d\n", count);
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("ERROR: exceve error");
			}
		}
		else 
		{
			wait(&status);
		}
		count = count + 1;
	}
	return (0);
}

