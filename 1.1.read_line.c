#include <stdio.h>
#include <unistd.h>
/**
 *
 *
 *
 *
 */
int main(int ac, char **av)
{
	char *buffer;
	size_t buffer_size;
	size_t characters;

	printf("$ ");

	/*user input*/
	characters = getline(&buffer, &buffer_size, stdin);
	if (buffer == NULL) /*getline mallocs*/
	{
		return (-1);
	}
	printf("%zu characters read\n", characters);
	printf("buffer: %s\n", buffer);

	return (0);
}
