#pragma once

#include <iostream>

using namespace std;

#include <stdlib.h>

// implement the functions : add, sub, mult, transpose

class Matrix {

public:

	Matrix(int row, int col);

	int GetData();

	Matrix Transpose();

	int Display();

	Matrix & operator + (const Matrix &);//add matrix to matrix
	Matrix & operator * (const Matrix &);//multiply matrix y matrix
	friend istream& operator >> (istream& s, Matrix &);
	friend ostream& operator << (ostream& s, Matrix &);
	int CompareRowCol(Matrix b);

private:
	int rows, cols;
	//Do not use "int Term[rows][cols];"

	int *Term;
};