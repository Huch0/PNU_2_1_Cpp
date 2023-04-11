// 6-3.DANGLE.CPP
#include <iostream>
using namespace std;
/*
실습 3
1)내용
 aliasing으로 발생되는 dangling reference에 대해 이해해보자.

2)방법
 가. 객체 a를 삭제했을 경우 변수 b가 가리키는 값이 사라지는 것을 실행결과를 통해서 확인해보자.
*/
void main (){
	// 정수에 대한 pointer 선언
    int *a;
    int *b;
	  // new 연산은 정수 변수를 위한 memory를 할당한다.
	a = new(int);
    b = new(int);
        // pointer 변수에 대한 연산을 수행한다.
	*a = 10;
	    // b는 a의 같은 위치 aliasing를 가리킨다.
    b = a;
    cout<<"Before delete(): a = "<<a<<", b = "<<b<<endl;
	cout << endl << "The original value of b is " << *b << endl;
	    // 다음 문장(a의 제거)은 a에 할당된 memory가 return되므로 b의 값은 임의 위치를 가리킨다.
 	delete (a);
	    cout<<"After delete(): a = "<<a<<", b = "<<b<<endl;
    cout << "After the deallocation of a, the value of b becomes"<<*b<< endl;
	  // b에 대한 다음 문장은 틀린 것은 아니지만 의미가 없다.
 	*b *= 2;
    cout << "Multiplying b for 2 yields a value of " << *b << endl;
	system("pause");
}