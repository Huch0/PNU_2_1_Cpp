// ∞¥√º Ω∫≈√ template
#include <iostream>
#include <string>
using namespace std;
class Person {
    string pid;
    string pname;
public:

};
class Student : public Person {
    string deptName;
public:
   
};

template <class T>
class Stack {
    T data[50];
    int nElements;
public:
    Stack();

    void Push(T elem);
    T Pop();
    int Number();
    int Empty();
};



template <class T>
int Stack <T>::Empty() {
    return (nElements == 0);
}


void main() {
    Stack <int> intStack;

    intStack.Push(50);
    intStack.Push(19);
    intStack.Push(3);
    intStack.Push(10);
    intStack.Push('aa');

    cout << "-----int type stack" << endl;
    while (!intStack.Empty()) {
        cout << intStack.Pop() << endl;
    }

    Stack <double> doubleStack;

    doubleStack.Push(500.8);
    doubleStack.Push(1992.8);
    doubleStack.Push(33.8);
    doubleStack.Push(1024.8);

    cout << "-----double type stack" << endl;
    while (!doubleStack.Empty()) {
        cout << doubleStack.Pop() << endl;
    }

    Stack <string> stringStack;

    stringStack.Push("500");
    stringStack.Push("1992");
    stringStack.Push("33");
    stringStack.Push("1024");

    cout << "-----string type stack" << endl;
    while (!stringStack.Empty()) {
        cout << stringStack.Pop() << endl;
    }
    Stack <Person> personStack;

    personStack.Push(Person("p1", "hong"));
    personStack.Push(Person("p2", "song"));
    personStack.Push(Person("p3", "ong"));
    personStack.Push(Person("p4", "han"));
    Person p = Person("p6", "unkown");
    personStack.Push(p);
    Student q = Student("p7", "Gam", "DB");
    personStack.Push(q);
    personStack.Push(Student("p5", "kim", "com"));//void Stack <T>::Push(T elem) {

    cout << "-----string type stack" << endl;
    while (!personStack.Empty()) {
        cout << personStack.Pop() << endl;
    }
    system("pause");
}

