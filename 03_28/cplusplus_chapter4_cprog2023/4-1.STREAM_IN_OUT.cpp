//4-1. STREAM_IN_OUT.cpp  4.1 변수 scope와 표준 입출력
#include <iostream>
using namespace std;

class Person{
	/*
    ostream& operator<<(char); 
    ostream& operator<<(short);
    ostream& operator<<(int);
    ostream& operator<<(long);
    ostream& operator<<(float);
    ostream& operator<<(double);
   */
	friend ostream& operator<<(ostream& stream, const Person &p);
private:
    int idNum;
    int age;
    //23.3.23 추가한 코드
    char* name;//이름 field를 추가함
    char* address;
    char dept[20];

public:
    Person() { idNum = 0; age = 0; name = nullptr; address = nullptr; }
    Person(int , int , char* , char*, char* ); 
    ~Person();
};
Person::~Person() {
    delete[]name;

}
Person::Person(int idNum, int age, char* name, char* address, char dept[]) {
    this->idNum = idNum;
    this->age = age;
    this->name = new char[20];
    strcpy(this->name, name);//_CRT_SECURE_NO_WARNINGS를 속성 > 전처리기>전처리기 정의 편집하여 "_CRT_SECURE_NO_WARNINGS"를 추가
    int len = strlen(address) + 1;//null char를 포함
    this->address = new char[len];
    strcpy(this->address, address);
    //this->dept = dept;
    strcpy(this->dept, dept);
}
//주석 1번
//* operator overloading 사용예
ostream& operator<<(ostream& stream, const Person &p){
    stream<<"idNum =  "<<p.idNum<<", age = "<<p.age<<", name = " << p.name << ", address = "<<p.address<<", dept = "<<p.dept<<endl;
    return stream;
}
//*/
void main() {
    Person p(941111, 20, "hong", "Busan", "CPP");//2022 version에서 에러 발생시 > 상단의 프로젝트 > 속성>C/C++.준수모드>아니오선택
    cout << "저의" << p << "입니다." << endl << endl; //error - 주석1을 해제하지 않으면 오류 발생을 확인

    Person s(981212, 30, "kim", "Masan", "Java");
    cout << "저의" << s << "입니다." << endl << endl;
    system("pause");
}