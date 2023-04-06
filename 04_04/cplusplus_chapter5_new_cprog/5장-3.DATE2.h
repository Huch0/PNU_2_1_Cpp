// 5장-3.DATE2.H   5.3.3 class의 interface와 body 
// 여러 개의 생성자를 갖는 class Date의 부분 정의
// class Date의 모든 interface 정의 
#ifndef date2_h
class Date{
    // private 데이터
    int month;
    int day;
    int year;

public:
    // day, month, year로 한 날짜를 생성
    Date (int m, int d, int y);    // "표준" 생성자
    Date ();    // default 생성자 
    // 날짜 d 이후의 nn일이 지난 날짜를 생성
    Date (class Date d, int nn);
    // 다음 함수들은 또 다른 생성자 Date(Date d, int nn)에서
    // 사용되기 때문에 추가됨
    int Day ();    // 그 달의 날짜를 return함
    int Month ();    // 그 해의 월을 return함
    int Year ();    // 년도를 return함

    int LeapYear ();    // 윤년이면 1, 아니면 0을 return함
    int DaysInMonth ();    // 해당 월의 날수를 return
	void IncreaseDate ();    // 날짜를 하루 증가시킴

    void PrintDate ();    // 날짜를 출력함
    void PrintLeap ();    // 금년이 윤년인지 아닌지를 기술하는 문구를 출력
};
#endif