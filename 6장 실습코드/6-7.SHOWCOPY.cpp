// 6.7.SHOWCOPY.CPP
#include <iostream>
using namespace std;
/*
실습 7
1)내용
 복사 생성자와 치환 연산자가 어떻게 사용되는지를 확인해보자.
2)방법
 가. 주석 1을 제거 혹은 그대로 두고 실행하여 출력 값의 차이를 확인해보자.
*/
class Test{
	// 객체의 값
	int value;
	// 객체의 번호
	int obj_number;
	// 마지막 객체의 번호
	static int last_obj;

public:
	// 하나의 parameter를 가진 표준 생성자
	Test(int n){
		value = n;
		obj_number = ++last_obj;
		cout << "Standard constructor(object no." << obj_number << ") : value = " << value << endl;
	}
	// 복사 생성자
	Test(const Test& t){
		// 복사 생성자를 제공하면 default copy가 수행되지 않으므로 값을 복사할 필요가 있다.
		value = t.value;
		// 같은 값을 갖고 있지만 그것은 또 다른 객체이다
		obj_number = ++last_obj;
		cout << "Copy constructor(object no." << obj_number  << ") : value = " << value << endl;
	}
	// 소멸자
	~Test( ){
		cout << "Destructor (object no." << obj_number << ")" << endl;
	}
	// 치환 연산자
	Test& operator=(const Test& t){
		// 치환 생성자를 제공하면 default copy가 행해지지 않기 때문에 값을 복사할 필요가 있다.
		value = t.value;
		cout << "Assignment operator (from object no." << t.obj_number << " to object no." << obj_number << ") : value = "<< value << endl;
		return (*this);
	}
	// 증가 연산자
	int operator++( ){
		return ++value;
	}
};
// static 데이터 member의 외부 정의
int Test::last_obj = 0;
// 증가된 값을 출력하는 global 함수
// parameter와 return 값은 복사에 의해 전달된다.
/*
Test PrintNext(Test t){ //복사 생성자가 호출되는 것을 확인
cout<<"printNext():: ";
// ++함수 호출 
cout << "New increased value = " << ++t << endl; 
//cout << "New increased value = " << ++(++t) << endl;
return t;
}
*/
//주석 1

//참조에 의해 전달을 하게 되면 임시 객체가 생성되지 않는다.
//*
Test& PrintNext(Test& t){ 
	cout << "New increased value = " << ++t << endl;
	return t;
}
//*/
void main( ){
	cout << "1. New object" << endl;
	{
		Test t1(25);
		cout << endl;
		cout << "2. New object…copied" << endl;
		Test t2 = t1;
		cout << endl;
		cout << "3. New object…increased" << endl;
		Test t3 = PrintNext(t1);
		cout << endl;
		cout << "4. Assignment of increased object" << endl;
		t2 = PrintNext(t3);
	}
	cout << endl;
	system("pause");
}