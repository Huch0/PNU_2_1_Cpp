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

// strcmp : 아스키 코드가 더 큰지 확인 > 알파벳 역순. b > a
// 리턴 1 : 왼쪽이 오른쪽보다 나중 순서임.
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
        cout << "\n선택 1: Stack 입력(Batch), 2: Push(화면 입력), 3. PoP 한 객체를 출력, 4: 스택 모든 객체 출력," << endl;
        cout <<"5. 스택의 모든 객체를 pop하여 Person 객체 배열에 저장 후 정렬하기, 6. 스택의 치환(s1 = s2;), 7.quit = > ";
        cin >> select;
        switch (select) {
            case 1: {//AddBatch
                cout << endl << "10개 큐에 입력" << endl;
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
                cout << endl << "1개 객체를 화면 입력받아" << endl;

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
                    cout << "삭제된 객체:";
                    cout << result;
                }
                break;
            }
            case 4: {//Stack에 있는 모든 객체를 출력
                //cout << s2.getLength() << endl;
                cout << s2;
                break;
            }
            case 5: {//stack에 있는 모든 객체를 pop하여 정렬하기
                Person* arry[50];
                int stack_length = s2.getLength();
                for (int i = 0; i < stack_length; i++) {
                    arry[i] = s2.Pop();
                }
                //arry[] 객체를 person의 이름으로 정렬하기 > person의 비교 연산자 구현
                //정렬된 객체를 출력하기
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
                s1 = s2; //s2의 모든 객체를 s1에 넣음. s2는 날아가도 s1의 객체들은 남게 
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
    //프로그램 종료시에 run-time이 없도록 소멸자 구현과 delete 호출 사용
}


