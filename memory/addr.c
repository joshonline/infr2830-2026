#include <stdio.h>
#include <stdlib.h>

int InitializedGlobal[1024] = {0,};
int UnintGlobal[1024];
int main() {
    int localVar1;
    int localVar2;
    int *dynamicLocalVar1;
    int *dynamicLocalVar2;
    dynamicLocalVar1 = malloc(sizeof(int));
    dynamicLocalVar2 = malloc(sizeof(int));
    printf("code                 : %p\n", &main);
    printf("Data                 : %p\n", &InitializedGlobal);
    printf("BSS(Uninit Data)     : %p\n", &UnintGlobal);
    printf("stack localVar1      : %p\n", &localVar1);
    printf("stack localVar2      : %p\n", &localVar2);
    printf("heap dynamicLocalVar1: %p\n", dynamicLocalVar1);
    printf("heap dynamicLocalVar2: %p\n", dynamicLocalVar2);

    /* size of */
    int *x = malloc(10*sizeof(int));
    printf("%ld\n", sizeof(x));

    int y[10];
    printf("%ld\n", sizeof(y));

    return 0;
}

