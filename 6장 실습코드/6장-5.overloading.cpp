//6장-5.overloading.cpp
#include <iostream>
using namespace std;

class Point {
    int x,y;
public:
	Point(int i = 0, int j = 0) :x(i), y(j) {}
	void print() const {cout<<"x = "<<x<<", y = "<<y<<endl;}
};
class indirectPoint {
    Point *p;
public:
    indirectPoint(Point *x) : p(x) {}
    Point *operator->() const {
		cout<<"smart pointer->: ";
       return p;
    }
    Point &operator*() const {
		cout<<"smart pointer*: ";
       return *p;

    }
};
void main() {
   indirectPoint ip1 = new Point(1,1);
   ip1->print();

  Point *p1 = new Point(2,2);//보통 pointer
  indirectPoint ip2 = new Point(3,3);//smart pointer
  //p1, ip2에 대하여 호출되는 pointer(0 함수가 달라짐
  p1->print();
  //ip2->print();
  ip2.operator->()->print();

  (*p1).print();
  (*ip2).print();
  //ip2.operator*().print(); //주석을 풀고 실습
  system("pause");
}