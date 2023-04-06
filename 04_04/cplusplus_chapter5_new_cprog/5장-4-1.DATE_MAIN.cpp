// 5장-4-1.DATE_MAIN.CPP   5.3.3 class의 interface와 body 
// 새로운 함수를 가진 class Date에 대한 test program
#include "5장-3.DATE2.h"//class Date의 header file만 포함
#include <stdlib.h>
//separate compilation: DATE2.h의 function body 구현이 DATE2.cpp
void main(){
    // 객체 newYearsDay를 정의하고 객체에 대한 다른 연산을 수행
    Date newYearsDay (1,1,2017);

    newYearsDay.PrintDate ();
    newYearsDay.IncreaseDate ();       // 변수가 가리키는 객체의 내부 데이터가 변경됨                             
    newYearsDay.PrintDate ();	
    newYearsDay.PrintLeap ();

    Date d (5,15,2016);    // Date class의 객체 d를 생성하고 다른 연산을 수행

    d.IncreaseDate ();
    d.PrintDate ();
    d.PrintLeap ();
    // 주어진 날짜부터 증가시켜 print한다
    for (Date dd(2,25,2017); dd.Day()<3||dd.Day()>10; dd.IncreaseDate())
		dd.PrintDate ();
	system("pause");
}