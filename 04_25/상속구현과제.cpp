//7장 클래스 상속 과제
#include <iostream>
#include <string>
using namespace std;
class Dept {
	char dname[10];
	char* city;
	ostream& operator<<(Dept&);
};
class Person {
private:
	string pid;
	string pname;
	ostream& operator<<(Person&);

};
class Employee : protected Person {
private:
	char* eno;
	Dept* dname;
protected: 
	void MoveDept(Dept* dname);
	ostream& operator<<(Employee&);

};
class Coder : private Employee {
private:
	char* language;
	double workYears;
public:
	int operator > (Coder&);//
	Coder(char* language, double workYears, char* eno, Dept* dname, string pid, string pname);
	void MoveDept(Dept* dname);//부서 이동
	ostream& operator<<(Coder&);

};
int main() {
    while (1)
    {
        Coder *codings[20];

        int select;
        //생성자 사용에 의한 입력은 new Coder("이름", ...)으로 값을 지정하여 입력
        cout << "\n선택 1: 객체 4개 입력(cin 사용), 2. 객체 10개 입력(생성자 사용), 3: 객체 정렬(Dept 이름)과 출력,4. 객체 정렬(Coder workYears)과 출력, 5. 종료" << endl;

        cin >> select;
        switch (select) {
        case 1://1: 객체 4개 입력(cin 사용)

            break;
        case 2://2. 객체 10개 입력(생성자 사용)

            break;

        case 3://3: 객체 정렬(Dept 이름)과 출력

            break;
        case 4://4. 객체 정렬(Coder workYears)과 출력

            break;

        default:
            exit(0);
            break;
        }
    }
    system("pause");
    return 1;
}