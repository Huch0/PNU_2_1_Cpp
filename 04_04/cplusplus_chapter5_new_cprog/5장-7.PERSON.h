// 5장-7.PERSON.H   5.6 class queue
// class Person의 정의
// 표준 C++ String class를 포함한다
//#include <cstring>
#include <string>
#include <iostream>
using namespace std;

class Person{
    string name;
	
public:
    Person (string n) :
    name (n){} 

    Person () : name (string()) {}

    string Name (){
        return name;
    }
};