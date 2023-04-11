// 6-4.OVERLOAD.CPP
// overloading된 member function 호출과 non-member 함수 호출의 차이를 실습
#include <iostream>
using namespace std;
/*
실습 4
1)내용
 Complex의 member함수 Add()와 non-member함수 Multiple()의 선언 및 호출 방법을 통하여 함수 Overloading에 대해 이해해보자.

2)방법
 가. Complex의 member함수 Add()와 non-member 함수 Multiple()의 선언형태를 확인해보자.
 나. main함수에서 Add와 Multiple 함수 호출 방식을 확인해보자.
 다. 각 호출방식에 따른 출력결과를 통해 어떤 함수가 호출되었는지 확인해보자.
*/
// public member를 가진 class 
struct Complex {
    int r;    // 복소수의 실수부
	int i;    // 복소수의 허수부

	Complex(){
		r = 0;
		i = 0;
	}
  // overloading된 member 함수
    void Add (Complex c){
        r += c.r;
        i += c.i;
    }
    void  Add (Complex * pc){
        r += (*pc).r;
        i += (*pc).i;
    }
    void Add (int a, int b = 0){
        r += a;
        i += b;
    }
};
// overloading된 non-member 함수
Complex Multiply (Complex c1, Complex c2){
    Complex c3;
    c3.r = c1.r * c2.r - c1.i * c2.i;
    c3.i = c1.r * c2.i + c1.i * c2.r;
    return c3;
}
Complex Multiply (Complex c, int n){
    c.r *= n;
    c.i *= n;
    return c;
}
// overloading된 non-member 함수의 다른 예
void Print (Complex c){
    cout << c.r << "+" << c.i << "i" << endl;
}
void Print (int n){
    cout << n << endl;
}
void Print (char * string){
    cout << string << endl;
}
void Print ( ){
    cout << endl;
}
/*
class Complex {
private:
	float real;
	float imaginary;
public:
	Complex& operator+(Complex&);//함수 body를 구현할 수 있어야 한다
	//c = a + b + c; 실행이 가능한 코드 작성 훈련
	friend ostream& operator<<(ostream&, Complex &);//member 함수로 정의할 수 없는 이유: ostream class를 고칠 수 없기 때문이다
	//friend ostream& operator<<(Complex &);//member 함수 형태인데 ostream class를 고칠 수 없기 때문에 사용 못함

};
*/
// main 함수는 방금 정의된 overloading된 함수를 이용한다.
void main(){
	Complex x; x.Add(3, 1);//operator +()를 사용한 코드로 변경한 실습 시행
    Complex y; y.Add(1, 2);
    int z = 4;
   	Print ("Sum of the complex numbers:");
    cout<<"x = "; Print (x);//cout <<x;를 사용한 실습으로 수정하기
    cout<<"y = "; Print (y);
       // 두 복소수의 합: Add()함수의 첫 번째 version
	x.Add (y);
    Print ("----");
    cout<<"x+y = ";Print (x);
       // 복소수와 실수의 합: Add ()함수의 세 번째 version
	y.Add (z);
     // 다른 두 함수를 이용하여 두 곱을 계산한다.
	cout<<"After y.Add(z)::y = "; Print(y);

	Complex product1, product2;
	int v = 7;
	product1 = Multiply (x, y);//두개의 복소수의 곱하기
    product2 = Multiply (x, v);//복소수 X에 대하여 정수 V 곱하기
        // 초기 값과 결과 값을 출력한다.
	Print (); Print ();
    Print ("x equals to:");
    Print (x); Print ();
    Print ("y equals to:");
    Print (y); Print ();
    Print ("v equals to: ");
        // Print(x)와 다른 함수가 호출된다.
	Print (v);
        // 곱셈의 결과를 출력한다. 
	Print ();
    Print ("x * y = ");
    Print (product1);
    Print ();
    Print ("x * v = ");
    Print (product2);
	system("pause");
}