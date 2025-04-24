#include <stdio.h>
#include <unistd.h>

/**
 * main - fork example
 * **NOTE - this seems weird because there is no wait function yet
 * the PID values may change depending on how long the child takes
 * Return: Always 0.
 */
int main(void)
{
    pid_t my_pid;
    pid_t pid;
    pid_t my_ppid;

    printf("Before fork\n");
    pid = fork();
    
    my_ppid = getppid();
    printf("my ppid is: %u\n", my_ppid);
    
    if (pid == -1)
    {
        perror("Error:");
        return (1);
    }
    printf("After fork\n");
    my_pid = getpid();
    printf("My pid is %u\n", my_pid);
    return (0);
}
