//5-2.Private_Protected_Public.CPP  5.3.2 private, protected, 그리고 public
#include <iostream>
#include <string>
using namespace std;
/*
 1) 내용
  access modifier인 private, protected, public의 개념을 이해하는 것이다.
 2) 방법
  가. 각 주석을 해제하고 compile 오류나는 문장과 오류나지 않는 문장을 비교하여                 private, protected, public의 개념을 이해하자.
*/
class Test1{
private:
    int a;
    void T1_private(){
        cout << "T1_private()";
        cout << "a : " << a;
    }
protected:
    int b;
    void T1_protected(){
        cout << "T1_protected()";
        cout << "b : " << b;
    }
public:
    int c;
    // public를 이용해 해당 class에서 접근 가능한 변수 출력
    void T1_public(){ 
        cout << "T1_public()";
        cout << "a : " << a << "   ";
        cout << "b : " << b << "   ";
        cout << "c : " << c << "   ";
    }
    // public 함수를 이용한 class의 private 변수와 private 함수 접근
    void T1_public_private(){
        cout << "T1_public_private()";
        cout << "a : " << a << "   ";
        T1_private();
    }
    // public를 이용한 class의 protected 변수와 함수 접근
    void T1_public_protected(){
        cout << "T1_public_protected()";
        cout << "b : " << b << "   ";
        T1_protected();
    }
    Test1(){
        a = 1; b = 2; c = 3;
    }
};
class Test2 : public Test1{
private:
    int d;
    void  T2_private(){
        cout << "T2_private()";
        cout << "d : " << d;
    }
public:
    int e;
    // public를 이용해 해당 class에서 접근 가능한 변수 출력
    void T2_public(){
        cout << "T2_public()  "; 
        //cout << "a : " << a;
        cout << "b : " << b << "   ";
        cout << "c : " << c << "   ";
        cout << "d : " << d << "   ";
        cout << "e : " << e << "   ";
    }
    // public 함수를 이용한 class의 private 변수와 private 함수 접근
    void T2_public_private(){ 
        cout << "T2_public_private()";
        cout << "d : " << d << "   ";
        T2_private();
    }
    //public 함수를 이용한 Test1의 protected 변수와 private 함수 접근
    void T2_public_protected(){ 
        cout << "T2_public_protected()";
        cout << "b : " << b << "   ";
        T1_protected();
    }
    Test2(){
        d = 4; e = 5;
    }
};
void main(){
    Test1 t1;
    Test2 t2;

    // 1번 주석
	/*
    //외부에서 private, protected, public 데이터 접근
    cout << "1번 주석" << endl;
    //private변수여서 접근 불가
    //cout << "t1.a : " << t1.a << endl;
    //protected변수여서 접근 불가
    //cout << "t1.b : " << t1.b << endl; 
    cout << "t1.c : " << t1.c << endl;
    //private변수여서 접근 불가
    //cout << "t2.a : "  << t2.a << endl;
    //protected변수여서 접근 불가
    //cout << "t2.b : "  << t2.b << endl; 
    cout << "t2.c : " << t2.c << endl;
    //cout << "t2.d : " << t2.d << endl;
    cout << "t2.e : " << t2.e << endl << endl;
	*/

    // 2번 주석
	/*
    //private함수와 변수에 접근하는 방법
    cout << "2번 주석" << endl;
    //해당class에서 호출되지 않았기 때문에 error
    //t1.T1_private(); 
    //public()를 이용하여 private()가 해당 class에서 호출
    t1.T1_public_private(); 
    cout << endl;
    //t2.T2_private();
    t2.T2_public_private();
    cout << endl << endl;
	*/

    // 3번 주석
/*
    //protected함수와 변수에 접근하는 방법
    cout << "3번 주석" << endl;
    //해당class와 자식class 외에서 호출되었기 때문에 error
    //t1.T1_protected(); 
    t1.T1_public_protected();
    cout << endl;
    t2.T2_public_protected();
    cout << endl << endl;
*/

    // 4번 주석
/*
    //각 class에서 출력할 수 있는 데이터 출력
    cout << "4번 주석" << endl; 
    t1.T1_public();
    cout << endl;
    t2.T2_public();
    cout << endl;
*/
    system("pause");
}