// 6장-2.CONSTFN.CPP
#include <iostream>

using namespace std;

// 상수 함수의 예
class A {
    int n;
public:
    A (int m) : n (m) { } //생성자
    int Read () const {//상수 함수
		cout<<"Read()::n = "<<n<<endl;
		return n;
    }

    void Change (int m) {
		cout <<"Change()::n= "<<n<<endl;
        n = m;
    }
};

void main (){
	A a1 (5);
    // argument ‘4’
    a1.Change (4);
    a1.Read ();

    const A a2(8);
    
	// 경고 메시지 발생
    //a2.Change (6);
    a2.Read ();
	system("Pause");
}