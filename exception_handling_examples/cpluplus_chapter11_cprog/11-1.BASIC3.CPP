// 11-1.BASIC3.CPP 11.3 예외 처리와 교정

#include <iostream>
using namespace std;

class ZeroDenominator{};
class ZeroDivision{};
class CloseFunction{};

class Negative{
public:
    int* pValue;
    Negative (int* pn):
        pValue(pn){}
};

int divide(int& num1, int& num2){
    if(num1 == 0){
        if (num2 == 0)
            throw CloseFunction();
        else
            throw ZeroDenominator();
    }
    if(num2 == 0)
        throw ZeroDivision();	
    if(num1 < 0)
        throw Negative(&num1);
    if(num2 < 0)
        throw Negative(&num2);
    return (num1/num2);
}

int divideCheck(int& num1, int& num2){
    int num;
    try{
        num = divide(num1, num2);
    }
    catch(Negative neg){
        *neg.pValue = - *neg.pValue;
        cout<< "A number was negative... reversing it to positive" 
             << endl; 
        num = divideCheck(num1, num2);
    }
    return num;
}

void main(){
    int num1, num2;
    int flag = 1;
    cout << "This is a dividing machine for positive integers!" 
          << endl << "(Input 0 0 value to end)" << endl << endl;
    while(flag == 1){
        cout<< "Input two values: ";
        cin >> num1 >> num2;
        try{
            int num3 = divideCheck(num1, num2);
            cout<< num1 << " / " << num2 << " = " << num3 << endl;
        }
        catch(CloseFunction){
            cout << "A dividing machine will be closd" << endl;
            flag = 0;
        }
        catch(ZeroDenominator){
            cout << "ERROR: Denominator is 0" << endl;
        }
        catch(ZeroDivision){
            cout << "ERROR: Division by 0" << endl;
        }
        catch(Negative neg){
            cout<< "Ouch!" << endl;
            throw; 
        }
    }
    system("pause");
}