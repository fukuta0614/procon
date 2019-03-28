
#include <stdio.h>
#include <stdlib.h>
#include    <string.h>

//void func(int **A) {
//    for (int i = 0; i < 3; i++) {
//        for (int j = 0; j < 3; j++) {
//            printf("%d ", A[i][j]);
//        }
//    }
//    printf("\n");
//
//}

int main(void) {
    printf("test\n");

    int **pA;
    int *A[3];

//    int a;
//
    printf("%p\n", &A);
    for (int i = 0; i < 3; i++) {
//        A[i] = (int *) malloc(sizeof(int) * 3);
        printf("%p %p\n", A[i], &A[i]);
    }
//
//
//    printf("%p \n", &a);

    memset(A[0], 0, sizeof(int) * 3);

//    printf("%d \n", A[0][0]);

    pA = A;

    printf("%d", pA[0][0]);

//    for (int i = 0; i < 3; i++) {
//        for (int j = 0; j < 3; j++) {
//            printf("%d\n", pA[i][j]);
//        }
//    }

//    func(A);

    return 0;
}