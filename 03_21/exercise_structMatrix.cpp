// matrixMultiplication.cpp - 2차원 행렬을 struct으로 구현 
#include <stdio.h>
#include <stdlib.h>
#include "time.h"
// 보통 행렬에 대하여add, sub, mult, transpose 구현하는 코딩
struct Matrix {
	int rows;
	int cols;
	int* Term;
};

int getData(struct Matrix* a);
int showData(struct Matrix* a);// 행렬 모양: A[rows][cols] 출력
void add(struct Matrix*, struct Matrix*, struct Matrix*);
void transpose(struct Matrix*, struct Matrix*);
bool multiply(struct Matrix*, struct Matrix*, struct Matrix*);
void free(struct Matrix*);

int getData(struct Matrix* a) {
	int rows = a->rows; int cols = a->cols;
	a->Term = (int*)calloc(rows * cols, sizeof(int)); 
	int* matrix = a->Term;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			matrix[i * cols + j] = rand() % 10;
		}
	}

	return 0;
}
int showData(struct Matrix* a) {
	int rows = a->rows; int cols = a->cols;
	int* matrix = a->Term;

	printf("showData : \n");

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("%d, ", matrix[i * cols + j]);
		}
		printf("\n");
	}
	printf("\n");

	return 1;
}
void add(struct Matrix* a, struct Matrix* b, struct Matrix* c) {
	if (a->rows != b->rows || a->cols != b->cols) {
		printf("a, b는 incompatiable matrix\n");
		return;
	}
	int* a_matrix = a->Term;
	int* b_matrix = b->Term;
	int* c_matrix = c->Term;

	for (int i = 0; i < a->rows; i++) {
		for (int j = 0; j < a->cols; j++) {
			c_matrix[i * a->cols + j] = a_matrix[i * a->cols + j] + b_matrix[i * a->cols + j];
		}
	}

	return;

}
//*
void transpose(struct Matrix* a, struct Matrix* a1) {
	int rows = a->rows;
	int cols = a->cols;
	int* a_matrix = a->Term;
	int* a1_matrix = a1->Term;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			a1_matrix[j * rows + i] = a_matrix[i * cols + j];
		}
	}

	a1->rows = cols;
	a1->cols = rows;
	
}
int dotProduct(int* row_vector, int* col_vector, int vector_length) {
	int sum = 0;
	for (int k = 0; k < vector_length; k++) {
		sum += row_vector[k] * col_vector[k];
	}

	return sum;
}
bool multiply(struct Matrix* a, struct Matrix* b, struct Matrix* c) {
	if (a->cols != b->rows) {
		printf("incompatible matrices");
		return false;
	}
	struct Matrix bXpose = { b->cols, b->rows };
	getData(&bXpose);

	printf("This is b : \n");
	showData(b);

	transpose(b, &bXpose);

	printf("This is bXpose : \n");
	showData(&bXpose);

	int* a_matrix = a->Term;
	int* bT_matrix = (&bXpose)->Term;
	int* c_matrix = c->Term;
	// a = 2x3 b = 3x4  bT = 4x3 c=2x4
	printf("bXpose rows : %d, cols : %d, Term : %p \n", (&bXpose)->rows, (&bXpose)->cols, (&bXpose)->Term);
	for (int i = 0; i < c->rows; i++) {
		for (int j = 0; j < c->cols; j++) {
			c_matrix[i * c->cols + j] = dotProduct(a_matrix + i * a->cols, bT_matrix + j * (&bXpose)->cols, a->cols);
		}
	}

	showData(c);

	free(&bXpose);
	return true;
}
void free(struct Matrix* m) {
	
}
//*/
int main()
{
	struct Matrix a = { 2,3,0 }, b = { 2,3,0 }, c = { 2,3,0 }, d = { 3,4,0 }, e = { 2,4,0 };
	srand(time(NULL));
	printf("matrix a[2][3]의 입력: \n");
	getData(&a);
	showData(&a);
	printf("matrix b[2][3]의 입력: \n");
	getData(&b);
	showData(&b);
	getData(&c);

	add(&a, &b, &c);

	printf("matrix c = a+b \n");
	showData(&c);

	printf("matrix d[3][4]의 입력: \n");
	getData(&d);
	showData(&d);
	
	getData(&e);
	multiply(&a, &d, &e);
	printf("matrix_e = a * d \n");
	showData(&e);
	free(&a); free(&b); free(&c); free(&d); free(&e);
	
	system("pause");
	return 0;
}

