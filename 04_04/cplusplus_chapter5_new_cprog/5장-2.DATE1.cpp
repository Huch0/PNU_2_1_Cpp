// 5장-2.DATE1.CPP   5.3 class
// 새로운 함수를 가진 class Date에 대한 test program
#include <iostream>
#include "5장-1.DATE1.h"

int main(){
    // 객체 newYearsDay를 정의하고 객체에 대한 다른 연산을 수행
    Date newYearsDay (1,1,2017);
   // Date dx;
    newYearsDay.PrintDate ();
    newYearsDay.IncreaseDate ();    // 변수가 가리키는 객체의 내부 데이터가 변경됨                               
    newYearsDay.PrintDate ();	
    newYearsDay.PrintLeap ();

    Date d (5,15,2016);    // Date class의 객체 d를 생성하고 다른 연산을 수행
    //d.day++;
    d.IncreaseDate ();
    d.PrintDate ();
    d.PrintLeap ();
    Date dy(13, 35, -1212);
    dy.PrintDate();//논리 오류 일자가 입력됨
    for (Date dd(2,25,2017); dd.Day()<3||dd.Day()>10; dd.IncreaseDate())    // 주어진 날짜부터 증가시켜 print한다
		dd.PrintDate ();
	system("pause");
    return 1;
}