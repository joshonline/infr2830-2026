# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int main (int argc, char* argv[]){
	int x = 100;
	
	int pid = fork();
	
	if (pid == 0){
		printf("child (pid = %d) - x: %d\n", getpid(), x);
	} else{
		printf("parent (pid = %d) - x: %d\n", getpid(), x);
	}
	return 0;
}