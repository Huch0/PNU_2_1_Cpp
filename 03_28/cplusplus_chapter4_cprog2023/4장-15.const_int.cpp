//4장-15 const_int.cpp   4.5.1 const_cast
#include <iostream>
using namespace std;
int f(int& a) { return 1; }
int g(volatile int& b) { return 0; }
void main ()
{
    volatile int x = 0; //메모리 변수, register 사용하여 최적화하지 않는다
	register int n = 1; //register 변수

    int y = 1;
	int* t;
	//t = &x;
	int *p;
	p = &n;
	y = x; y++;
	y = n; y++;
	x = y; x++;
	n = y; n++;
    //f(x); //volatile int x를 int&로 전달하는 오류
	f(n);
    g(y);
	g(x);
	system("pause");
}