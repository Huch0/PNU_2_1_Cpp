// 11장-8.VIRT_EXE.CPP  11.6 예외 class의 계층 구조
#include <iostream>
using namespace std;
class RangeError{
public:
    virtual void Print( ) = 0;
};
class MonthRange : public RangeError{
public:
    void Print( ){
        cout << "Generic error in the range of the month" 
              << endl;
    }
};
//
class MonthTooBig : public MonthRange{
public:
    void Print( ){
        cout << "Month is too big (december is the last)" 
              << endl;
    }
};

class NegativeMonth: public MonthRange{
public:
    void Print( ){
        cout << "Month is negative" << endl;
    }
};

class DayRange: public RangeError{
public:
    void Print( ){
        cout << "Generic error in the value of the day" 
              << endl;
    }
};

class DayTooBig: public DayRange{
public:
    void Print( ){
        cout << "Day is too big" << endl;
    }
};

class DayTooBigForMonth: public DayTooBig{
public:
    void Print( ){
        cout << "Day is too big for the specific month" 
              << endl;
    }
};

class NegativeDay: public DayRange{
public:
    void Print( ){
        cout << "Day is negative" << endl;
    }
};

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
        if (s_month == 2 && s_day > 29)
            throw DayTooBigForMonth();
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
        d1.SetDate(2, 29, 2017);
        d1.Print( );
        d2.SetDate(13, 3, 2017);
        d2.Print( );
		*/
		d2.SetDate(-06, 11, 2019);
		d2.Print();
		d2.SetDate(06, -11, 2019);
		d2.Print();
    }
    catch (RangeError &error){
        error.Print( );
    }
	system("pause");
}