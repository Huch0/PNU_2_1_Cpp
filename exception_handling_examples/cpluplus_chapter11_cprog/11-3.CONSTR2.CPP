// 11-3.CONSTR2.CPP  11.5 생성자의 중지
#include <iostream>
using namespace std;

class ZeroError
{ };
class Base{
protected:
    int value;
public:
    Base(int num) : value (num){
        cout << "Base class constructor called for "<< value << endl;
    }
    ~Base( ){
        cout << "Base class destructor called for "<< value << endl;
    }
};
class Derived: public Base{
public:
    Derived (int num) : Base (num){
        cout << "Entering the derived class constructor for "<< value << endl;
        if (num == 0)
            throw(new ZeroError); 
    }
    ~Derived( ){
         cout << "Derived class destructor called for "<< value << endl;
    }
};

void main( ){
    try {
        //Derived one(999);
        Derived two(0);
        // …operations on the objects
    }
    catch (ZeroError*){
        cout << "Error: zero value!" << endl;
    }
	system("pause");
}