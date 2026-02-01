#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int x = 100;

    int pid = fork();

    if (pid == 0)
    {
        printf("child (pid = %d) - x: %d\n", getpid(), x);
        x = 2000;
        printf("child change x: %d\n", x);
    }
    else
    {
        printf("parent (pid = %d) - x: %d\n", getpid(), x);
        x = 1000;
        printf("parent change x: %d\n", x);
    }
    return 0;
}