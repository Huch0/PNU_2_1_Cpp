
//4장-7. increase.cpp   4.4.3 reference에 의한 함수 parameter 전달 - 3차원 배열로 확장
#include <iostream>
using namespace std;
#define TIERS 2
#define ROWS 3
#define COLS 2

int sum(const int t[][ROWS][COLS], int);
//void increase(int(*)[ROWS][COLS], int);
void increase(int (**t)[COLS], int);
void displayArray(int(*)[ROWS][COLS], int);
void main(void){
	int number[TIERS][ROWS][COLS] = {{ {1, 2},{3,4},{4,5} }, { {6,7},{8,9},{10,11}}};
	int total = 0;
	displayArray(number, TIERS);
	total = sum(number, TIERS);
	cout<<"sum()::totoal = "<<total<<endl;
	increase(number, TIERS);
	displayArray(number, TIERS);
	total = sum(number, TIERS);
	cout<<"sum2()::totoal = "<<total<<endl;
	system("pause");
}
int sum(const int t[][ROWS][COLS], int row)
{
	int total = 0;
	for (int i = 0; i < row; i++)
	{
		for (int k = 0; k < ROWS; k++)
		for (int j = 0; j < COLS; j++)
			total += (*t)[k][j];
		t++;
		//(*t)[0] += 2;
	}
	return total;
}
//void increase(int(**t)[COLS], int row) //int (*)[3][2]가 int (**)[2]와 호환되지 않음
void increase(int(*t)[ROWS][COLS], int row)
{
	for (int i = 0; i < row; i++)
	{
		for (int k = 0; k < ROWS; k++)
		for (int j = 0; j < COLS; j++)
			(*t)[k][j] *= 2;
		
		t++;
	}
}
void displayArray(int(*a)[ROWS][COLS], int tiers)
{
	cout << endl << "use pointer-to-array: int (*)[][]" << endl;
	for (int g = 0; g < tiers; g++)
	{
		cout << endl << "tier = " << g << endl;
		for (int i = 0; i < ROWS; i++)
			for (int j = 0; j < COLS; j++)
				cout << "   " << (*a)[i][j];
		a++;
	}
	cout << endl;
}