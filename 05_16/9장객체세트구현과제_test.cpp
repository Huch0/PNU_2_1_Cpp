/*
* 객체들의 Set을 포함하는 테이블의 배열을 갖는 클래스 구현하기
*/
#include <iostream>
#include <string>
#define DefaultSize 50
using namespace std;
class Employee;
class Person { //추상 클래스로 구현한다
public:
    string GetName() { return pname; }
    void SetName(char* str) { pname = str; }
    string pid;
    string pname;
    Person() {}
    Person(string pid, string pname) : pid(pid), pname(pname) { }
    virtual void Print();
    virtual bool Equals(Employee*) = 0;
    virtual ~Person() {}

};
void Person::Print() {
    cout << "|" << pid << " | " << pname << " |";
    return;
}
class Employee : public Person {
private:
    string eno;
    string role;
public:
    Employee() :Person() {}
    Employee(string pid, string pname, string eno, string role) : Person(pid, pname), eno(eno), role(role) { }
    virtual void Print();
    virtual bool Equals(Employee* ep);
};
void Employee::Print() {
    Person::Print();
    cout << "| " << eno << " | " << role << " |";
}
bool Employee::Equals(Employee* ep) {
    if (eno == ep->eno && role == ep->role)
        return 1;
    else   
        return 0;
}
class Coder : public Employee {
private:
    string language;
public:
    Coder() :Employee() {}
    Coder(string pid, string pname, string eno, string role, string language) : Employee(pid, pname, eno, role), language(language) {}
    void Print();
};
void Coder::Print() {
    Employee::Print();
    cout << "| " << language<<" |";
}
class Student : public Employee {
private:
    string sid;
    string major;
public:
    Student(string sid, string major, string eno, string role, string pid, string pname) : Employee(pid, pname, eno, role), sid(sid), major(major) { }
    void Print();
};
void Student::Print() {
    Employee::Print();
    cout << "| " << sid << " | " << major << " |";
}
class Bag {
public:
    virtual int Add(Employee*); // 정수 하나를 bag에 삽입
    virtual int Delete(char*); //bag에서 정수 하나를 삭제
    virtual Employee* Search(char*);
    bool IsFull();
    // bag이 포화상태이면 true, 그렇지 않으면 false를 반환
    bool IsEmpty();
    // bag이 공백 상태이면 true, 그렇지 않으면 false를 반환
    int Top();
    virtual void Print();

protected:
    Bag(int bagSize) : bagMaxSize(bagSize), topBag(0) {
        arr = new Employee*[bagMaxSize];
        for (int i = 0; i < bagMaxSize; i++) {
            arr[i] = nullptr;
        }
    };
    void Full(); // bag이 포화상태일 때의 조치
    void Empty(); // bag이 공백 상태일 때의 조치

    Employee** arr; //> 생성자에서 arr = new Employee*[Size]; > arr[i] = new Employee();
    int bagMaxSize; // 배열의 크기
    int topBag; // 배열에서 원소가 들어 있는 가장 높은 위치
    //*
    ~Bag() {
        for (int i = 0; i < bagMaxSize; i++) {
            delete arr[i];
        }
        delete[] arr;
    }
    // */
};
// bag이 공백 상태이면 true, 그렇지 않으면 false를 반환
bool Bag::IsEmpty() {
    if (topBag == 0) 
        return 1;
    else 
        return 0;
}
// bag이 포화상태이면 true, 그렇지 않으면 false를 반환
bool Bag::IsFull() {   
    if (topBag == bagMaxSize)
        return 1;
    else 
        return 0;
}
 // bag이 포화상태일 때의 조치
void Bag::Full() {
    cout << "Bag is Full" << endl;
    return;
}
// bag이 공백 상태일 때의 조치
void Bag::Empty() {
    cout << "Bag is Empty" << endl;
    return;
}
// 정수 하나를 bag에 삽입
int Bag::Add(Employee* ep) { 
    if (this->IsFull()) {
        this->Full();
        return -1;
    }
    arr[topBag] = ep;
    topBag += 1;
    
    cout << "Successfully Added" << endl;
    return 1;
}

//bag에서 정수 하나를 삭제
int Bag::Delete(char* name) {
    int searched_index = 0;
    for (int i = 0; i < topBag; i++) {
        //cout << i << topBag << " Search : " << arr[i]->GetName() << " " << name << endl;
        if (arr[i]->GetName() == name) {
            break;
        }
        searched_index += 1;
    }
    //cout << "searched_index : " << searched_index << endl;
    if (searched_index != topBag) {
        delete arr[searched_index];
        
        for (int j = searched_index; j < topBag - 1; j++) {
            arr[j] = arr[j + 1];
            if (j != topBag - 1)
                arr[j + 1] = nullptr;
        }
        topBag -= 1;
        return 1;
    }
    cout << "There is no " << name << endl;
    return -1;
}
Employee* Bag::Search(char* name) {
    for (int i = 0; i < topBag; i++) {
        //cout << "Search : " << arr[i]->GetName() << " " << name << endl;
        if (arr[i]->GetName() == name) {
            return arr[i];
        }
    }
    cout << "There is no " << name << endl;
    return nullptr;
}
int Bag::Top() {
    return topBag;
}
void Bag::Print() {
    for (int i = 0; i < topBag; i++) {
        arr[i]->Print();
        cout << endl;
    }
}

class Set : public Bag {
public:
    Set(int setSize) :Bag(setSize) {}
    ~Set() {}
    int Add(Employee*);
    int Delete(char*);
    void Print();
    Employee* Search(char*);
};
int Set::Add(Employee* ep) {
    if (this->IsFull()) {
        this->Full();
        return -1;
    }
    
    for (int i = 0; i < bagMaxSize; i++) {
        if (arr[i] == ep) {
            cout << "Employee already exists" << endl;
            return -1;
        }
    }

    return Bag::Add(ep);
}
int Set::Delete(char* name) {
    return Bag::Delete(name);
}
void Set::Print() {
    Bag::Print();
}
Employee* Set::Search(char* name) { 
    return Bag::Search(name);
}
class RecordSet : public Set {
    int setMaxSize;//5개의 레코드 수
    int topRecordSet;//해당 레코드세트에서 입력할 위치
public:
    RecordSet(int maxSize) : Set(maxSize) {
        if (maxSize > 5) 
            setMaxSize = 5;
        else 
            setMaxSize = maxSize;

        topRecordSet = 0;
    }
    ~RecordSet() {}
    Employee* Search(char*);
    void Print();
    int Add(Employee*);
};
Employee* RecordSet::Search(char* name) {
    return Set::Search(name);
}

int RecordSet::Add(Employee* ep) {
    if (topRecordSet == 5) {
        cout << "Record Set is Full" << endl;
        return -1;
    }

    int result = Set::Add(ep);
    if (result) {
        topRecordSet += 1;
    }

    return result;
}
void RecordSet::Print() {
    Set::Print();
}
class RecordTable {
    int tableMaxSize;
    int topRecordTable;
    RecordSet** data;
    int capacity;
public:
    RecordTable(int numberSet, int numberRecords) :tableMaxSize(numberSet), capacity(numberRecords) {
        topRecordTable = 0;
        data = new RecordSet * [numberSet];//10개의 set
        for (int i = 0; i < numberSet; i++) {
            data[i] = new RecordSet(numberRecords);//각 set는 5개 records
        }
    }
    ~RecordTable() {
        delete[] data;
    }
    int Add(Employee*); // 정수 하나를 bag에 삽입
    int Delete(char*);
    Employee* Search(char*);
    void Print();
};
int RecordTable::Add(Employee* ep) {
    ep->Print();
    if (topRecordTable == tableMaxSize) {
        cout << "Record Table is Full" << endl;
        return -1;
    }
    if (data[topRecordTable]->Add(ep) == -1) {
        topRecordTable += 1;
        
        return data[topRecordTable]->Add(ep);
    } else {
        return 1;
    }
}
int RecordTable::Delete(char* name) {
    int count = 0;
    for (int i = 0; i < topRecordTable; i++) {
        if (data[i]->Delete(name) == 1)
            count += 1;
    }
    
    return count;
}
Employee* RecordTable::Search(char* name) {
    Employee* result = nullptr;

    for (int i = 0; i < topRecordTable; i++) {
        result = data[i]->Search(name);
        if (result != nullptr) 
            break;
    }

    return result;
}
void RecordTable::Print() {
    cout << "Record Table : " << endl;
    for (int i = 0; i < tableMaxSize; i++) {
        cout << "Table " << i << " : " << endl;
        data[i]->Print();
    }
    return;
}

int main() {
    Employee* members[30];//Employee 선언으로 변경하는 문제 해결 필요 
    RecordTable table(10, 5);//10개의 record sets, 각 set은 5개의 records
    int select;
    Employee* p;
    int result;
    //table에 객체 30개 입력
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
    members[10] = new Student("s011", "coding", "E33", "manager", "23001", "hong");
    members[11] = new Student("s012", "coding", "E33", "manager", "23002", "ong");
    members[12] = new Student("s013", "coding", "E33", "manager", "23003", "dong");
    members[13] = new Student("s014", "coding", "E33", "manager", "23004", "fong");
    members[14] = new Student("s015", "coding", "E33", "manager", "23011", "tong");
    members[15] = new Student("s016", "coding", "E33", "manager", "23021", "nong");
    members[16] = new Student("s017", "coding", "E33", "manager", "23031", "mong");
    members[17] = new Student("s018", "coding", "E33", "manager", "23041", "kong");
    members[18] = new Student("s019", "coding", "E33", "manager", "23051", "long");
    members[19] = new Student("s020", "coding", "E33", "manager", "23101", "pong");
    members[20] = new Student("s021", "coding", "E53", "manager", "23141", "lim");
    members[21] = new Student("s022", "coding", "E53", "manager", "23241", "mim");
    members[22] = new Student("s023", "coding", "E53", "manager", "23341", "bim");
    members[23] = new Student("s024", "coding", "E53", "manager", "23441", "dim");
    members[24] = new Student("s025", "coding", "E53", "manager", "23541", "rim");
    members[25] = new Student("s026", "coding", "E53", "manager", "23641", "qim");
    members[26] = new Student("s021", "coding", "E53", "manager", "23741", "fim");
    members[27] = new Student("s021", "coding", "E53", "manager", "23841", "him");
    members[28] = new Student("s027", "coding", "E53", "manager", "23941", "jim");
    members[29] = new Student("s027", "coding", "E53", "manager", "24041", "jjj");

    while (1)
    {
        cout << "\n선택 1: member  객체 30개 입력, 2.table 출력, 3: table 객체 찾기,4. table에서 객체 삭제, 5. 종료" << endl;
        cin >> select;
        switch (select) {
        case 1:
            for (int i = 0; i < 30; i++)
            {
                table.Add(members[i]);

            }
            break;
        case 2:
            // table의 모든 객체 출력하기
            //table 모양으로 출력해야 한다: | *** | ???? | === |으로 출력한다.

            table.Print();
            break;
        case 3:
            // table에서 객체 찾기

            p = table.Search("kim");
            if (p == nullptr) cout << "kim이 존재하지 않는다" << endl;
            else
                p->Print();
            break;
        case 4:
            //table에서 객체 삭제하기
            result = table.Delete("hong");
            if (result >= 0)
                cout << "삭제된 records 숫자" << result << endl;

            break;

        default:
            exit(0);

        }
    }
    system("pause");
    return 1;
}