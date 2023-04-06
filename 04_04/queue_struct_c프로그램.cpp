#include <stdio.h>
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

void Add(struct Queue &, int&);
int Delete(struct Queue &);
void InitializeQueue(struct Queue&);
struct Queue {
    int front, rear;
    int queue[100];
};


int main() {
    struct Queue q1, q2;
    InitializeQueue(q1);
    InitializeQueue(q2);
    int result = 0;
    int n = 10;
    Add(q1, n);//첫번째 queue를 사용
    result = Delete(q1);
    cout << "result = " << result << endl;
    int m = 20;
    Add(q2, m);//두번째 queue를 사용
    result = Delete(q2);
    cout << "result2 = " << result << endl;
    q2.queue[q2.rear] = 30; q2.rear++;//struct Queue가 전역변수 이므로 임의 장소에서 수정 - 디버깅 추적이 어렵다 
    result = Delete(q2);
    cout << "result2 = " << result << endl;
    system("pause");
    return 1;
}
void InitializeQueue(struct Queue& q) {
    q.front = q.rear = 0;
}
void Add(struct Queue &q, int& x) {
    if (q.rear == 100) {
        cout << "queue is full" << endl;
        return;
    }
    q.queue[q.rear++] = x;
}

int Delete(struct Queue& q) {
    if (q.front == q.rear) {
        printf("queue empty");
        return 0;
    }
    int temp = q.queue[q.front];
    q.front++;
    return temp;
}