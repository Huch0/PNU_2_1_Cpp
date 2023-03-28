//4장-18 Macro.cpp   4.8.1 C++에서 macro 대치
#include <iostream>
using namespace std;
#define ONE_MILLION 1000000
#define max(a,b) ((a>b) ? a:b)

void main(){
    float num1 = 9000;
    float num2 = ONE_MILLION;
    float greater;
    greater = max(num1, num2);
	cout<<"num2 = "<<num2<<endl<<"greater = "<<greater<<endl;
	system("pause");
}