//7장 클래스 상속 과제
#include <iostream>
#include <string>
using namespace std;
class Dept {
    char dname[10];
    char* city;
public:
    Dept() : dname(""), city(new char[1]) {
        city[0] = '\0';
    }
    Dept(char* dname, char* city) {
        strcpy(this->dname, dname);
        this->city = city;
    };
    ~Dept() {
        delete this->city;
    }

    ostream& operator<<(Dept&);
};
class Person {
private:
	string pid;
	string pname;
	ostream& operator<<(Person&);
public:
    Person() {
        this->pid = "";
        this->pname = "";
    }
    Person(string pid, string pname) {
        this->pid = pid;
        this->pname = pname;
    };
  
};
class Employee : protected Person {
private:
	char* eno;
	Dept* dname;
protected: 
	void MoveDept(Dept* dname);
	ostream& operator<<(Employee&);
public:
    Employee() : Person() {
        this->eno = new char[1];
        this->eno = "\0";
        this->dname = new Dept();
    }
    Employee(char* eno, Dept* dname, string pid, string pname) : Person(pid, pname) {
        this->eno = eno; this->dname = dname;
        // this->pid = pid; this->pname = pname; pid, pname은 private이라 사용못함.
    };
    ~Employee() {
        delete this->eno;
        delete this->dname;
    }
};
class Coder : private Employee {
private:
	char* language;
	double workYears;
public:
    Coder() : Employee() {
        this->language = new char[1];
        this->language = "\0";
        this->workYears = 0;
    }
    Coder(char* language, double workYears, char* eno, Dept* dname, string pid, string pname)
        : Employee(eno, dname, pid, pname) {

        this->language = new char[strlen(language) + 1];
        strcpy(this->language, language);
        this->workYears = workYears;
    };
    ~Coder() {
        delete this->language;
    }
	void MoveDept(Dept* dname);//부서 이동
    friend istream& operator >>(istream& stream, Coder& c);
    friend ostream& operator <<(ostream& stream, Coder& c);
    int operator > (Coder&);//
};
istream& operator >>(istream& stream, Coder& c) {
    char tmp[20];
    stream >> tmp >> c.workYears;
    c.language = new char[strlen(tmp) + 1];
    strcpy(c.language, tmp);

    return stream;
}
ostream& operator <<(ostream& stream, Coder& c) {
    stream << "Language : " << c.language << " Workyears : " << c.workYears << endl;
    
    return stream;
}
int main() {
    Coder* codings[20];
    Coder c0, c1, c2, c3;
    codings[0] = &c0; codings[1] = &c1; codings[2] = &c2; codings[3] = &c3;
    int len_codings = 0;
    while (1)
    {
       
        int select;
        //생성자 사용에 의한 입력은 new Coder("이름", ...)으로 값을 지정하여 입력
        cout << "\n선택 1: 객체 4개 입력(cin 사용), 2. 객체 10개 입력(생성자 사용), 3: 객체 정렬(Dept 이름)과 출력,4. 객체 정렬(Coder workYears)과 출력, 5. 종료" << endl;
        cin >> select;
        switch (select) {
        case 1://1: 객체 4개 입력(cin 사용)
            for (int i = 0; i < 4; i++) {
                cin >> *codings[i]; //pointer 입력
                len_codings += 1;
            }

            // 이 밑은 추가된 코드
            for (int i = 0; i < 4; i++) {
                cout << *codings[i]; 
            }
            //
            break;
        case 2://2. 객체 10개 입력(생성자 사용)
            for (int i = 0; i < 10; i++) {
                Coder* input_coder = new Coder();
                cin >> *input_coder;
                codings[i] = input_coder;
                len_codings += 1;
            }

            break;

        case 3://3: 객체 정렬(Dept 이름으로 정렬)과 출력
            for (int i = 0; i < len_codings; i++) {

            }

            break;
        case 4://4. 객체 정렬(Coder workYears로 정렬)과 출력
            for (int i = 0; i < len_codings; i++) {

            }
            
            break;

        default:
            exit(0);
            break;
        }
    }
    system("pause");
    return 1;
}