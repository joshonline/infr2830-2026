//import headers
#include <stdio.h>
#include <stdlib.h>

// main(int n, int a, int r)
int main(int argc, char *argv[]){
    // error check: args passed must be int
    if (argc !=4){ //check argument count, argc
        fprintf(stderr, "Usage: %s n a r\n", argv[0]);
        return 1; //end with error
    } 
    // array: empty array, holds sequence
    // k=0 //count sequence 
    // 
    // for k=0, while k<n, k++
        // print a*(r**k)
        // 
    // 
    // retturn 0
    return 0;
}