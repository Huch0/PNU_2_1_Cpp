// 6-1.SIDE.CPP
#include <iostream>
using namespace std;
/*
실습 1
1)내용
 함수 활용을 통해서 side effect에 대해 알아보자.

2)방법
 가. 실행을 통하여 multiply 함수가 main의 a값 까지 변경하는 것을 확인해보자.
*/
// 곱셈 함수는 정확하다. 그러나 reference parameter의 값을 변경하게 되어 non-local 데이터를 변경하게 된다.
int multiply (int &x, int &y){
    x *= y;
	cout<<"multiply(): x = "<<x<<", y = "<<y<<endl;
    return x;
}

void main (){ 
	
    // 값 치환에 의한 초기화
    int a = 5, b = 3, c = 0;
	// 다음 표현식은 side effect 때문에 잘못된 결과를 준다.
    c = a + multiply (a, b);
	cout<<"after multiply(): a = "<<a<<", b = "<<b<<endl;
    cout << "5 + 3 * 5 = "<< c << endl << endl;
	system("pause");
}