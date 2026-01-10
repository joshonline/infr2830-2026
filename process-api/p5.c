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
    char *argv[2];
    argv[0] = "wc";
    argv[1] = 0;
    close(0);
    dup(p[0]);
    close(p[0]);
    close(p[1]);
    printf("I'm child, going to run \"wc\" on whatever parent will send me\n");
    execvp(argv[0], argv);
  } else {      // parent process goes down this path
    close(p[0]);
    printf("I'm parent, writing \"hello world\" to child\n");
    write(p[1], "hello world\n", 12);
    close(p[1]);
  }
  return 0;
}

