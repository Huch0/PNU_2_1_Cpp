// 5장-4.DATE2.CPP  5.3.3 class의 interface와 body 
#include <iostream>
#include "6장-3.DATE3.h"
using namespace std;
Date::Date(int m, int d, int y) :
    month(m), day(d), year(y) {
}

Date::Date() {
    month = 1;
    day = 1;
    year = 1900;
}

Date::Date(class Date d, int nn) {
    month = d.Month();
    day = d.Day();
    year = d.Year();
    for (int i = 1; i < nn; i++)
        IncreaseDate();
}

int Date::Month() {
    return month;
}
int Date::Day() {
    return day;
}
int Date::Year() {
    return year;
}
int Date::LeapYear() {
    if (year % 4 != 0) return 0;
    else
        if (year % 100 != 0) return 1;
        else if (year % 400 != 0) return 0;
        else return 1;
}
int Date::DaysInMonth() {
    switch (month) {
    case 2:
        if (LeapYear()) return 29;
        else return 28;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    default:
        return 31;
    }
}
void Date::IncreaseDate() {
    if (day < DaysInMonth())
        day++;
    else {
        day = 1;
        if (month != 12) month++;
        else {
            month = 1;
            year++;
        }
    }
}
void Date::PrintDate() {
    cout << endl << "Date : " << month << "/" << day << "/" << year;

}
void Date::PrintLeap() {
    cout << endl << "Year " << year;
    if (LeapYear()) cout << " is a leap-year";
    else cout << " is not a leap-year";
}
//*
int Date::operator > (Date d) {
    return Year() == d.Year() ? ((Month() == d.Month() ? Day() > d.Day() : Month() > d.Month())) : Year() > d.Year();
}
//*/