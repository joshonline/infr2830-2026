//link headers
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
        printf("Argumets: n=%d, a=%d, r=%d\n", n, a, r);
    }

    int term = a;
    printf("Sequence:");
    // for k=0, while k<n, k++
    for(int k=0; k<n; k++){
        // print current term
        printf("%d, ",term);
        // multiply current term by r
        term *= r;
    }

    // retturn 0
    return 0;
}
