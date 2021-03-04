#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid1 = fork();
    if (pid1 == -1) // fork failed
    {
        fprintf(stderr, "Fork Failed");
        return 1;
    }
    else if (pid1 == 0) // child process
    {
        printf("I am first child, my pid is: %d\n", getpid());
    }
    else // parent process
    {
        pid_t pid2 = fork();
        if (pid2 == 0)
        {
            printf("I am second child, my pid is %d\n", getpid());
        }
        else if (pid2 == -1)
        {
            fprintf(stderr, "Fork Failed");
            return 1;
        }
    }

    wait(NULL);
    wait(NULL);

    return 0;
}