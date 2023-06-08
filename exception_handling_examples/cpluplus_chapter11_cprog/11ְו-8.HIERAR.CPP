// 11장-8.HIERAR.CPP의 두 번째 부분   11.6 예외 class의 계층 구조
#include <iostream>
#include "11장-7.HIERAR.h"
using namespace std;

class Date{
private:
    int month;
    int day;
    int year;
public:
    void SetDate ( int s_month, int s_day, int s_year ){
        if (s_month > 12)     
            throw MonthTooBig();
        if (s_month < 0)    
            throw NegativeMonth();
        if (s_day > 31)    
            throw DayTooBig();
        if (s_day < 0)    
            throw NegativeDay();
        month = s_month;
        day = s_day;
        year = s_year;
    }
    void Print( ){
        cout << month << '.' << day << '.' << year << endl;
    }
};
void main(){
    
    try{
        Date d1, d2;
		/*
        d1.SetDate(2, 44, 2017);
        d1.Print( );
        d2.SetDate(13, 15, 2017);
        d2.Print( );
		*/
		d2.SetDate(-06, 11, 2019);
		d2.Print();
		d2.SetDate(06, -11, 2019);
		d2.Print();
    }
    catch (DayRange)   {cout<< "Error in the day" << endl; }
    catch (MonthRange) {cout<< "Error in the month" << endl; }
  	system("pause");
}