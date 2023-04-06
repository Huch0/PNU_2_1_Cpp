#include <stdlib.h>
#include <iostream>
/*
queue를 C++의 class를 사용 > 큐 데이터 멤버가 person 객체 > person의 name이 char* 문자열로 구현
*/
using namespace std;

class Person {
    friend class Queue;
    char* pid;
    char* pname;
    int age;
public:
    friend ostream& operator<<(ostream& stream, const Person& p);
    //Person p0("s1", "hong", 12);
    Person(char* pid, char* pname, int age) {
        this->pid = new char[strlen(pid) + 1];
        strcpy(this->pid, pid);

        this->pname = new char[strlen(pname) + 1];
        strcpy(this->pname, pname);

        this->age = age;
    }
    Person(Person& other) {
        if (this != &other) {
            delete[] this->pid;
            this->pid = new char[strlen(other.pid) + 1];
            strcpy(this->pid, other.pid);


            delete[] this->pname;
            this->pname = new char[strlen(other.pname) + 1];
            strcpy(this->pname, other.pname);

            this->age = other.age;
        }
    }
    ~Person() {
    };


};

ostream& operator<<(ostream& stream, const Person& p) {
    stream << "id : ";
    for (int i = 0; p.pid[i] != '\0'; i++) {
        stream << p.pid[i];
    }
    stream << ", name : ";
    for (int i = 0; p.pname[i] != '\0'; i++) {
        stream << p.pname[i];
    }
    stream << ", age : " << p.age;
    return stream;
}

class Queue {
    int front, rear;
    Person* queue[100];
public:
    Queue() {
        this->front = 0;
        this->rear = 0;
    }
    ~Queue() {};

    void Add(Person& pp);
    Person& Delete();
    void Show();


};
void Queue::Add(Person& pp) {
    if (this->rear == 100) {
        cout << "queue is full" << endl;
        return;
    }
    //cout << pp << &pp << endl;
    this->queue[this->rear] = &pp;
    this->rear += 1;
    return;
}
Person& Queue::Delete() {
    if (this->front == this->rear) {
        cout << "queue empty" << endl;
        return Person("","",0);
    }
    Person result = *(this->queue[this->front]);
    this->queue[this->front] = 0;
    this->front += 1;

    return result;
}
void Queue::Show() {
    for (int i = this->front; i < this->rear; i++) {
        //cout << this->front << ", " << this->rear << endl;
        //cout << i << ", ";
        //cout << this->queue[i] << endl;
        cout << *(this->queue[i]) << endl;
    }
    return;
}

int main() {
    Person* p[10];
    Queue q1, q2;
    while (1)
    {
        char sno[10];
        char sname[20];
        int year;
        int select;
        cout << "\nSelect command 1: AddBatch(), 2: AddOne(1개 객체를 화면 입력받아), 3. Delete, 4: Show, 5. quit => ";
        cin >> select;
        switch (select) {
            case 1: {
                //AddBatch
                cout << endl << "10개 큐에 입력" << endl;   
                Person p0("s1", "hong", 12);
                Person p1("s2", "kim", 22);
                Person p2("s3", "lee", 23);
                Person p3("s4", "park", 24);
                p[0] = &p0; p[1] = &p1; p[2] = &p2; p[3] = &p3;
                for (int i = 0; i < 4; i++) {
                    //cout << *p[i] << endl;
                    q1.Add(*p[i]);
                }
                break;
            }
            case 2: {
                //AddOne
                cout << endl << "1개 객체를 화면 입력받아" << endl;
                cin >> sno >> sname >> year;
                Person px = Person(sno, sname, year);
                q1.Add(px);
                break;
            }

            case 3: {
                //Delete
                cout << endl << "Delete" << endl;
                Person result = q1.Delete();
                cout << "삭제된 객체:";
                q2.Add(result);
                cout << result;
                break;
            }
            case 4: {
                //Show - 큐의 상태를 출력
                cout << endl << "front = "  << endl;
                cout << "rear = " << endl;
                //큐에 있는 객체들을 show()를 사용하여 출력
                q1.Show();
                cout << "삭제된 객체들을 저장한 q2의 객체들을 출력";
                q2.Show();
                break;
            }
            default:
                exit(0);
                break;
        }
    }
    
    system("pause");
    return 1;
}
