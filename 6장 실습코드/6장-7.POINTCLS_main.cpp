// 6¿Â-7.POINTCLS_main.CPP
#include <iostream>
#include "6¿Â-6.POINTCLS.h"
using namespace std;

int main (void){
    cout << "Creating Object A" << endl;
    PointerClass objA (5, 8);
   {
        cout << endl;
        cout << "Creating Object B" << endl;
        PointerClass objB = objA;
        objB.Print();
        cout << endl;
        cout << "Object B is going out of scope" << endl;
    }
    cout << endl;
    cout << "Look at whether Object A has a dangling pointer or not" << endl;
    objA.Print ();
    cout << endl;
    cout << "Object A is going out of scope" << endl;
	system("pause");
	return 1;
}