// 11장-2.BASIC2.CPP   11.1 예외의 기본 개념
#include <iostream>
using namespace std;
int divide (int num1, int num2){
    if (num2 == 0)
		throw ("Divide by zero") ;
    return (num1 / num2) ;
}
void main(){
    int num1, num2 ;
    cout << "This is an integer dividing machine!" << endl
          << "(Input 0 as first value to end)" << endl <<endl ;
    cout << "Input two values: " ;
	/*
    cin >> num1 >> num2 ;
    while (num1 != 0){
	*/
	while(cin>>num1>>num2){
        try{
            cout << num1 << " / " << num2 << " = " ;
            cout << divide (num1, num2) << endl ;
        }
        catch (const char * text){
            cout << "ERROR: " << text << endl ;
			continue;// 다음 실행 코드는?
        }
        cout << endl ;
        cout << "Input two values: " ;
        cin >> num1 >> num2 ;
    }
	system("pause");
}