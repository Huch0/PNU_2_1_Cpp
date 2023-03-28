//4장-13 const_cast.cpp   4.5.1 const_cast
#include<iostream>
using namespace std;
int increase(int *p) { 
	*p += 1;
	return *p;
}
int main()
{
   const int a = 100;
   const int *ptr = &a;
   //*ptr += 1;
   //a++;
   int *q = const_cast <int*> (ptr);//const_cast의 목적은 무엇인가?
   *q += 1;
   cout << "a = " << a << endl;
   cout<<"*q = "<<*q << endl<< "increase(q) = " << increase(q)<<endl;
   cout << "address of q = " << q << endl<<"address of a = " << &a << endl;//주소는 같은데 값이 다르다 이유는?
   //*q를 사용하여 값이 변경됨, const a의 객체를 *q를 통해서는 변경된 값을 보게 함, 그러나 cout <<a일 때는 데이터 영역의 상수 값은 변경이 안되므로 초기 값이 그대로 출력됨
   cout << "a = " << a << "   *q= " << *q << endl; //a와 *q의 값이 다르다 왜 그런가?
   system("pause");
}
