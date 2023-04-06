// 5-5.QUE-USE.CPP  5.6 class queue
#include <iostream>
#include "5장-8.QUEUE.h"
using namespace std;
#include <stdlib.h>
/*
1) 내용
본 source code는 class Queue를 이용하여 객체를 생성, queue에 삽입 또는 삭제를 해보는 예제이다.
2) 방법
 가. 주석 1번을 해제하여 객체를 생성하고 queue에 삽입, 삭제하는 과정을 자세히 살펴보자.
 나. 주석 2번을 해제하여 Queue객체에 대한 pointer를 이용하여 queue에 삽입, 삭제하는 과정을 살펴보자.
 다. student.h 를 정의하여 객체를 생성하고 queue에 삽입, 삭제과정을 직접 실습해보자.
*/
void main (){
    //주석 1번
    //*
    Queue q;
	Queue t;//t의 사용시에도 실습
	t = q; // 구현 실습
    // queue에 있는 대기자 숫자를 출력한다
    cout << "queue에 있는 사람은 "<< q.Number () << " 명 입니다." 
         << endl << endl;
    // queue에 몇 사람을 추가한다
    q.Push ( Person ("홍길동") );
    q.Push ( Person ("사임당") );
    q.Push ( Person ("류성룡") );
    q.Push ( Person ("정약용") );
    cout << "queue에 있는 사람은 "
         << q.Number () << " 명 입니다." << endl << endl;
    // queue의 첫 번째 사람을 제거한다
    q.Pop();
    cout << "queue에 있는 사람은 "<< q.Number () << " 명 입니다." 
         << endl << endl;
    // queue에 새로 도착한 사람을 추가한다
    q.Push ( Person ("홍대용") );
    cout << "queue에 있는 사람은 " << q.Number () << " 명 입니다." 
         << endl << endl;
    // queue 전체를 비운다
    cout << "모든 사람이 queue에서 나갑니다." << endl<<endl;
    while (q.Number () > 0){
       q.Pop ();
       cout << "queue에 있는 사람은 " << q.Number () << " 명 입니다." 
            << endl << endl;
    }
    //*/
    //주석 2번
    /*
    //Queue 객체의 pointer를 이용하여 q의 영역에 Person객체의 입력과 객체 수를 출력
    Queue *pq = &q;
    (*pq).Push ( Person ("홍경래") );
    cout << "queue에 있는 사람은 "
         << (*pq).Number () << " 명 입니다." << endl << endl;
    (*pq).Pop();
    */
	system("pause");
}