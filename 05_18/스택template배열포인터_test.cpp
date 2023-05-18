// 객체 스택 template
/*
* stack의 데이터 멤버를 *data[50];로 하는 방법 > int, float, double에는 적합하지 않다
*
*/
#include <iostream>
#include <string>
using namespace std;
class Person {
    string pid;
    string pname;
public:
    Person(string pid = "none", string pname = "none") : pid(pid), pname(pname) {}
    ~Person() {}

    friend ostream& operator<<(ostream&, Person&);
};
ostream& operator<<(ostream& ostream, Person& p) {
    ostream << "| " << p.pid << " | " << p.pname << " |" << endl;

    return ostream;
}
class Student : public Person {
    string deptName;
public:
    Student(string pid = "none", string pname = "none", string deptName = "none") : Person(pid, pname), deptName(deptName) {}
    ~Student() {}
};

template <class T>
class Stack {
    T* data[50];
    int nElements;
public:
    Stack() {
        nElements = 0;
        for (int i = 0; i < 50; i++) {
            data[i] = nullptr;
        }
    }

    void Push(T* elem);
    T* Pop();
    int Number();
    int Empty();
};
template <typename T>
void Stack<T>::Push(T* elem) {
    data[nElements] = elem;
    nElements++;
}
template <typename T>
T* Stack<T>::Pop() {
    if (!this->Empty()) {
        nElements--;
        return data[nElements];
    }

    return nullptr;
}
template <typename T>
int Stack<T>::Number() {
    return nElements;
}
template <typename T>
int Stack<T>::Empty() {
    return (nElements == 0);
}

void main() {
    Stack <int> intStack;
    
    intStack.Push(new int(50));
    intStack.Push(new int(19));
    intStack.Push(new int(3));
    intStack.Push(new int(10));
    intStack.Push(new int('aa'));

    cout << "-----int type stack" << endl;
    while (!intStack.Empty()) {
        cout << *intStack.Pop() << endl;
    }
    
    Stack <double> doubleStack;
    /*
    doubleStack.Push(500.8);
    doubleStack.Push(1992.8);
    doubleStack.Push(33.8);
    doubleStack.Push(1024.8);

    cout << "-----double type stack" << endl;
    while (!doubleStack.Empty()) {
        cout << doubleStack.Pop() << endl;
    }
    */
    Stack <string> stringStack;

    stringStack.Push(new string("500"));
    stringStack.Push(new string("1992"));
    stringStack.Push(new string("33"));

    cout << "-----string type stack" << endl;
    while (!stringStack.Empty()) {
        cout << *stringStack.Pop() << endl;
    }
    Stack <Person> personStack;

    personStack.Push(new Person("p1", "hong"));
    personStack.Push(new Person("p2", "song"));
    personStack.Push(new Person("p3", "ong"));
    personStack.Push(new Person("p4", "han"));
    Person* p = new Person("p6", "unkown");
    personStack.Push(p);
    Student* q = new Student("p7", "Gam", "DB");
    personStack.Push(q);
    personStack.Push(new Student("p5", "kim", "com"));//void Stack <T>::Push(T elem) {
    cout << "-----string type stack" << endl;
    while (!personStack.Empty()) {
        cout << *personStack.Pop() << endl;
    }
    system("pause");
}

