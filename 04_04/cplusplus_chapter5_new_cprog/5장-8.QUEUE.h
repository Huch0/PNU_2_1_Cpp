// 5장-8.QUEUE.H  5.6 class queue
// class Queue의 interface 정의
#include "5장-7.PERSON.h"
using namespace std;
class Queue {
private:
	Person    line[20];
	int        number; //static variable로 변경시 사용하도록 수정하는 실습

public:
	Queue();
	void Push(Person p);
	Person Pop();
	int Number();
};