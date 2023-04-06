// 5장-6.LETTERS.CPP   5.5 class 데이터와 class 함수
#include <iostream>
#include "5장-6-1.Letters.h"
using namespace std;
// class 데이터 member와 소멸자를 가진 class의 예
Letters::Letters(char c) : ch(c) {
	num++; //class varible 사용
	cout << "New letter " << c
		<< ", the total number is " << num << endl;//num is static variable
}
Letters::~Letters() {
	num--;
	cout << "Letter " << ch << " destroyed, ";
	if (num == 1)
		cout << "1 letter remains" << endl;
	else
		cout << num << " letters remain" << endl;
}
char Letters::Value() {
	//num++;
	return ch;
}
