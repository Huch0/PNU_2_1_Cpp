#include <stdlib.h>
#include <iostream>
/*
1. queue를 C의 배열을 사용한 구현
2. queue를 C의 struct를 사용한 구현
3. queue를 C++의 class를 사용 > 큐 데이터 멤버가 정수인 경우의 구현
4. queue를 C++의 class를 사용 > 큐 데이터 멤버가 person 객체 > person의 name이 char* 문자열로 구현
5. queue를 C++의 class를 사용 > 큐 데이터 멤버가 person 객체 > person의 name이 string 객체로 구현
*/
using namespace std;

class Person {
    friend class Queue;
    char* pid;
    char* pname;
    int age;
public:

};

class Queue {
    int front, rear;
    Person* queue[100];
    int capacity;
public:

};



int main() {
    Queue q1(50), q2(30);
    Person p1("s1", "hong", 12);
    Person p2("s2", "kim", 22);
    Person result("s3", "a", 0);
    q1.Add(p1);//첫번째 queue를 사용
    result = q1.Delete();
    cout << "result = " << result << endl;
    int m = 20;
    q2.Add(p2);//두번째 queue를 사용
    result = q2.Delete();
    cout << "result2 = " << result << endl;

    system("pause");
    return 1;
}
