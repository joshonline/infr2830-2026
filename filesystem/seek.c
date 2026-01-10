#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int
main (int argc, char *argv[])
{
    int fd = open("./offset.c", O_RDONLY);
    int fd2 = open("./offset.c", O_RDONLY);
    char buf[20];

    read(fd, buf, 20);
    printf("[fd=%d]: %s\n", fd, buf);
    read(fd, buf, 20);
    printf("[fd=%d]: %s\n", fd, buf);

    read(fd2, buf, 20);
    printf("[fd=%d]: %s\n", fd2, buf);

    lseek(fd, 200, SEEK_SET);
    read(fd, buf, 20);
    printf("After jumping ahead ...\n");
    printf("[fd=%d]: %s\n", fd, buf);

    close(fd);
    close(fd2);
    return 0;
}
