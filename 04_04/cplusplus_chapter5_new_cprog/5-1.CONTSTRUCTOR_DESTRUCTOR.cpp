//5-1.CONSTRUCTOR_DESTRUCTOR.CPP     5.3.1 생성자와 소멸자 
#include <iostream>
using namespace std;
// 여러 개의 생성자를 갖는 class Date의 부분 정의
class Date{
    int month;
    int day;
    int year;
public:
    // parameter가 있는 생성자
	//*
    // 기본 생성자 (parameter가 없는 경우에 default 값으로 초기화)
    Date (int m, int d, int y):month (m), day (d), year (y){ }
	//*/
    Date(){
    // compiler는 미 정의된 내부 데이터 member 값을 초기화하지 않는다.
    // 그래서 다음과 초기 값을 사전 설정하는 것이 필요하다.
       month = 1;
       day = 1;
       year = 1900;
    }
	//*/
    void showDate(){
        cout<<year<<"년 "<<month<<"월 "<<day<<"일"<<endl;
    }
    ~Date(){
        cout<<"소멸자 호출"<<endl;
    }
};
void main(){
	//주석 1: default constructor를 사용, constructor() 모두 주석 처리 - compiler 제공
    //생성자가 없을 경우
/*
    Date date;//default 값
    // 생성자가 없을 경우 compiler가 자동으로 생성해주지만,
    // 아무런 일을 하지 않기 때문에 쓰레기 값이 출력됨
    date.showDate();     
*/
	//주석2: constructor를 사용 -    Date(){} 사용한 경우
    //parameter가 없는 생성자
//*
    Date date1;
    date1.showDate();
//*/
    //주석3 -  parameter가 있는 생성자
/* 
    Date date2(3, 1, 2017);
    date2.showDate();
*/ 
	system("pause");
}