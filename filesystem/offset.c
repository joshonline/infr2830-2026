#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int
main (int argc, char *argv[])
{
    int fd = open("./offset.c", O_RDONLY);
    char buf[20];
    int n;
    while ((n = read(fd, buf, 20)) > 0) {
        if (n < 20) {
            char buf2[20];
            strncpy(buf2, buf, n);
            printf("%s", buf2);
        }
        else {
            printf("%s", buf);
        }
        //printf("%s", buf);
    }
    close(fd);
    return 0;
}
