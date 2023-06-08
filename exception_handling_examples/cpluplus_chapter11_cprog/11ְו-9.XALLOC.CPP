// 11장-9.XALLOC.CPP   11.7 new를 사용한 메모리 할당
#include <stdexcept>
#include "stdlib.h"
#include <cstring>
#include <iostream>
using namespace std;
using std::exception;
class BigClass{
public:
    char bigText[5000];
};

void main(){
    BigClass * hugeArray[20];
    int tmp1;
    try{
        for (tmp1=0; tmp1<20; tmp1++){
            hugeArray[tmp1] = new BigClass;
            cout << "Memory allocated for element" << tmp1 << endl;
        }       
        cout << endl;
        cout << "All requested memory allocated..." << endl;
        cout << endl;

        for (tmp1=0; tmp1<20; tmp1++){
            delete hugeArray[tmp1];
            cout << "Memory de-allocated for element " << tmp1 << endl;
        }
    }
	/*
	catch (const char*) //바람직한 code 아님
	{
		cout << "new error";
		exit(0);
	}
	*/
	//*
	catch(const std::bad_alloc eb)
    //catch (std::exception eb)
	{
        cout<< "No more memory for element " << eb.what() << endl;
        for (int tmp2=0; tmp2<tmp1; tmp2++){
            delete hugeArray[tmp2];
            cout << "Memory de-allocated for element " << tmp2 
                  << endl;
        }
    }
	//*/
	system("pause");
}