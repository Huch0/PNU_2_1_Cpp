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
        this->city = new char[strlen(city) + 1];
        strcpy(this->city, city);
    };
    ~Dept() {
        delete[] this->city;
    }

    friend ostream& operator<<(ostream& stream, Dept&);
    int operator > (Dept& another);
};

ostream& operator <<(ostream& stream, Dept& d) {
    stream << "dept_name : " << d.dname << " city : " << d.city;

    return stream;
}
int Dept::operator >(Dept& another) {
    if (strcmp(this->dname, another.dname) > 0) 
        return 1;
    else    
        return 0;
}
class Person {
private:
	string pid;
	string pname;
public:
    Person() {
        this->pid = "";
        this->pname = "";
    }
    Person(string pid, string pname) {
        this->pid = pid;
        this->pname = pname;
    };
  
    friend ostream& operator <<(ostream& stream, Person&);
    void ChangePidPname(string pid, string pname);
};
void Person::ChangePidPname(string pid, string pname) {
    this->pid = pid;
    this->pname = pname;
}
ostream& operator <<(ostream& stream, Person& p) {
    stream << "Person Info : " << endl;
    stream << "pid : " << p.pid << " pname : " << p.pname << endl;
    return stream;
}
class Employee : protected Person {
private:
	char* eno;
	Dept* dname;
protected: 
	void MoveDept(Dept* dname);
    void ChangeEno(char* eno);
	friend ostream& operator <<(ostream& stream, Employee& e);
public:
    Employee() : Person() {
        this->eno = new char[1];
        this->eno = "\0";
        this->dname = new Dept();
    }
    Employee(char* eno, Dept* dname, string pid, string pname) : Person(pid, pname) {
        this->eno = new char[strlen(eno) + 1];
        strcpy(this->eno, eno);
        
        this->dname = dname;
        // this->pid = pid; this->pname = pname; pid, pname은 private이라 사용못함.
    };
    ~Employee() {
        delete this->eno;
        delete this->dname;
    }
    Dept& get_Dept();
};
void Employee::MoveDept(Dept* dname) {
    delete this->dname;
    this->dname = dname;
}
void Employee::ChangeEno(char* eno) {
    delete this->eno;
    this->eno = new char[strlen(eno) + 1];
    strcpy(this->eno, eno);
}

ostream& operator <<(ostream& stream, Employee& e) {
    stream << "Employee Info : " << endl;
    stream << "eno : " << e.eno << " " << *e.dname << endl;
    stream << static_cast<Person&>(e) << endl;
    return stream;
}

Dept& Employee::get_Dept() {
    return *(this->dname);
}

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
    int operator >(Coder& another);//
    //Dept : char dname[10]
    int cmp_Dept(Coder& another) {
        if(this->get_Dept() > another.get_Dept()) 
            return 1;
        else    
            return 0;
    }
};
void Coder::MoveDept(Dept* dname) {
    this->Employee::MoveDept(dname);
}
//Coder(char* language, double workYears, char* eno, Dept* dname, string pid, string pname)
istream& operator >>(istream& stream, Coder& c) {
    char language[20];
    char eno[20];
    char dname[10];
    char city[20];
    string pid;
    string pname;
    cout << "Input Language, Work years, eno, dname, city, pid, pname : " << endl;

    stream >> language >> c.workYears >> eno >> dname >> city >> pid >> pname;
    c.language = new char[strlen(language) + 1];
    strcpy(c.language, language);
    c.ChangeEno(eno);
    Dept* tmp_Dept = new Dept(dname, city);
    c.MoveDept(tmp_Dept);
    c.ChangePidPname(pid, pname);

    return stream;
}
ostream& operator<<(ostream& stream, Coder& c) {
    stream << "Coder Info : " << endl;
    stream << "Language : " << c.language << " Workyears : " << c.workYears << endl;
    stream << static_cast<Employee&>(c) << endl;
    return stream;
}
int Coder::operator > (Coder& another) {
    return (this->workYears > another.workYears);
}

int main() {
    Coder* codings[20];
    Coder c0, c1, c2, c3;
    codings[0] = &c0; codings[1] = &c1; codings[2] = &c2; codings[3] = &c3;

    Coder* coder_0 = new Coder("C", 5, "20200001", new Dept("sss", "Busan"), string("011220"), string("Kim"));
    Coder* coder_1 = new Coder("C++", 20, "20220012", new Dept("sss", "Seoul"), string("001112"), string("Lee"));
    Coder* coder_2 = new Coder("C#", 5, "20220013", new Dept("bbb", "Gwangju"), string("991212"), string("Park"));
    Coder* coder_3 = new Coder("Java", 14, "20200002", new Dept("bbb", "Ulsan"), string("901010"), string("Jung"));
    Coder* coder_4 = new Coder("Python", 12, "20200041", new Dept("ddd", "Daegu"), string("010101"), string("Won"));
    Coder* coder_5 = new Coder("C++", 10, "20230001", new Dept("ddd", "Seoul"), string("050101"), string("Seo"));
    Coder* coder_6 = new Coder("Javascript", 20, "20190012", new Dept("fff", "Seoul"), string("010102"), string("Joo"));
    Coder* coder_7 = new Coder("Rust", 10, "20200005", new Dept("fff", "Suwon"), string("000101"), string("Woo"));
    Coder* coder_8 = new Coder("C", 50, "20190013", new Dept("aaa", "Busan"), string("011113"), string("Heo"));
    Coder* coder_9 = new Coder("Rust", 100, "20150001", new Dept("aaa", "Jeonju"), string("920101"), string("Son"));
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
            }

            len_codings = 4;
            // 이 밑은 출력을 위해 추가된 코드
            for (int i = 0; i < 4; i++) {
                cout << *codings[i]; 
            }
            //
            break;
        case 2://2. 객체 10개 입력(생성자 사용)
            //Coder(char* language, double workYears, char* eno, Dept* dname, string pid, string pname)
            len_codings = 10;
            codings[0] = coder_0; codings[1] = coder_1; codings[2] = coder_2; codings[3] = coder_3; codings[4] = coder_4; 
            codings[5] = coder_5; codings[6] = coder_6; codings[7] = coder_7; codings[8] = coder_8; codings[9] = coder_9; 

            // 이 밑은 출력을 위해 추가된 코드
            for (int i = 0; i < 10; i++) {
                cout << *codings[i]; 
            }
            //

            break;

        case 3://3: 객체 정렬(Dept 이름으로 정렬)과 출력
            for (int i = 0; i < len_codings; i++) {
                for (int j = 0; j < len_codings - i - 1; j++) {
                    if (codings[j]->cmp_Dept(*(codings[j + 1]))) {
                        Coder* tmp = codings[j];
                        codings[j] = codings[j + 1];
                        codings[j + 1] = tmp;
                    }
                }
            }

            for (int i = 0; i < len_codings; i++) {
                cout << *codings[i] << endl;
            }

            break;
        case 4://4. 객체 정렬(Coder workYears로 정렬)과 출력
            
            for (int i = 0; i < len_codings; i++) {
                for (int j = 0; j < len_codings - i - 1; j++) {
                    if (*(codings[j]) > *(codings[j + 1])) {
                        Coder* tmp = codings[j];
                        codings[j] = codings[j + 1];
                        codings[j + 1] = tmp;
                    }
                }
            }

            for (int i = 0; i < len_codings; i++) {
                cout << *codings[i] << endl;
            }
            break;

        default:
            exit(0);
            break;
        }
    }
    delete coder_1;
    system("pause");
    return 1;
}