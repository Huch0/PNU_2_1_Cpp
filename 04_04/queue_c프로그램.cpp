#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
/* queue를 C의 배열을 사용한 구현, 한 프로그램에 2개의 큐를 만드는 방법으로,
hard-coding 문제가 생긴다 
*/
/*
1. queue를 C의 배열을 사용한 구현
2. queue를 C의 struct를 사용한 구현
3. queue를 C++의 class를 사용 > 큐 데이터 멤버가 정수인 경우의 구현
4. queue를 C++의 class를 사용 > 큐 데이터 멤버가 person 객체 > person의 name이 char* 문자열로 구현
5. queue를 C++의 class를 사용 > 큐 데이터 멤버가 person 객체 > person의 name이 string 객체로 구현
*/
void Add(int& x);
int Delete();
int front=0, rear=0;
int queue[100];

void Add2(int& x);
int Delete2();//hard-coding을 안할려면 queue[]를 parameter로 전달
int front2=0, rear2=0;
int queue2[100];

void Add3(int [], int &, int &, int&);//hard-coding 대신에 queue를 parameter로 전달하는 방식
int Delete3(int[], int &, int&);//hard-coding 대신에 queue를 parameter로 전달하는 방식

int main() {
    int n = 10;
    int result = 0;
    Add(n);//첫번째 queue를 사용
    result = Delete();
    cout << "result = " << result << endl;

    int m = 20;
    Add2(m);//두번째 queue를 사용
    result = Delete2();
    cout << "result = " << result << endl;
    system("pause");
    return 1;
}
void Add(int& x) {
    if (rear >= 100) {
        printf("queue full");
        return;
    }
    queue[rear++] = x;
    return;
}

int Delete() {
    if (front == rear) {
        printf("queue empty");
        return 0;
    }
    return queue[front++];
}

void Add2(int& x) {
    if (rear >= 100) {
        printf("queue full");
        return;
    }
    queue[rear++] = x;
    return;
}
int Delete2() {
    if (front == rear) {
        printf("queue empty");
        return 0;
    }
    return queue[front++];
}
