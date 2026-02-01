#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
  int p[2];
  pipe(p);
  int rc = fork();
  if (rc < 0) {     // fork failed; exit
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {     // child (new process)
    close(p[1]);
    close(0);
    dup(p[0]);
    close(p[0]);

    char *myargs[4];
    myargs[0]= "tr";
    myargs[1]="a-z";
    myargs[2]="A-Z";
    myargs[3]=NULL;
    execvp(myargs[0], myargs);

    fprintf(stderr, "exec failed\n");
    exit(1);
  } else {      // parent process goes down this path
    close(p[0]);
    close(1);
    dup(p[1]);
    close(p[1]);

    char *myargs[3];
    myargs[0] = "cat";
    myargs[1] = "exercise10_pipe.c";
    myargs[2] = NULL;
    execvp(myargs[0], myargs);

    fprintf(stderr, "exec failed\n");
    exit(1);
  }
  return 0;
}
