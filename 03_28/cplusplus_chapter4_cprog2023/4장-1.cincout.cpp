//4장-1. CINCOUT.cpp  4.1 변수 scope와 표준 입출력
#include <iostream>
using namespace std;
void main ( ) {
    char A[20];
    strcpy(A, "hello");
	struct student {
		int sno;
		char name[10];
	};
	student s;
    int number ;
    float decimal ;
    cout << endl ; //새 line으로 이동	
    cout << "Get an integer: " ;
    cin  >> number ; //입력을 받는다
    cout << endl ;
    cout << "Get a decimal number: " ;
    cin  >> decimal; //입력을 받는다
    cout << endl << "The integer = " << number << " and the decimal = "<< decimal<<endl;
	//cout << s; //operator <<(cout, s) 연산자가 없다 - 4-1.STREAM_IN_OUT.cpp 참조
	system("pause");
}
