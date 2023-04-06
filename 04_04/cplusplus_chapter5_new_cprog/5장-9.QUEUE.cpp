// 5장-9.QUEUE.CPP   5.6 class queue
#include <iostream>
#include "5장-8.QUEUE.h"
using namespace std;
Queue :: Queue (){
	// queue의 있는 대기자 숫자로서 초기 상태는 0으로 한다
	number = 0;
}
void Queue :: Push (Person p){
	// queue의 끝에 사람을 추가한다
	// queue의 전체 대기자 수를 1 증가한다
	line [number] = p;
	number++;
	cout<<number<<endl;
	// queue의 삽입 내용을 출력한다
	cout<<p.Name()<<" has joined the queue"<<endl;
}

Person Queue :: Pop (){
	// queue에서 제거할 사람을 선택한다("줄(line)의 첫 번째 사람")
	Person  p = line [0];
	// queue의 줄을 앞으로 이동한다. 모든 사람을 앞으로 하나씩 이동한다
	for (int i = 1; i < number; i++) 
		line [i-1] = line [i];
	number --;
	// queue의 전체 대기자 숫자를 1 감소한다
	// queue의 삭제 내용을 출력한다
    cout << p.Name () << " has left the queue" << endl;
	// queue의 줄에서 첫 번째 사람을 삭제하여,
	// 임시 변수 p에 저장한다
    return p;
}
int Queue :: Number (){
	// queue에 있는 대기자 숫자를 return한다
    return number;
}