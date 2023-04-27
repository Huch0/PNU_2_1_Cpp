//7장 클래스 상속 과제
#include <iostream>
#include <string>
#include <cstring>

using namespace std;
class Dept {
	string dname;
	string city;
	ostream& operator<<(Dept&);
public:
	Dept() {
		this->dname = "";
		this->city = "";
	}	
	Dept(string dname, string city) {
		this->dname = dname;
		this->city = city;
	}	
	~Dept() {};
	
	friend ostream& operator<<(ostream& stream, Dept&);
    int operator > (Dept& another);
};
ostream& operator <<(ostream& stream, Dept& d) {
    stream << "dept_name : " << d.dname << " city : " << d.city;

    return stream;
}
//3: Coder객체 정렬(Dept 이름과 도시)과 출력
int Dept::operator > (Dept& another) {
	if ((this->dname).compare(another.dname) > 0) 
        return 1;
    else if((this->dname).compare(another.dname) == 0) {
    	if((this->city).compare(another.city) > 0) 
    		return 1;
	} else
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
	}
	~Person() {};
	
	friend ostream& operator <<(ostream& stream, Person&);
    void ChangePidPname(string pid, string pname);
};
void Person::ChangePidPname(string pid, string pname) {
    this->pid = pid;
    this->pname = pname;
}
ostream& operator <<(ostream& stream, Person& p) {
    stream << "Person Info : " << endl;
    stream << "pid : " << p.pid << " pname : " << p.pname ;
    return stream;
}
class Employee : protected Person {
private:
	string eno;
	Dept* dname;
public:
	Employee() : Person() {
		this->eno = "";
		this->dname = new Dept();
	}
	Employee(string eno, Dept* dname, string pid, string pname)
		 : Person(pid, pname) {
		this->eno = eno;
		this->dname = dname;
	}
	~Employee() {
		delete this->dname;
	}
	
	int operator > (Employee& another);//
	friend ostream& operator <<(ostream& stream, Employee& e);
};

ostream& operator <<(ostream& stream, Employee& e) {
    stream << "Employee Info : " << endl;
    stream << "eno : " << e.eno << " " << *e.dname << endl;
    stream << static_cast<Person&>(e)  << endl;
    
    return stream;
}
int Employee::operator > (Employee& another) {
    return (*this->dname > *another.dname);
}

class Student : private Person {
private: 
    string sid;
    Dept* dname;
public:
	Student() : Person() {
		this->sid = "";
		this->dname = new Dept();
	}    	
	Student(string sid, Dept* dname, string pid, string pname)
		 : Person(pid, pname) {
		this->sid = sid;
		this->dname = dname;
	}
	~Student() {
		delete this->dname;
	}
	
	friend ostream& operator << (ostream& stream, Student& s);
};
ostream& operator << (ostream& stream, Student& s) {
    stream << "Student Info : " << endl;
	stream << "sid : " << s.sid << " " << *s.dname << endl;
    stream << static_cast<Person&>(s)  << endl;
	return stream;
}
class Coder : private Employee {
private:
	char* language;
	double workYears;
public:
	Coder(char* language, double workYears, string eno, Dept* dname, string pid, string pname)
        : Employee(eno, dname, pid, pname) {
        	
        this->language = new char[strlen(language) + 1];
        strcpy(this->language, language);
        this->workYears = workYears;
    };
	int operator >(Coder& another);//
	friend ostream& operator <<(ostream& stream, Coder& c);
};
ostream& operator<<(ostream& stream, Coder& c) {
    stream << "Coder Info : " << endl;
    stream << "Language : " << c.language << " Workyears : " << c.workYears << endl;
    stream << static_cast<Employee&>(c) << endl;
    
    return stream;
}
//3: Coder객체 정렬(Dept 이름과 도시)과 출력
int Coder::operator > (Coder& another) {
    return ((Employee)*this > (Employee)another);
} 

class PartTimeStudent : private Employee, private Student {
private:
    double salary;
    double grade;

public:
	PartTimeStudent() : Employee(), Student() {
		this->salary = 0;
		this->grade = 0;
	}
	PartTimeStudent(double salary, double grade, string eno, Dept* dname, string sid, string pid, string pname)
		 : Employee(eno, dname, pid, pname), Student(sid, dname, pid, pname) {
    	this->salary = salary;
    	this->grade = grade;
	}
	friend ostream& operator <<(ostream& stream, PartTimeStudent& pts);
};
ostream& operator<<(ostream& stream, PartTimeStudent& pts) {
    stream << "PartTimeStudent Info : " << endl;
    stream << "salary : " << pts.salary << " grade : " << pts.grade << endl;
    stream << static_cast<Employee&>(pts) << static_cast<Student&>(pts) << endl;
    
    return stream;
}

int Coder::operator > (Coder& another) {
    return (this->workYears > another.workYears);
}

int main() {
    Coder *codings[10];
    PartTimeStudent* workStudents[10];
    
    Coder* coder_0 = new Coder("C", 5, "20200001", new Dept(string("sss"), string("Busan")), string("011220"), string("Kim"));
    Coder* coder_1 = new Coder("C++", 20, "20220012", new Dept("sss", "Seoul"), string("001112"), string("Lee"));
    Coder* coder_2 = new Coder("C#", 5, "20220013", new Dept(string("bbb"), string("Gwangju")), string("991212"), string("Park"));
    Coder* coder_3 = new Coder("Java", 14, "20200002", new Dept(string("bbb"), string("Ulsan")), string("901010"), string("Jung"));
    Coder* coder_4 = new Coder("Python", 12, "20200041", new Dept(string("ddd"), string("Daegu")), string("010101"), string("Won"));
    Coder* coder_5 = new Coder("C++", 10, "20230001", new Dept(string("ddd"), string("Seoul")), string("050101"), string("Seo"));
    Coder* coder_6 = new Coder("Javascript", 20, "20190012", new Dept(string("fff"), string("Seoul")), string("010102"), string("Joo"));
    Coder* coder_7 = new Coder("Rust", 10, "20200005", new Dept("fff", "Suwon"), string("000101"), string("Woo"));
    Coder* coder_8 = new Coder("C", 50, "20190013", new Dept("aaa", "Busan"), string("011113"), string("Heo"));
    Coder* coder_9 = new Coder("Rust", 100, "20150001", new Dept("aaa", "Jeonju"), string("920101"), string("Son"));
    //PartTimeStudent(double salary, double grade, string eno, Dept* dname, string pid, string pname)
    PartTimeStudent* pts_0 = new PartTimeStudent(1000, 1, "20200001", new Dept("sss", "Busan"), "011220", "202000012", "Kim");
    PartTimeStudent* pts_1 = new PartTimeStudent(500, 2, "20220012", new Dept("sss", "Seoul"), "001112","202000012", "Lee");
    PartTimeStudent* pts_2 = new PartTimeStudent(100, 3, "20220013", new Dept("bbb", "Gwangju"),"991212","202000012", "Park");
    PartTimeStudent* pts_3 = new PartTimeStudent(1000, 2, "20200002", new Dept("bbb", "Ulsan"), "901010","202000012", "Jung");
    PartTimeStudent* pts_4 = new PartTimeStudent(700, 1, "20200041", new Dept("ddd", "Daegu"), "010101", "202000012","Won");
    PartTimeStudent* pts_5 = new PartTimeStudent(700, 4, "20230001", new Dept("ddd", "Seoul"), "050101", "202000012","Seo");
    PartTimeStudent* pts_6 = new PartTimeStudent(2000, 1, "20190012", new Dept("fff", "Seoul"), "010102,", "202000012", "Joo");
    PartTimeStudent* pts_7 = new PartTimeStudent(500, 5, "20200005", new Dept("fff", "Suwon"), "000101", "202000012","Woo");
    PartTimeStudent* pts_8 = new PartTimeStudent(100, 5, "20190013", new Dept("aaa", "Busan"), "011113", "202000012","Heo");
    PartTimeStudent* pts_9 = new PartTimeStudent(300, 3, "20150001", new Dept("aaa", "Jeonju"), "920101","202000012", "Son");
    while (1)
    {

        int select;
        //생성자 사용에 의한 입력은 new Coder("이름", ...)으로 값을 지정하여 입력
        //객체 출력은 cout<<*codings[i]만을 사용한다.
        cout << "\n선택 1: Coder 객체 10개 입력과 출력, 2. PartTimeStudent 객체 10개 입력과 출력, 3: Coder객체 정렬(Dept 이름> 도시 순서로 정렬)과 출력,4. partTimeStudents 객체 정렬(eno > sid 순서로 정렬)과 출력, 5. 종료" << endl;

        cin >> select;
        switch (select) {
        case 1://1: Coder 객체 10개 입력과 출력
            codings[0] = coder_0; codings[1] = coder_1; codings[2] = coder_2; codings[3] = coder_3; codings[4] = coder_4; 
            codings[5] = coder_5; codings[6] = coder_6; codings[7] = coder_7; codings[8] = coder_8; codings[9] = coder_9; 
            
			for (int i = 0; i < 10; i++) {
		        cout << *codings[i]; 
            }
            break;
        case 2://2. PartTimeStudent 객체 10개 입력과 출력
            workStudents[0] = pts_0; workStudents[1] = pts_1; workStudents[2] = pts_2; workStudents[3] = pts_3; workStudents[4] = pts_4; 
            workStudents[5] = pts_5; workStudents[6] = pts_6; workStudents[7] = pts_7; workStudents[8] = pts_8; workStudents[9] = pts_9; 
			
			for (int i = 0; i < 10; i++) {
		        cout << *workStudents[i]; 
            }
            break;

        case 3://3: Coder객체 정렬(Dept 이름과 도시)과 출력
			for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10 - i - 1; j++) {
                    if (codings[j]->cmp_Dept(*(codings[j + 1]))) {
                        Coder* tmp = codings[j];
                        codings[j] = codings[j + 1];
                        codings[j + 1] = tmp;
                    }
                }
            }

            for (int i = 0; i < 10; i++) {
                cout << *codings[i] << endl;
            }
            break;
        case 4://4. partTimeStudents 객체 정렬(eno > sid)과 출력

            break;

        default:
            exit(0);
            break;
        }
    }
    system("pause");
    return 1;
}
