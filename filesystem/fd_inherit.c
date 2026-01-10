#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int
main (int argc, char *argv[])
{
    int fd = open("/tmp/file", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
    write(fd, "hello world\n", 13);
    close(fd);
    fd = open("/tmp/file", O_RDONLY);
    
    int rc = fork();
    if (rc == 0) { // child
        char buf[10];
        read(fd, buf, 6);
        printf("[child]: %s\n", buf);
    }
    else if (rc > 0) { // parent
        waitpid(rc, NULL, 0);
        char buf2[10];
        read(fd, buf2, 6);        
        printf("[parent]: %s", buf2);  
    }
    else {            // error
        return -1;
    }
    return 0;
}

