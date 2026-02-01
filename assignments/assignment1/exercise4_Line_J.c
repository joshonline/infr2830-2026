# include <sys/types.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h> // Include definition of wait form header sys/wait.h

int main(){
    pid_t pid;
    pid = fork();
    if(pid < 0){
        fprintf(stderr, "fork() failed");
        return 1;
    }
    else if (pid == 0){
        execlp("/bin/ls", "ls", NULL);
        printf("LINE J");
    }
    else{
        wait(NULL);
        printf("child completed");
    }
}