// 11장-5.CONSTRUC.CPP  11.5 생성자의 중지
#include <iostream>
using namespace std;
class Date{
private:
    int month;
    int day;
    int year;
public:
    Date(int d_month, int d_day, int d_year){
        cout << "Entering the constructor…" << endl;
        if (d_month>12)
            throw("Month too big!");
        if (d_day>13)
            throw("Day too big!");
        month = d_month;
        day = d_day;
        year = d_year;
        cout << "Date object properly built" << endl;
    }

    ~Date(){
        cout << "Destructor called" << endl;
    }

    void Print( ){
        cout << month << '.' << day << '.' << year << endl;
    }
};

void main(){
    try{
        Date d1(11, 11, 1993);
        d1.Print( );
        cout << endl;
        Date d2(8, 1992, 13);
        d2.Print( );
    }
    catch (const char * description){
        cout << "Exception: " << description << endl;
    }
	system("pause");
}