#include <stdio.h>
#include <unistd.h>

/**
 * main - execve example
 *
 * Return: Always 0.
 */
int main(void)
{
    char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};
    
    printf("argv %s", *argv);
    printf("Before execve\n");
    
    printf("argv is this: why does this not run???????, \n"); /*need a new line for execve*/
    /*execve(array of arguments - which is the command, argument, environment (env)*/

    if (execve(argv[0], argv, NULL) == -1) /*why is this running?*/
    {
        perror("Error:");
    }
    printf("After execve\n");
    return (0);
}
