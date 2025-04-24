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
int main(int ac, char **av)
{
	int count;
	int max;
	int child_pid;
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};
	int status;
	int my_pid;
	int my_ppid;
	char *buffer;
	size_t buffer_size;
	size_t line;

	count = 0;
	max = 5;

	while (count < max)
	{
		my_pid = getpid();
		printf("is this the parent: %d\n", my_pid);

		printf("$ ");

		child_pid = fork();
		if (child_pid == 0)
		{
			line = getline(&buffer, &buffer_size, stdin);
			printf("line is: %zu", line);
			/*split*/

			/*save these into argv*/

			my_pid = getpid();
			my_ppid = getppid();

			printf("Parent pid:%d\n", my_ppid);
			printf("Child pid:%d\n", my_pid);
			printf("%d\n", count);

			if (execve(buffer, argv, NULL) == -1)
			{
				perror("ERROR: exceve error");
			}
/*			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("ERROR: exceve error");
			}
*/
			printf("%zu line read\n", line);
		}
		else 
		{
			wait(&status);
		}
		count = count + 1;
	}
	return (0);
}

