// 6장-8.POINTCLS.CPP
#include <iostream>
#include "6장-6.POINTCLS.h"
using namespace std;
//*
//주석처리시에 LNK2019 오류 발생: PointerClass() 외부 기호에서 확인하지 못했습니다
PointerClass::PointerClass(const PointerClass& pc){
    // member들을 복사함
    number = pc.number;
    // 새로운 pointer를 할당하고 pointer 값을 복사함
    pointer = new int;
    *pointer = *(pc.pointer);
    cout << "New pointer - address:" << pointer
          << ", value:" << *pointer << endl;
}
//*/
PointerClass::PointerClass (int a, int b){
        number = a;
        pointer = new int;
        *pointer = b;
        cout << "New pointer - address:" << pointer<< ", value:" << *pointer << endl;
}
    // 소멸자
PointerClass::~PointerClass (){
        cout << "Deleting pointer - address:" << pointer
              << ", value:" << *pointer << endl;
        delete pointer;
}
void PointerClass::Print (){
        cout << "The pointer value is " << *pointer
              << " and its address is " << pointer << endl;
}