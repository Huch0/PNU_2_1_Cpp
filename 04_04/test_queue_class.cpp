#include <stdlib.h>
#include <iostream>
using namespace std;
/*
1. queue를 C의 배열을 사용한 구현
2. queue를 C의 struct를 사용한 구현
3. queue를 C++의 class를 사용 > 큐 데이터 멤버가 정수인 경우의 구현
4. queue를 C++의 class를 사용 > 큐 데이터 멤버가 person 객체 > person의 name이 char* 문자열로 구현
5. queue를 C++의 class를 사용 > 큐 데이터 멤버가 person 객체 > person의 name이 string 객체로 구현
*/

class Queue {
    int front, rear;
    int* queue;
public:

};

int main() {
    Queue q1(50), q2(30);

    int result = 0;
    int n = 10;
    q1.Add(n);//첫번째 queue를 사용
    result = q1.Delete();
    cout << "result = " << result << endl;
    int m = 20;
    q2.Add(m);//두번째 queue를 사용
    result = q2.Delete();
    cout << "result2 = " << result << endl;
    //q2.queue[q2.rear] = 30; q2.rear++;//struct Queue가 전역변수 이므로 임의 장소에서 수정 - 디버깅 추적이 어렵다 
    result = q2.Delete();
    cout << "result2 = " << result << endl;
    system("pause");
    return 1;
}
