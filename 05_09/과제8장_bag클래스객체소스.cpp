//8 �����̳� Ŭ���� - ��ü�� ���� 
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


class Student : public Person {//virtual�� Person() �����ڸ� ȣ������ ����
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
    } //������
    
    ~Bag() {// �Ҹ���
        for (int i = 0; i < top; i++) {
            delete arr[i];
        }
    }
    virtual void Add(Person*); // ���� �ϳ��� bag�� ����
    virtual Person* Delete(); //bag���� ���� �ϳ��� ����
    bool IsFull();
    // bag�� ��ȭ�����̸� true, �׷��� ������ false�� ��ȯ
    bool IsEmpty();
    // bag�� ���� �����̸� true, �׷��� ������ false�� ��ȯ
    int Top();
    Person* Find(string);
    virtual void Print();

protected:
    void Full(); // bag�� ��ȭ������ ���� ��ġ
    void Empty(); // bag�� ���� ������ ���� ��ġ
    Person* arr[DefaultSize];
    int MaxSize; // �迭�� ũ��
    int top; // �迭���� ���Ұ� ��� �ִ� ���� ���� ��ġ
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
        //cout << *arr[i]; ������
        arr[i]->Show();
    }
}
void Bag::Add(Person* pp) { //Bag�� �ߺ��˻���ϰ� ������ ����
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

    //���� ���� 0 ~ top - 1 ���̰� ����
    int random_index = 0;
    Person* pp = arr[random_index];
    
    // ���� ���� �Ѵ��� �� ĭ�� �� ����
    for (int i = random_index; i < top - 1; i++) {
        arr[i] = arr[i + 1];
        arr[i + 1] = nullptr;
    }
    top -= 1;
    return pp;
}
class Set : public Bag {//Set�� �ߺ� �Ұ���
public:
    Set(int MaxSize = DefaultSize) : Bag() {}//������}
    ~Set() {} // �Ҹ���
                 
    //Set �ڷᱸ���� �°� Add(), Delete() �Լ� ������
    void Add(Person*);
    //Person* Delete();
    void Print();
    
};
void Set::Print() {
    Bag::Print();
    cout << "Set ����" << endl;
}
void Set::Add(Person* pp) {
    if (this->IsFull())
        return;
    cout << this->IsFull() << endl;
    //�ߺ��˻� �Ŀ� ���� ���� ������ ����
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
    Person* members[30];//Person �������� �����ϴ� ���� �ذ� �ʿ� 
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
    members[13] = new PartTimeStudent("manager", "s004", "���", "23001", "hong");
    members[14] = new PartTimeStudent("accountant", "s005", "����", "23001", "hong");
    members[15] = new PartTimeStudent("salesman", "s006", "�Ƿ�", "23001", "hong");
    members[16] = new PartTimeStudent("planner", "s007", "����", "23001", "hong");
    members[17] = new PartTimeStudent("audit", "s008", "ȭ��", "23001", "hong");
    members[18] = new PartTimeStudent("DBA", "s009", "ȭ��", "23001", "hong");
    members[19] = new PartTimeStudent("DBA", "s010", "���", "23001", "hong");
    members[20] = new PartTimeStudent("coder", "s001", "computer", "23001", "hong");
    members[21] = new PartTimeStudent("coder", "s002", "DB", "23001", "hong");
    members[22] = new PartTimeStudent("tester", "s003", "Java", "23001", "hong");
    members[23] = new PartTimeStudent("designer", "s004", "���", "23001", "hong");
    members[24] = new PartTimeStudent("designer", "s005", "����", "23001", "hong");
    members[25] = new PartTimeStudent("AS", "s006", "�Ƿ�", "23001", "hong");
    members[26] = new PartTimeStudent("coder", "s007", "����", "23001", "hong");
    members[27] = new PartTimeStudent("audit", "s008", "ȭ��", "23001", "hong");
    members[28] = new PartTimeStudent("engineer", "s009", "ȭ��", "23001", "hong");
    members[29] = new PartTimeStudent("designer", "s010", "���", "23001", "hong");
    
    while (1)
    {

        cout << "\n���� 1: member  ��ü 30�� �Է�, 2. set ���, 3: set���� ��ü ã��,4. set���� ���� ��ü ����, 5. members[] �迭�� show �Լ�, 6. ����" << endl;
        cin >> select;

        switch (select) {
        case 1://1: Coder ��ü 10�� �Է°� ���
            for (int i = 0; i < 30; i++)
            {
                s.Add(members[i]);

            }
            break;
        case 2:
            // set�� ��� ��ü ����ϱ�
            s.Print();
            break;
        case 3:
            // set���� ��ü ã��
            cin >> name;
            p = s.Find(name);
            p->Show();
            break;
        case 4:
            //set���� ���� ��ü �����ϱ�
            p = s.Delete();
            if (!p) {
                cout << "Set is Empty" << endl;
                break;
            }
            p->Show();
            
            break;
        case 5:
            //members[]��  ��� ��ü�鿡 ���� show() ����: polymorphic function �����ϱ�
            Show(members);
            break;
        default:
            exit(0);

        }
    }
    system("pause");
    return 1;
}