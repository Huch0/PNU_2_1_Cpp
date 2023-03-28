//4-1. STREAM_IN_OUT.cpp  4.1 변수 scope와 표준 입출력
#include <iostream>
using namespace std;

class Person {
    friend ostream& operator<<(ostream& stream, const Person& p);
private:
    int idNum;
    int age;
    //23.3.23 추가한 코드
    char* name;//이름 field를 추가함
    char* address;
    char dept[20];

public:
    Person() { idNum = 0; age = 0; name = nullptr; address = nullptr; }
    Person(int, int, char*, char*, char*);
    ~Person();
};

void main() {
    Person p(941111, 20, "hong", "Busan", "CPP");
    cout << "저의" << p << "입니다." << endl << endl; 

    Person s(981212, 30, "kim", "Masan", "Java");
    cout << "저의" << s << "입니다." << endl << endl;
    system("pause");
}