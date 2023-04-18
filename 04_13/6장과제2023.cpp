#include <stdlib.h>
#include <iostream>
/*

*/
using namespace std;
class String {
    char* data;

public:
    String() {
        this->data = new char[1];
        strcpy(this->data, "\0");
    }
    String(char* data) {
        this->data = new char[strlen(data) + 1];
        strcpy(this->data, data);
    }
    String(String* other) {
        this->data = new char[strlen(other->data) + 1];
        strcpy(this->data, other->data);
    }

    ~String() {
        delete this->data;
    }

    String& operator=(String& other);
    int operator>(String& other);
    int operator==(String& other);

    friend ostream& operator<<(ostream& stream, const String& s);
};

String& String::operator=(String& other) {
    delete this->data;
    this->data = new char[strlen(other.data) + 1];
    strcpy(this->data, other.data);

    return *this;
}

// strcmp : �ƽ�Ű �ڵ尡 �� ū�� Ȯ�� > ���ĺ� ����. b > a
// ���� 1 : ������ �����ʺ��� ���� ������.
int String::operator>(String& other) {
    if (strcmp(this->data, other.data) > 0) 
        return 1;
    else {
        return 0;
    }
}
int String::operator==(String& other) {
    if (strcmp(this->data, other.data) == 0) 
        return 1;
    else {
        return 0;
    }
}

ostream& operator<<(ostream& stream, const String& s) {
    for (int i = 0; s.data[i] != '\0'; i++) {
        stream << s.data[i];
    }
    return stream;
}
class Person {
    friend class Queue;
    String *pname;
    int age;
public:
    Person() {
        this->pname = new String();
        this->age = 0;
    }
    Person(int age) {
        this->pname = new String();
        this->age = age;
    }
    Person(char* pname) {
        this->pname = new String(pname);
        this->age = 0;
    }
    Person(char* pname, int age) {
        this->pname = new String(pname);
        this->age = age;
    }
    Person(Person* pp) {
        this->pname = new String(pp->pname);
        this->age = pp->age;
    }
    Person(Person& pr) {
        this->pname = new String(pr.pname);
        this->age = pr.age;
    }
    ~Person() {
        delete this->pname;
    }

    Person& operator=(Person& other);
    Person& operator=(Person* other);
    int operator>(Person& other);

    friend ostream& operator<<(ostream& stream, const Person& p);
};

Person& Person::operator=(Person& other) {
    delete this->pname;
    this->pname = new String(other.pname);
    this->age = other.age;
    
    return *this;
}
Person& Person::operator=(Person* other) {
    delete this->pname;
    this->pname = new String(other->pname);
    this->age = other->age;

    return *this;
}

int Person::operator>(Person& other) {
    if (*this->pname > *other.pname) {
        return 1;
    } else if (*this->pname == *other.pname) {
        if (this->age > other.age) {
            return 1;
        }    
    } else {
        return 0;
    }
}
ostream& operator<<(ostream& stream, const Person& p) {
    stream << "name : " << *(p.pname);
    stream << ", age : " << p.age;

    return stream;
}

class Stack {
    int top;
    Person* items[100];

public:
    Stack() {
        this->top = 0; 
        for (int i = 0; i < 100; i++) {
            this->items[i] = nullptr;
        }
    }
    ~Stack() {
        for (int i = 0; i < this->top; i++) {
            delete this->items[i];
        }
    }
    int Push(Person& p);
    Person* Pop();
    int getLength();
    void show();
    friend ostream& operator<<(ostream& stream, const Stack& stack);
    Stack& operator=(Stack& other);
};
int Stack::Push(Person& p) {
    if (this->top == 100) {
        cout << "Stack is full" << endl;
        return 0;
    }
    cout << "top : " << this->top << "Person : " << p << endl;
    Person* tmp = new Person(p);
    this->items[this->top] = tmp;
    this->top += 1;

    return 1;
}
Person* Stack::Pop() {
    if (this->top == 0) {
        cout << "Stack is empty" << endl;
        return nullptr;
    }
    this->top -= 1;
    Person* result = this->items[top];
    this->items[top] = nullptr;

    return result;
}
int Stack::getLength() {
    return this->top;
}

void Stack::show() {
    cout << "stack show : " << endl;
    for (int i = 0; i < this->top; i++) {
        cout << *(this->items[i]) << endl;
    }
    return;
}
ostream& operator<<(ostream& stream, const Stack& stack) {
    for (int i = 0; i < stack.top; i++) {
        stream << *(stack.items[i]) << endl;
    }

    return stream;
}
Stack& Stack::operator=(Stack& other){
    if (this != &other) {
        for (int i = 0; i < this->top; i++) {
            delete this->items[i];
            this->items[i] = nullptr;
        }
        for (int i = 0; i < other.top; i++) {
            Person* tmp = new Person(other.items[i]);
            this->items[i] = tmp;
        }
        this->top = other.top;
    }

    return *this;
}

int main() {
    Stack s1;
    Stack s2;
    Person* p[10];
    while (1)
    {
        char sname[20];
        int year;

        int select;
        cout << "\n���� 1: Stack �Է�(Batch), 2: Push(ȭ�� �Է�), 3. PoP �� ��ü�� ���, 4: ���� ��� ��ü ���," << endl;
        cout <<"5. ������ ��� ��ü�� pop�Ͽ� Person ��ü �迭�� ���� �� �����ϱ�, 6. ������ ġȯ(s1 = s2;), 7.quit = > ";
        cin >> select;
        switch (select) {
            case 1: {//AddBatch
                cout << endl << "10�� ť�� �Է�" << endl;
                Person p0;
                Person p1("kim");
                Person p2(23);
                Person p3("park", 24);
                
                p[0] = &p0; p[1] = &p1; p[2] = &p2; p[3] = &p3;
                for (int i = 0; i < 4; i++) {
                    s2.Push(*p[i]);
                }
                break;
            }
            case 2: {//AddOne 
                cout << endl << "1�� ��ü�� ȭ�� �Է¹޾�" << endl;

                cin >> sname >> year;
                Person px(sname, year);
                s2.Push(px);
                break;
            }
            case 3: {//Delete
                cout << endl << "Delete" << endl;
                Person* result_ptr = s2.Pop();
                if (result_ptr != nullptr) {
                    Person result = *result_ptr;
                    cout << "������ ��ü:";
                    cout << result;
                }
                break;
            }
            case 4: {//Stack�� �ִ� ��� ��ü�� ���
                //cout << s2.getLength() << endl;
                cout << s2;
                break;
            }
            case 5: {//stack�� �ִ� ��� ��ü�� pop�Ͽ� �����ϱ�
                Person* arry[50];
                int stack_length = s2.getLength();
                for (int i = 0; i < stack_length; i++) {
                    arry[i] = s2.Pop();
                }
                //arry[] ��ü�� person�� �̸����� �����ϱ� > person�� �� ������ ����
                //���ĵ� ��ü�� ����ϱ�
                for (int i = 0; i < stack_length; i++) {
                    for (int j = 0; j < stack_length - i - 1; j++) {
                        if (*(arry[j]) > *(arry[j + 1])) {
                            Person* tmp = arry[j];
                            arry[j] = arry[j + 1];
                            arry[j + 1] = tmp;
                        }
                    }
                }
                for (int i = 0; i < stack_length; i++) {
                    cout << *arry[i] << endl;
                }
                break;
            }
            case 6: {
                s1 = s2; //s2�� ��� ��ü�� s1�� ����. s2�� ���ư��� s1�� ��ü���� ���� 
                s1.show();
                s2.~Stack();
                cout << "after s2 deleted" << endl;
                s1.show();
            }
            default: {
                exit(0);
                break;
            }
        }
    }
    system("pause");
    return 1;
    //���α׷� ����ÿ� run-time�� ������ �Ҹ��� ������ delete ȣ�� ���
}


