// 6장-3.DATE3.H
using namespace std;

class Date{
    // private 데이터
    int month;
    int day;
    int year;

public:
    // day, month 와 year로 date를 생성한다. 
	//*
    Date (int m, int d, int y);
    // default date를 생성한다. 
    Date ();
    // 날짜 d 이후 nn일 지난 한 날짜를 생성한다. 
    Date (class Date d, int nn);
    // 그 달의 날짜를 return한다.
    int Day ();
    // 그 해의 월을 return한다.
    int Month ();
    // 그 해를 return한다.
    int  Year ();
    // 윤년이면 1을, 윤년이 아니면 0을 return한다.
    int LeapYear ();
    // 해당 월의 날짜수를 return한다.
    int DaysInMonth ();
    // 하루를 증가시킨다. 
    void IncreaseDate ();
    // 현재 날짜를 출력한다. 
    void PrintDate ();
    // 윤년을 출력한다. 
    void PrintLeap ();
    int operator > (Date d);
	// prefix 증가 연산자(prefix increment operator)
	//*
	Date& operator++() {
		// member 함수 IncreaseDate를 호출한다.
		IncreaseDate();
		return *this;
	}
	// postfix 증가 연산자( postfix increment operator)
	Date&  operator++(int) {
		Date theOldOne = *this;
		IncreaseDate();
		return theOldOne;;
	}
    //*/
};