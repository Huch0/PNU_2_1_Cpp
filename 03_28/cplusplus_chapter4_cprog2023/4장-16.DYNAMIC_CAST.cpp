//4장-16. DYNAMIC_CAST.cpp   4.5.2 dynamic_cast
#include <iostream>
//실행 확인만 하고 6장에서 실습
using namespace std;
class Parent{
public:
    virtual void Print(){}
};
class Child_1 : public Parent{
public:
    virtual void Print(){
    cout << "Child_1 is ok" << endl;
    }
};

class Child_2 : public Parent{
public:
    virtual void Print(){
        cout << "Child_2 is ok" << endl;
    }
};
void main(){
    Parent *p_1 = new Child_1;
    Parent *p_2 = new Parent;

    Child_1 *pchild1 = dynamic_cast<Child_1*> (p_1);
    //pchild1 = p_1;
    if (NULL == pchild1)
        cout << "Child_1 == NULL" << endl;
    else
        pchild1->Print();

	Child_2 *child2;
	child2	= dynamic_cast<Child_2*> (p_2);
	//child2 = p_2;
    if (NULL == child2)
        cout << "Child_2 == NULL" << endl;
    else
        child2->Print();

    Child_2 *pchild2 = dynamic_cast<Child_2*> (p_1);
    if (NULL == pchild2)
        cout << "Child_2 == NULL" << endl;
    else
        pchild2->Print();
	system("pause");
}