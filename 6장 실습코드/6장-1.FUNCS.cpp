// 6장-1.FUNCS.CPP
// 같은 연산(숫자를 3배하는 연산)을 수행하는 다른 종류의 함수 예
#include <iostream>
using namespace std;
// non-member("ordinary") 함수 정의
int Triple1 (int number){
    return number * 3;
}

class Number {
    int n;
public:
    //생성자
    Number (int num) :
    n (num)
    { }
    // member 함수 정의
    void Triple2 (){
        n *= 3;
    }
    int Value (){
        return n;
    }
    // class member 함수 정의
    static int Triple3 (int num){
        return num * 3;
    }
} ;

void main (){
    int intNum = 5;
    Number objNum (5);
    int triple;
    // 다음 함수 호출은 같은 결과를 얻는다.
    cout << "Show the result of three corresponding functions:" << endl;
    // non-member 함수 호출
    triple = Triple1 (intNum);
    cout <<"non-member 함수 호출: Triple1()::"<< triple << endl;
    // class(static) member 함수 호출
    triple = Number :: Triple3 (intNum);
    cout <<"static member 함수 호출: Number::Triple3()::"<< triple << endl;
    // member 함수 호출과 값 검색
    objNum.Triple2 ();
    objNum.Triple3(intNum);
    triple = objNum.Value ();
    cout <<"member 함수 호출: objNum.Triple2():"<< triple << endl;
	system("pause");
}