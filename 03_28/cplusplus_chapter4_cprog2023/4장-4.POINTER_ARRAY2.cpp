//4장-4. POINTER_ARRAY2.cpp    4.3 pointer 변수와 reference 변수
#include <iostream>
//times()을 2배 곱하기로 변경
using namespace std;
#define ROWS 2
#define COLS 3
int times(int (&)[ROWS][COLS], int row);
int times2(int (*t)[COLS], int row);//pointer-to-array
int show(int(&)[ROWS][COLS], int row);
int show2(int(*t)[COLS], int row);//pointer-to-array
void main(void){
	int num[2][3] ={{1, 2, 3}, {4, 5, 6}};
	cout<<"times()::"<<endl;
	times(num, 2);
	show(num, 2);
	cout<<"times2()::"<<endl;
	times2(num, 2);
	show2(num, 2);
	system("pause");
}
int times(int (&t)[ROWS][COLS], int row)//how to pass 2D array as reference
{
	int total = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			//total += (*t)[j];//t를 pointer로 사용
			//(*t)[j] += t[i][j];
			t[i][j] *= 2;
		}
		//(*t)++;
	}
	return total;
}
int times2(int (*t)[COLS], int row)//how to pass 2D array as pointer
{
	int total = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < COLS; j++)
			(*t)[j] *= 2;
				//(*t)[j] += t[i][j];//t는 배열로 사용 가능
			t++;
	}
	return total;

}
int show(int(&t)[ROWS][COLS], int row)//how to pass 2D array as reference
{
	int total = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << " " << t[i][j];
		}
		cout << endl;
	}
	return total;
}
int show2(int(*t)[COLS], int row)//how to pass 2D array as pointer
{
	int total = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < COLS; j++)
			cout << " " << (*t)[j];//t는 배열로 사용 가능
		t++;
		cout << endl;
	}
	return total;
}