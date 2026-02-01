//import headers
#include <stdio.h>
#include <stdlib.h>

// main(int n, int a, int r)
int main(int argc, char *argv[]){
    // error check: args passed must be int
    if (argc !=4){ //check argument count, argc
        fprintf(stderr, "Usage: %s n a r\n", argv[0]);
        return 1; //end with error
    };

    // string to int conversion
    int n = atoi(argv[1]);
    int a = atoi(argv[2]);
    int r = atoi(argv[3]);

    if (n < 0 || a < 0 || r < 0){
        fprintf(stderr, "All arguments must be integers\n");
        return 1;
    }
    else{
        printf("Argumets: n=%d, a=%d, r=%d", n, a, r);
    }

    // for k=0, while k<n, k++
        // print a*(r**k)
        //
    //
    // retturn 0
    return 0;
}
