#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#define AROWS 3
#define ACOLS 4
#define BROWS 4
#define BCOLS 5
#define CROWS 3
#define CCOLS 5
#define DROWS 3
#define DCOLS 6
int getDataA(int (*arr)[ACOLS], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < ACOLS; j++) {
            arr[i][j] = rand() % 10;
        }
    }
    return 0;
};
int getDataB(int (*arr)[BCOLS], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < BCOLS; j++) {
            arr[i][j] = rand() % 10;
        }
    }
    return 0;
};
int showA(int (*arr)[ACOLS], int rows) {
    printf("\nshowA\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < ACOLS; j++) {
            printf("%d,", arr[i][j]);
        }
        printf("\n");
    }
    
    return 0;
};
int showB(int (*arr)[BCOLS], int rows) {
    printf("\nshowB\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < BCOLS; j++) {
            //printf("%d, i: %d, j: %d\n", arr[i][j], i, j);
            printf("%d,", arr[i][j]);
        }
        printf("\n");
    }
    
    return 0;
};
int showC(int (*arr)[CCOLS], int rows) {
    printf("\nshowC\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < CCOLS; j++) {
            printf("%d,", arr[i][j]);
        }
        printf("\n");
    }
    
    return 0;
};
void add(int destination[][ACOLS], int (*matrixA1)[ACOLS], int rowsA1, int (*matrixA2)[ACOLS], int rowsA2){
    for (int i = 0; i < AROWS; i++) {
        for (int j = 0; j < ACOLS; j++) {
            destination[i][j] = matrixA1[i][j] + matrixA2[i][j];
        }
    }

    return;
};

int multiplyRowAndColumn (int (*matrixA)[ACOLS], int rowsA, int (*matrixB)[BCOLS], int rowsB, int row, int column) {
    int sum = 0;
    //printf("row : %d, column : %d,  \n", row, column);
    for (int i = 0; i < ACOLS; i++) {
        sum += matrixA[row][i] * matrixB[i][column];
        //printf("A[row][i] : %d, B[i][column] : %d\n", matrixA[row][i], matrixB[i][column]);
    }
    return sum;
}
void multiply(int deestination[][CCOLS], int (*matrixA)[ACOLS], int rowsA, int (*matrixB)[BCOLS], int rowsB){
    if (ACOLS != rowsB) {
        printf("곱연산을 할 수 있는 행렬 형식이 아닙니다.");
        return;
    }
    for (int i = 0; i < CROWS; i++) {
        for (int j = 0; j < CCOLS; j++) {
            deestination[i][j] = multiplyRowAndColumn(matrixA, rowsA, matrixB, rowsB, i, j);
        }
    }
    return;
};

/*
*/

int main()
{
    srand(time(NULL));
    int a[AROWS][ACOLS]; 
    int a1[AROWS][ACOLS];
    int a2[AROWS][ACOLS];
    int a3[AROWS][ACOLS];
    int b[BROWS][BCOLS];
    int c[CROWS][CCOLS];
    int d[CROWS][CCOLS];
    getDataA(a, AROWS);
    getDataA(a1, AROWS);
    getDataB(b, BROWS);

    showA(a, AROWS);  
    
    showA(a1, AROWS); showA(a2, AROWS); 
    showB(b, BROWS);
    
    add(a2, a, AROWS, a1, AROWS); // a2 = a + a1
    showA(a2, AROWS);

    int tmp[AROWS][ACOLS];
    add(tmp, a, AROWS, a1, AROWS); // tmp = a + a1
    add(a3, tmp, AROWS, a2, AROWS); // a3 = tmp + a2
    showA(a3, AROWS);

    multiply(c, a, AROWS, b, BROWS); // c = a * b ( 3*5 = 3*4 * 4*5)
    showC(c, AROWS);
    
    
    //multiply(multiply(a, AROWS, b, BROWS), c, CROWS)); 3*5 * 3*5 는 행렬곱연산 불가
    //show(d, DROWS);

    system("pause");
    
    return 1;
}