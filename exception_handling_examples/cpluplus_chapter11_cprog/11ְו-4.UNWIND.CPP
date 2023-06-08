// 11장-4.UNWIND.CPP   11.4 stack unwinding
#include <iostream>
using namespace std;
class Date{
private:
    int month ;
    int day ;
    int year ;
public:
    Date ( ){
        cout << "Default date built" << endl ;
    }
    ~Date ( ){
        cout << "Destructor called" << endl ;
    }
    void SetDate (int s_month, int s_day, int s_year){
        if (s_month > 12)
            throw ("Month too big!") ;
        if (s_day > 31)
            throw ("Day too big!") ;
        month = s_month ;
        day = s_day ;
        year = s_year ;
    }

    void Print ( ){
        cout << month << '.' << day << '.' << year << endl ;
    }
} ;

void main(){
    try {
        Date d1, d2 ;
        d1.SetDate (11, 11, 1993) ;
        d1.Print ( ) ;
        d2.SetDate (15, 11, 1993) ;
        d2.Print ( ) ;
    } //d1, d2 객체의 destructor가 호출된다

    catch (const char * description){
        cout << "Exception: " << description << endl ;
    }
	system("pause");
}