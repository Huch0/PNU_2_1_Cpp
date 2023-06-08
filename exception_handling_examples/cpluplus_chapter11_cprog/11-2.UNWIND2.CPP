// 11-2.UNWIND2.CPP 11.4 stack unwinding
#include <iostream>
using namespace std;

class Date{
private:
    int month;
    int day;
    int year;
public:
    Date(){
        cout << "Default date built" << endl;
    }
    ~Date(){
        cout << "Destructor called" << endl;
    }
    void SetDate(int s_month, int s_day, int s_year){
        if(s_month > 12)
            throw("Month too big!");
        if(s_day > 31)
            throw("Day too big!");

        month = s_month;
        day = s_day;
        year = s_year;
    }

    void Print(){
        cout << "Month.Day.Year:" << month << "." << day << "." << year << endl;
    }
};

void main() {
        //주석 1
		//*
        Date d1, d2;
        try{
            d1.SetDate(06, 04, 2019);
            d1.Print();

            d2.SetDate(15,04,2019);
            d2.Print();
        }
        catch(const char* description){
            cout << "Exception: " << description << endl;
        }
        //*/

        // 주석 2
	    /*
        Date *d1, *d2;
        try{
            d1 = new Date;
            d2 = new Date;

            d1->SetDate(06, 04, 2019);
            d1->Print();

            d2->SetDate(15,04,2019);
            d2->Print();

            delete d1;    
            delete d2;    
        }
        catch(const char* description){
            cout << "Exception: "<< description << endl;
            delete d1;
            delete d2;
        }
		*/
        system("pause");
}