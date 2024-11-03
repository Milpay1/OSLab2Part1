#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>  // Include for fork() and pid_t

void ChildProcess(void);  /* child process prototype */
void ParentProcess(void); /* parent process prototype */

int main(void)
{
    pid_t pid;  // Declare pid of type pid_t
    pid = fork();  // Initialize pid with the result of fork()

    if (pid == 0) {
        ChildProcess();
    } else if (pid > 0) {
        ParentProcess();
    } else {
        printf("Fork failed.\n");
        return 1;
    }

    return 0;
}

void ChildProcess(void)
{
    printf("This is the child process.\n");
}

void ParentProcess(void)
{
    printf("This is the parent process.\n");
}
