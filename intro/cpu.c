#include <stdio.h> // i/o and file handling
#include <stdlib.h> //functions for memory allocations, process control, coversions, etc.
#include <unistd.h> // access POSIX OS API

int
main(int argc, char* argv[]) // code start point
{
  if (argc != 2) {
    fprintf(stderr, "usage: cpu <string>\n");
    exit(1);
  }
  char *str = argv[1];
  while (1) {
    sleep(1); // Repeatedly checks the time and 					returns once it has run for a second
    printf("%s\n", str);
  }
  return 0;
}

