#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

static void sighandler(int signo)
{
    int fd;
    char buff[] = "This program has exited due to SIGINT\n";
    if (signo == SIGINT)
    {
        fd = open("./log.txt", O_CREAT | O_WRONLY | O_APPEND, 0777);
        //printf("%s\n", strerror(errno));
        int numwritten = write(fd, buff, sizeof(buff));
        //printf("%s\n", strerror(errno));
        exit(0);
    }
    if (signo == SIGUSR1)
        printf("The PID of the parent process is %d\n", getppid());
}

int main()
{
    signal(SIGUSR1, sighandler);
    signal(SIGINT, sighandler);

    while (1)
    {
        printf("The process' PID is %d\n", getpid());
        sleep(1);
    }

    return 0;
}