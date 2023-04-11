#include "6장-3.DATE3.h"
#include <iostream>
using namespace std;
void main() {
	Date d;
	Date e(4, 30, 2020);
	/*
	if (d > e)cout << "d > e" << endl;
	else cout << "d <= e" << endl;
	*/
	d.PrintDate();
	// prefix 연산자
	++d;
	d.PrintDate();
	// postfix 연산자
	d++;
	d.PrintDate();
	// prefix version에 대한 함수적 표기
	d.operator++();
	d.PrintDate();
	// postfix version에 대한 함수적 표기
	d.operator++(0);
	d.PrintDate();
	system("pause");
}