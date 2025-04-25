#include <stdio.h>
#include <unistd.h>
#include <string.h>
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
	char *tokens;

	printf("$ ");

	/*user input*/
	characters = getline(&buffer, &buffer_size, stdin);
	if (buffer == NULL) /*getline mallocs*/
	{
		return (-1);
	}
	printf("%zu characters read\n", characters);
	printf("buffer: %s\n", buffer);
	printf("buffer address: %p\n", &buffer);

	tokens = strtok(buffer, " ");
	while (tokens != NULL)
	{
		printf("%s\n", tokens);
		tokens = strtok(NULL, " ");
	}
	return (0);
}
