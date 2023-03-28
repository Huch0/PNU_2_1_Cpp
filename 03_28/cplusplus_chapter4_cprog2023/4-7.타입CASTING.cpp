//4-7. 타입CASTING.cpp    4.5.4 static_cast
#include <iostream>
#include <string.h>
using namespace std;

class Base{
public:
    virtual void classname(){cout << "Base" << endl;};
};
class Derived : public Base{
public:
    void classname(){cout << "Derived" << endl;};
};
void main(){
    //1번 주석
    //*
    cout<<"(1번)괄호를 이용한 타입 전환"<<endl;
    int i = 5;
    float f = 3.45;
    int j = (int)f;
    float f2 = (float)i;
    cout << "i : " << i << "   f : " << f << endl;
    cout << "j : " << j << "   f2 : " << f2 << endl;

    int x = 10, y = 2;
    float result;
    result = (float) x / (float) y;
    cout << "x : " << x << "   y : " << y << "   result : " << result << endl;
   //*/

    //2번 주석
    //*
    cout << endl << "(2번) static_cast" << endl;
    char ca = 'a';
	int k = 10;
	int number = (int)ca;
	int *p = &k;
	//number = (int)p;//실행 가능하나 문제가 있음
	//number = static_cast<int>(p);//pointer를 int로 변환하는 것을 못하게 함- static_cast를 사용하는 이유
    int num = static_cast<int>(ca);
    cout << "ca : " << ca <<"   num : " << num << endl;

    int d = 15, e = 7;
    float r = static_cast<float> (d) / static_cast<float>(e);
    cout << "d : " << d << "   e : " << e << "   result : " << r << endl;
    //*/

    //3번 주석
  ///*
    cout << endl << "(3번) const_cast" << endl;
    const int n = 10;
    //int* d = &n; 
    int* m = const_cast<int*> (&n); 
	*m = 99;//n,m의 주소는 같으나 변경된 값은 다르다- 주의 필요
    //n++;
    cout << "&n : " << &n << "   m : " << m << endl;
    cout << "n : " << n << "   *m : " << *m << endl; //n의 값은 const
  //*/

    //4번 주석
   //*
    Base *pb = new Derived();
    Derived *pd = NULL;
	pb = pd;
	//pb = (Base)pd;
    //pd = pb;
    pd = dynamic_cast<Derived*>(pb); 
    //*/

    //5번 주석
    //*
    //reinterpret_cast - 상이한 type을 강제로 변환

    int s = 1020;
    char *h = NULL;
    char *cp2 = NULL;
    h = (char*)s; 
    //h = static_cast<char*>(s);
    h = reinterpret_cast<char*>(s); 
    //cout <<*h<< endl; //메모리 접근 에러 발생
    //*/
	int nmb = 10;
	float *ptr = reinterpret_cast<float*>(&nmb);
	cout << *ptr << endl;
	system("pause");
}