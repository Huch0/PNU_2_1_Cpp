// 11-5.XALLOC2.CPP  11.7 new를 사용한 메모리 할당
#include <new>
#include <iostream>
#include <cstring>
using namespace std;

class BigClass{
public:
    char bigText[300000000];
};

class BigUser{
private:
    BigClass * pBig;
    static long totalMemory;

public:
    BigUser(){
        cout << "Entering the default constructor..." << endl;
        pBig = new BigClass;
        totalMemory += sizeof(*pBig);
        cout << "Default constructor:" << sizeof(*pBig)
              << "bytes used for a total of" << totalMemory << endl;
    }

    BigUser(const BigUser & bu){
        cout << "Entering the copy constructor..." << endl;
        pBig = new BigClass;
        totalMemory += sizeof(*pBig);
        
        cout << "Copy constructor executed:" << sizeof(*pBig)
              << "bytes used for a total of" << totalMemory << endl;
    }

    ~BigUser(){
        totalMemory -= sizeof(*pBig);
        //optionally add this code:
        /*cout << "Destructor: " << sizeof(*pBig)
                << "bytes freed" << endl;*/
        delete pBig;
    }

    void Fake(){
        cout << "Fake called" << endl;
    }
};

long BigUser::totalMemory = 0;

BigUser GlobalUserFunction(BigUser bu){
    BigUser bu2;
    cout << "GlobalUserFunction called" << endl;

    bu.Fake();
    bu2.Fake();

    return bu2;
}

void main(){
    try{
        BigUser bu, secondBu, bubu;
        BigUser bu1;
        BigUser bu2 = GlobalUserFunction(bu1);
        bu2.Fake();
    }
    catch (bad_alloc exc){
        cout << "Something went wrong: "  <<exc.what() << endl;
    }
	system("pause");
}