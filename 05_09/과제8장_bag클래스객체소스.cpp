//8 컨테이너 클래스 - 객체들 집합 
#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string pid;
    string pname;
public:
    Person() {}
    Person(string pid, string pname) : pid(pid), pname(pname) { }
    virtual void Show();
    virtual bool operator==(Person&);
    string getName();
};
void Person::Show() {
    cout << "pid : " << pid << " pname : " << pname << endl;
}
string Person::getName() {
    return pname;
}
bool Person::operator==(Person& other) {
    if (this->pid == other.pid && this->pname == other.pname)
        return 1;
    else
        return 0;
}
class Employee : public Person {
private:
    string eno;
    string role;
public:
    Employee() :Person() {}
    int operator >(Employee&);
    Employee(string pid, string pname, string eno, string role) : Person(pid, pname), eno(eno), role(role) { }
    int operator < (Employee&);

    void Show() {
        Person::Show();
        cout << "eno : " << eno << " role : " << role << endl;
    }

};

class Coder : public Employee {
private:
    string language;
public:
    Coder() :Employee() {}
    Coder(string pid, string pname, string eno, string role, string language) : Employee(pid, pname, eno, role), language(language) {}
    int operator > (Coder&);//
    void Show() {
        Employee::Show();
        cout << "language : " << language << endl;
    }

};


class Student : public Person {//virtual은 Person() 생성자를 호출하지 않음
private:
    string sid;
    string major;
public:
    Student(string sid, string major, string pid, string pname) : Person(pid, pname), sid(sid), major(major) { }
    int operator < (Student&);

    void Show() {
        Person::Show();
        cout << "sid : " << sid << " major : " << major << endl;
    }
};

class PartTimeStudent : public Student {
private:
    string workType;
public:
    PartTimeStudent(string workType, string sid, string major, string pid, string pname) :
        Student(sid, major, pid, pname), workType(workType) {}
    int operator < (PartTimeStudent&);

    void Show() {
        Student::Show();
        cout << "workType : " << workType << endl;
    }
};
#define DefaultSize 10
class Bag { 
public:
    Bag(int MaxSize = DefaultSize) {
        this->MaxSize = MaxSize;
        this->top = 0;
        for (int i = 0; i < MaxSize; i++) {
            arr[i] = nullptr;
        }
    } //생성자
    
    ~Bag() {// 소멸자
        for (int i = 0; i < top; i++) {
            delete arr[i];
        }
    }
    virtual void Add(Person*); // 정수 하나를 bag에 삽입
    virtual Person* Delete(); //bag에서 정수 하나를 삭제
    bool IsFull();
    // bag이 포화상태이면 true, 그렇지 않으면 false를 반환
    bool IsEmpty();
    // bag이 공백 상태이면 true, 그렇지 않으면 false를 반환
    int Top();
    Person* Find(string);
    virtual void Print();

protected:
    void Full(); // bag이 포화상태일 때의 조치
    void Empty(); // bag이 공백 상태일 때의 조치
    Person* arr[DefaultSize];
    int MaxSize; // 배열의 크기
    int top; // 배열에서 원소가 들어 있는 가장 높은 위치
};
bool Bag::IsFull() {
    if (top == MaxSize)
        return 1;
    else
        return 0;
}
bool Bag::IsEmpty() {
    if (top == 0)
        return 1;
    else
        return 0;
}
int Bag::Top() {
    return top;
}
Person* Bag::Find(string name) {
    for (int i = 0; i < top; i++) {
        if (arr[i]->getName() == name) {
            return arr[i];
        }
    }
    return nullptr;
}
void Bag::Print() {
    for (int i = 0; i < top; i++) {
        //cout << *arr[i]; 사용금지
        arr[i]->Show();
    }
}
void Bag::Add(Person* pp) { //Bag은 중복검사안하고 무조건 삽입
    if (this->IsFull())
        return;

    arr[top] = pp;
    top += 1;
}
Person* Bag::Delete() {
    cout << " top : " << top << endl;
    cout << " isEmpty() : " << IsEmpty() << endl;
    if (this->IsEmpty())
        return nullptr;

    //난수 생성 0 ~ top - 1 사이값 생성
    int random_index = 0;
    Person* pp = arr[random_index];
    
    // 랜덤 추출 한다음 한 칸씩 다 땡김
    for (int i = random_index; i < top - 1; i++) {
        arr[i] = arr[i + 1];
        arr[i + 1] = nullptr;
    }
    top -= 1;
    return pp;
}
class Set : public Bag {//Set은 중복 불가능
public:
    Set(int MaxSize = DefaultSize) : Bag() {}//생성자}
    ~Set() {} // 소멸자
                 
    //Set 자료구조에 맞게 Add(), Delete() 함수 재정의
    void Add(Person*);
    //Person* Delete();
    void Print();
    
};
void Set::Print() {
    Bag::Print();
    cout << "Set 정보" << endl;
}
void Set::Add(Person* pp) {
    if (this->IsFull())
        return;
    cout << this->IsFull() << endl;
    //중복검사 후에 같은 값이 없으면 삽입
    cout << "top : " << top << endl;
    cout << "pp : ";
    pp->Show();
    for (int i = 0; i < top; i++) {
        if (*arr[i] == *pp)
            return;
    }

    Bag::Add(pp);
}
void Show(Person* p[]) {
    for (int i = 0; i < 30; i++) {
        p[i]->Show();
  }
}
int main() {
    Person* members[30];//Person 선언으로 변경하는 문제 해결 필요 
    Set s;
    int select;
    Person* p;
    Coder cx;
    string name; 
    members[0] = new Coder("p1", "hong", "E1", "Coding", "C++");
    members[1] = new Coder("p2", "hee", "E2", "Coding", "C++");
    members[2] = new Coder("p3", "kim", "E3", "Test", "JAVA");
    members[3] = new Coder("p4", "lee", "E4", "Test", "C#");
    members[4] = new Coder("p5", "ko", "E5", "Design", "GO");
    members[5] = new Coder("p6", "choi", "E6", "Design", "GO");
    members[6] = new Coder("p7", "han", "E7", "Sales", "PYTHON");
    members[7] = new Coder("p8", "na", "E8", "Sales", "C");
    members[8] = new Coder("p9", "you", "E9", "Account", "C++");
    members[9] = new Coder("p10", "song", "E10", "Production", "C#");
    members[10] = new PartTimeStudent("coding", "s001", "computer", "23001", "hong");
    members[11] = new PartTimeStudent("designer", "s002", "DB", "23001", "hong");
    members[12] = new PartTimeStudent("tester", "s003", "Java", "23001", "hong");
    members[13] = new PartTimeStudent("manager", "s004", "기계", "23001", "hong");
    members[14] = new PartTimeStudent("accountant", "s005", "전기", "23001", "hong");
    members[15] = new PartTimeStudent("salesman", "s006", "의류", "23001", "hong");
    members[16] = new PartTimeStudent("planner", "s007", "전자", "23001", "hong");
    members[17] = new PartTimeStudent("audit", "s008", "화공", "23001", "hong");
    members[18] = new PartTimeStudent("DBA", "s009", "화학", "23001", "hong");
    members[19] = new PartTimeStudent("DBA", "s010", "산업", "23001", "hong");
    members[20] = new PartTimeStudent("coder", "s001", "computer", "23001", "hong");
    members[21] = new PartTimeStudent("coder", "s002", "DB", "23001", "hong");
    members[22] = new PartTimeStudent("tester", "s003", "Java", "23001", "hong");
    members[23] = new PartTimeStudent("designer", "s004", "기계", "23001", "hong");
    members[24] = new PartTimeStudent("designer", "s005", "전기", "23001", "hong");
    members[25] = new PartTimeStudent("AS", "s006", "의류", "23001", "hong");
    members[26] = new PartTimeStudent("coder", "s007", "전자", "23001", "hong");
    members[27] = new PartTimeStudent("audit", "s008", "화공", "23001", "hong");
    members[28] = new PartTimeStudent("engineer", "s009", "화학", "23001", "hong");
    members[29] = new PartTimeStudent("designer", "s010", "산업", "23001", "hong");
    
    while (1)
    {

        cout << "\n선택 1: member  객체 30개 입력, 2. set 출력, 3: set에서 객체 찾기,4. set에서 임의 객체 삭제, 5. members[] 배열의 show 함수, 6. 종료" << endl;
        cin >> select;

        switch (select) {
        case 1://1: Coder 객체 10개 입력과 출력
            for (int i = 0; i < 30; i++)
            {
                s.Add(members[i]);

            }
            break;
        case 2:
            // set의 모든 객체 출력하기
            s.Print();
            break;
        case 3:
            // set에서 객체 찾기
            cin >> name;
            p = s.Find(name);
            p->Show();
            break;
        case 4:
            //set에서 임의 객체 삭제하기
            p = s.Delete();
            if (!p) {
                cout << "Set is Empty" << endl;
                break;
            }
            p->Show();
            
            break;
        case 5:
            //members[]의  모든 객체들에 대한 show() 동작: polymorphic function 구현하기
            Show(members);
            break;
        default:
            exit(0);

        }
    }
    system("pause");
    return 1;
}