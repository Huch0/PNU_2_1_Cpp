//testQueue2019 coding exam, 19.4.25/Thursday
#include <iostream>
using namespace std;
#include <stdlib.h>
class Person {
private:
	string name;
	// String name; //실습 코딩 필요
public:
	Person(string n) :
		name(n) {}
	Person() : name(string()) {}
	string Name() {
		return name;
	}
};
class Queue {
private:
	Person    line[20];
	static int number;
public:
	Queue();
	void Push(Person p);
	Person Pop();
	static int Number();
};
Queue::Queue() {
	number = 0;
}
void Queue::Push(Person p) {
	line[number] = p;
	number++;
	cout << number << endl;
	cout << p.Name() << " has joined the queue" << endl;
}

Person Queue::Pop() {
	Person  p = line[0];

	for (int i = 1; i < number; i++)
		line[i - 1] = line[i];
	number--;

	cout << p.Name() << " has left the queue" << endl;
	return p;
}
int Queue::Number() {
	return number;
}
int Queue::number = 0;
void main() {
	Person p;
	Queue q;
	Queue t;
	while (1)
	{
		int select;
		//testing plan: A) run 1. and 3, B) run 2 and 3
		cout << "\nSelect command 1: input of Person, 2: push person to Queue q, 3. push person to Queue t, 4: pop of q, 5: pop of t, 6. display of q and t, 7. counting of waiting persons, 8. Quit => ";
		cin >> select;
		switch (select) {
		case 1:
			cin >> p;
			break;

		case 2:
			q.Push(p);
			break;

		case 3:
			t.Push(p);
		case 4:
			p = q.Pop();
			break;
		case 5:
			p = t.Pop();
			break;
		case 6:
			cout << q << t;
			break;
		case 7:
			cout << q.Number();
			break;
		default:
			exit(0);
			break;
		}
	}

	system("pause");
}