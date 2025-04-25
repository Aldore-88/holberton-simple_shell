#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
/**
 *
 *
 *
 *
 */
int main(int ac, char **av)
{
	int child_pid;
	char *buffer;
	char *argv[] = {&buffer, NULL};
	int status;
	size_t buffer_size;
	size_t line;

	buffer = NULL;
	buffer_size = 0;

	while (1)
	{
		printf("$ ");

		child_pid = fork();
		if (child_pid == 0)
		{
			line = getline(&buffer, &buffer_size, stdin);
			if (buffer == NULL)/*buffer is malloced*/
			{
				return (-1);
			}

			printf("line is: %zu", line);
			/*save these into argv*/

			if (execve(buffer, argv, NULL) == -1)
			{
				perror("ERROR: exceve error");
			}
			printf("%zu line read\n", line);
		}
		else 
		{
			wait(&status);
		}
	}
	free(buffer);
	return (0);
}

