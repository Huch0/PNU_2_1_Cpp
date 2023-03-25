// matrixMultiplication.cpp - 2���� ����� 1�������� ����, + ���� 
#include <iostream>
using namespace std;
#include <stdlib.h>
#include "time.h"
// ���� ��Ŀ� ���Ͽ�add, sub, mult, transpose �����ϴ� �ڵ�
class Matrix {
public:
	Matrix(int row, int col) {
        this->rows = row;
        this->cols = col;
        this->Term = new int[row * col];
    }
	//~Matrix() { delete[]Term; }
	int GetData();
	int Display(); // ��� ���: A[rows][cols] ���

	Matrix Add(Matrix& b);
	Matrix Transpose();
	Matrix Multiply(Matrix& b);

private:
	int rows, cols;
	//int Term[rows][cols];
	int* Term;// a[i][j] = i * cols + j
};

int Matrix::GetData() {
	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < this->cols; j++) {
			this->Term[i * cols + j] = rand() % 10;
		}
	}
	return 1;
}

int Matrix::Display() {
	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < this->cols; j++) {
			cout << this->Term[i * cols + j] << ", ";
		}
		cout.put('\n');
	}
	return 1;
}

Matrix Matrix::Add(Matrix& b) {
	if (this->rows != b.rows || this->cols != b.cols) {
		cout << "Wrong format" << endl;
		return Matrix(0, 0);
	}

	Matrix result(rows, cols);
	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < this->cols; j++) {
			result.Term[i * cols + j] = this->Term[i * cols + j] + b.Term[i * cols + j];
		}
	}

	return result;
}

Matrix Matrix::Transpose(){
	int rows = this->rows;
	int cols = this->cols;
	
	Matrix Transposed(cols, rows);

	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < rows; j++) {
			Transposed.Term[i * rows + j] = this->Term[j * cols + i];
		}
	}

	return Transposed;
}
int dotProduct(int* row, int* col, int vector_len) {
	int sum = 0;

	for (int k = 0; k < vector_len; k++) {
		sum += row[k] * col[k];
	}
	return sum;
}

Matrix Matrix::Multiply(Matrix& b) {
	if (this->cols != b.rows) {
		cout << "Wrong format" << endl;
		return Matrix(0, 0);
	}

	Matrix result(this->rows, b.cols);
	Matrix bT = b.Transpose();
	for (int i = 0; i < result.rows; i++) {
		for (int j = 0; j < result.cols; j++) {
			result.Term[i * result.cols + j] = dotProduct(this->Term + i * this->cols, bT.Term + j * bT.cols, bT.cols);
		}
	}
	return result;
}

int main()
{
	Matrix a(2, 3); Matrix a1(2, 3); Matrix a2(2, 3);
	Matrix b(3, 4);
	Matrix c(2, 4);
	srand(time(NULL));
	cout << "matrix a[2][3] : " << endl;
	a.GetData();
	a.Display();

	cout << "matrix a1[2][3] : " << endl;
	a1.GetData();
	a1.Display();

	a2 = a.Add(a1);
	cout << "a2 = a + a1" << endl;
	a2.Display();

	cout << "matrix b[3][4] : " << endl;
	b.GetData();
	b.Display();

	Matrix d(4, 3);
	d = b.Transpose();
	cout << "Transpose() of Matrix b" << endl;
	d.Display();

	cout << "Multiply of Matrix a,b" << endl;
	c = a.Multiply(b);
	c.Display();

	system("pause");
	return 0;
}

