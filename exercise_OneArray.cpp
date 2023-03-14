/*2차원 배열에 대한 행렬 더하기
C++ 2차 과제로 2차원 배열을 1차원 배열로 데이터 입력, add, multiply
1. getMatrix(row, col)에서 행렬 row x col 메모리를 할당, 난수 값 입력
2. add(a, b)는 a = a + b로 계산
3. multiply(a, b, c)는 c = a x b로 구현
*/
#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#define MaxCounts 30
#define AROWS 3
#define ACOLS 4
#define BROWS 4
#define BCOLS 5
#define CROWS 3
#define CCOLS 5
#define DROWS 3
#define DCOLS 5
//int getMatrix(int[], int);//난수 생성하여 처리 - pointer만 사용하여 구현
bool showMatrix(int[], int, int);
int * addMatrix(int a[], int, int, int b[], int, int);//a = a + b를 계산하고 a를 return
int * getMatrix(int, int );
int * multiplyMatrix(int a[], int, int, int b[], int, int,int c[], int, int);//c = a * b를 계산하고 c를 return
bool freeMatrix(int[], int, int);
int main()
{
    srand(time(NULL));
  
    int* a, * a1, * a2, * a3, * b, * c, * d;

    a = getMatrix(AROWS, ACOLS); a1 = getMatrix(AROWS, ACOLS); 
    a2 = getMatrix(AROWS, ACOLS);

    printf("\nthis is a matrix :");
    showMatrix(a, AROWS, ACOLS); showMatrix(a1, AROWS, ACOLS); 
    showMatrix(a2, AROWS, ACOLS); //showMatrix(a3, AROWS, ACOLS);
    
    a3 = addMatrix(addMatrix(a, AROWS, ACOLS, a1, AROWS, ACOLS),AROWS, ACOLS, a2, AROWS, ACOLS);
    showMatrix(a3, AROWS, ACOLS);
    b = getMatrix(BROWS, BCOLS);
    printf("\nthis is b matrix :");
    showMatrix(b, BROWS, BCOLS);
    c = getMatrix(CROWS, CCOLS);
    showMatrix(c, CROWS, CCOLS);

    d = multiplyMatrix(a, AROWS, ACOLS, b, BROWS, BCOLS, c, CROWS, CCOLS);
    showMatrix(c, CROWS, CCOLS);
    showMatrix(d, DROWS, DCOLS);

    freeMatrix(a, AROWS, ACOLS); freeMatrix(a1, AROWS, ACOLS); freeMatrix(a2, AROWS, ACOLS);
    freeMatrix(b, BROWS, BCOLS); freeMatrix(c, CROWS, CCOLS);

    system("pause");
    return 1;
}

int * getMatrix(int rows, int cols)
{
    int *arr = (int *) calloc(rows * cols, sizeof(int));
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i * cols + j] = rand() % 10;//계산식 수정 필요 
        }
    }
    return arr;
}

bool showMatrix(int* arr, int rows, int cols)
{
    if (!arr) {
        return 0;
    }
    printf("\nshowMatrix : \n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            //printf("\ni: %d, j: %d, i * rows + j: %d", i, j, i * rows + j);
            printf("%d, ", arr[i * cols + j]);
        }
    }

    return 1;
}

int* addMatrix(int* a_matrix, int a_rows, int a_cols, int *b_matrix, int b_rows, int b_cols) //a = a + b를 계산하고 a를 return
{   
    if (a_rows != b_rows || a_cols != b_cols) {
        printf("행과 열이 다른 행렬끼리 더할 수 없음");
        return 0;
    }
    int* result = (int*)calloc(a_rows * a_cols, sizeof(int));
    for (int i = 0; i < a_rows; i++) {
        for (int j = 0; j < a_cols; j++) {
            result[i * a_cols + j] = a_matrix[i * a_cols + j] + b_matrix[i * b_cols + j];
        }
    }
    
    return result;
}

int dotProduct(int* row_vector, int* column_vector, int vector_length, int b_cols);

int* multiplyMatrix(int* a_matrix, int a_rows, int a_cols, int* b_matrix, int b_rows, int b_cols, int* c_matrix, int c_rows, int c_cols) //c = a * b를 계산하고 c를 return
{
    for (int i = 0; i < c_rows; i++) {
        for (int j = 0; j < c_cols; j++) {
            //printf("\ni: %d, j: %d, a_matrix + i * a_cols : %d,  b_matrix + j %d",i, j, *(a_matrix + i * a_cols), *(b_matrix + j));
            c_matrix[i * c_cols + j] = dotProduct(a_matrix + i * a_cols, b_matrix + j, a_cols, b_cols);
        }
    }

    return c_matrix;
}

int dotProduct(int* row_vector, int* column_vector, int vector_length, int b_cols) {
    int sum = 0;
    //printf("\ndotProduct : ");
    for (int k = 0; k < vector_length; k++) {
        //printf("\nrow_vector[k] : %d, column_vector[b_cols * k] : %d", row_vector[k], column_vector[b_cols * k]);
        sum += row_vector[k] * column_vector[b_cols * k];
    }

    return sum;
}

bool freeMatrix(int* arr, int rows, int cols) 
{
    printf("\nfreeMatrix : %p", arr);
    //printf("arr[rows * cols - 1] : %d", arr[rows * cols - 1]);

    free(arr);
    //printf("arr[rows * cols - 1] : %d", arr[rows * cols - 1]);

    return 1;
}