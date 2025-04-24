#include <unistd.h>
#include <stdio.h>
/**
 *
 *
 *
 *
 */
int main(int ac, char **av)
{
	int count = 0;

	while (count < ac)
	{
		printf("%s\n", av[count]);
		count = count + 1;
	}
	return (0);
}
