//4장-5. MULTIPLY.cpp   4.4.1 C++ 함수 선언과 정의
#include <iostream>
using namespace std;
//function overloading
#define ROWS 3
#define COLS 4
int multiply(int, int);
float multiply(float, float);
//void displayArray(int [][COLS]);
void displayArray(int (*)[COLS]);
void displayArray(int* );
//void displayArray(int**);
void displayArray(int* a[COLS]);//void displayArray(int**);//같은 signature로 간주함
int main () {
    int i = 10, j = 20;
	float a = 1.25, b = 2.55;
	//function overloading
    int k = multiply(i, j);
	float c = multiply(a, b);
	cout << " k = " << k <<endl << " c = " << c << endl;
	//int n = multiply(i, a); //multiply(int, float)는 오류

	//2D array functions: overloading
	int data[ROWS][COLS] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	//*
	// misuse of double pointer
	int* p1, ** p2;
	p1 = (int*)data;//array "width(ROWS) 정보가 없음
	p2 = &p1;
	//displayArray(p2);//run-time에러가 발생하는 것을 확인 
	//*/

	///*
	//array of pointers를 사용
	int *p3[ROWS], **p4; 
	p4 = (int**)p3;
	for (i = 0; i < ROWS; i++)
		p3[i] = (int*)data + i * COLS;
	displayArray(data);
	displayArray(&data[0][0]);//function overloading
	displayArray(p4);
	displayArray(p3);
	//*/
	cout << endl;
	system("pause");
}
int multiply(int n1, int n2) {
    return (n1 * n2);
}
float multiply(float n1, float n2) {
    return (n1 * n2);
}
/*
void displayArray(int a[][COLS])//int (*)[]와 동일함
{
	cout << endl<<"use array: int [][]" << endl;
	for (int i = 0; i < ROWS; i++)
		for (int j = 0; j < COLS; j++)
			cout << "   " << a[i][j];
}
*/
///*
void displayArray(int (*a)[COLS])
{
	cout << endl<<"use pointer-to-array: int (*)[]" << endl;
	for (int i = 0; i < ROWS; i++)
		for (int j = 0; j < COLS; j++)
			cout << "   " << a[i][j];
}
//*/
void displayArray(int *a)
{
	cout <<endl<< "use simple pointers: int *a" << endl;
	for (int i = 0; i < ROWS; i++)
		for (int j = 0; j < COLS; j++)
			cout << "   " << *(a+ COLS * i + j);
}
//*
void displayArray(int** a)//use double pointer - int *[]와 동일함
{
	cout <<endl<< "use double pointers: int **a" << endl;
	for (int i = 0; i < ROWS; i++)
		for (int j = 0; j < COLS; j++)
			cout << "   " << a[i][j];
}
//*/
/*
void displayArray(int *a[COLS])//use array of pointers
{
	cout << endl<<"use array of pointers: int *a[]" << endl;
	for (int i = 0; i < ROWS; i++)
		for (int j = 0; j < COLS; j++)
			cout << "   " << a[i][j];
}
*/