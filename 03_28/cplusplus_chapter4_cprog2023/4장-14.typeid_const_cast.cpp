//4장-14 typeid_const_cast.cpp   4.5.1 const_cast
#include <iostream>  
#include <typeinfo>  
using namespace std;

int main()
{
   int a = 100;//int is read/write
   const int const_a = 111;//const int =>ㅜ const를 read/no write qualifier이라고 함
   a = const_a;
   //const_a = a;
   //const volatile int *b = &a; //차이를 구분
   const volatile int *const b = &a;
   cout << "typeid of b = " << typeid(b).name() << '\n';   //pointer b의 타입만 출력
   int *c = const_cast <int*> (b);
   cout << "typeid of c = " << typeid(c).name() << '\n';
   system("pause");
 }