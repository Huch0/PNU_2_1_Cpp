//5장-5. rectangle_main.cpp   5.4.2 class 객체의 선언과 member 함수의 호출
#include <stdlib.h>
#include <iostream>
#include "5장-5-2.Rectangle.h"
using namespace std;
//main에서는 iostream, std, xxx.h 포함
//실습 내용: Rectangle.h 변경없으면 main 변경없다
//실습 내용: Rectangle.cpp 변경되어도 main 변경없다
void main(){
    Rectangle a(2,3,5,6), b(2,3,5,5);
    Rectangle *c = &b;	
    cout<<a<<b;
    if( a.Area() > c->Area())
        cout<<"a";
    else 
        cout<<"b";
    cout<<"가 더 넓은 면적을 가진다"<<endl;
	if (a == b) cout << "a와 b는 같다";
	else cout << "a와 b는 다르다"<<endl;
	system("pause");
}