// 6-5.ASSIGN.CPP
//operator =() 함수 호출과 body를 코딩할 수 있는 능력을 실습
#include <iostream>
using namespace std;

class FooWithPointer{
public:
    //data and functions
    int *pNumber; //main()이 변경이 되도록 의도된 public 정의, 개발시에는 private으로 선언되어야 함
    //default constructor
    FooWithPointer(){
        pNumber = new int;
        *pNumber=0;
    }
    //constructor with one parameter
    FooWithPointer(int i){
        pNumber = new int;
        *pNumber=i;
    }
    //destructor
    ~FooWithPointer(){
        cout<<"소멸"<<endl;
        delete pNumber;
    }
    //주석 1 - 주석을 미해제시에는 compiler가 제공하는 assignment code가 실행 - 주소만 복사됨
    //overloaded assignment operator
    /*
    //compile error 발생
    FooWithPointer operator = (const FooWithPointer& source){
        //copy the pointed value, not the pointer
        cout<<"사용자에 의해 overloading된 치환 연산자 호출"<<endl;
        *pNumber = *(source.pNumber);
        //the other members should be copied, too
        return this;// 오류가 나는 이유 파악 필요
    }
    */

    //*
    // 잘못된 실행결과 - runtime 오류
    FooWithPointer operator = (const FooWithPointer& source){
        //copy the pointed value, not the pointer
        cout<<"사용자에 의해 overloading된 치환 연산자 호출"<<endl;
        *pNumber=*(source.pNumber);
        //the other members should be copied, too
        return *this;
    }
    //*/

    /*
    //올바른 source code
    FooWithPointer& operator = (const FooWithPointer& source){
        //copy the pointed value, not the pointer
        cout<<"사용자에 의해 overloading된 치환 연산자 호출"<<endl;
        *pNumber=*(source.pNumber);
        //the other members should be copied, too
       // this는 자신이 포함된 함수를 호출한 객체의 주소를 가리킨다.
        return *this; 
    }
    */

};
void main(){
    cout<<"assign 호출 전"<<endl;
    FooWithPointer fp1(1);
    cout << "\tfp1의 pNumber은" << *fp1.pNumber << "이다 "<<endl;
    FooWithPointer fp2(2);
    cout << "\tfp2의 pNumber은" << *fp2.pNumber << "이다 "<<endl;
    FooWithPointer fp3(3);
    cout << "\tfp3의 pNumber은" << *fp3.pNumber << "이다" << endl << endl;

    fp1 = fp2;
    cout<<"assign(a=b의 경우) 호출 후"<<endl;
    cout << "\tfp1의 pNumber은" << *fp1.pNumber << "이다 "<<endl;
    cout << "\tfp2의 pNumber은" << *fp2.pNumber << "이다 "<< endl << endl;

    cout<<"fp2의 pNumber의 값을 변경 후"<<endl;
    *fp2.pNumber = 5;
    cout << "\tfp1의 pNumber은" << *fp1.pNumber << "이다 "<<endl;
    cout << "\tfp2의 pNumber은" << *fp2.pNumber << "이다 "<<endl<<endl;

    fp1 = fp2 = fp3;
    cout<<"assign(a=b=c의 경우) 호출 후"<<endl;
    cout << "\tfp1의 pNumber은" << *fp1.pNumber << "이다 "<<endl;
    cout << "\tfp2의 pNumber은" << *fp2.pNumber << "이다 "<<endl;
    cout << "\tfp3의 pNumber은" << *fp3.pNumber << "이다 " << endl << endl;
	system("pause");
}