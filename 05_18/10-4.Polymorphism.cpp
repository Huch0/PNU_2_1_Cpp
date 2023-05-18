//[실습예제 10.2]
// 10-4.Polymorphism.cpp  10.3 상속과 polymorphism을 사용하여 genericity 표현
/*
* 정수 배열의 정렬 > 스트링 배열의 정렬 > 객체 배열의 정렬 > Person *data[]; 또는 Person **data;로 구현 연습이 필요 
*/
#include <iostream>
using namespace std;
//genericity를 표현하는 coding으로 macro 대체 효과를 확인
/*
실습 2
 1) 내용
  본 source code는 상속을 사용하여 다양한 데이터 타입의 객체들을 다루는 방법을 알아보는 것이다.
 2) 방법
  가. 각 class간의 상속 관계를 확인해보자.
  나. 같은 구조의 stack에 각기 다른 class의 객체가 어떤 방식으로 저장되는지 확인해보자.
  다. 같은 구조의 stack에서 각기 다른 class의 객체가 어떤 방식으로 출력되는지 확인해보자.
  라. 주석4를 통해 Stack.Pop()을 수행할 때 type casting이 없을 경우 어떤 오류가 발생하는지 확인해보자.
*/
class GenericObject {};
class Stack{
    GenericObject* data[50];
    int nElements;
public:
    Stack(): nElements(0) {}
    //stack에 한 요소를 추가
    void Push(GenericObject* item);
    //stack으로부터 한 요소를 얻음
    GenericObject* Pop();
    //stack에 실제로 저장된 요소 개수
    int Number();
    //stack이 비었나?
    int Empty();
};

void Stack::Push(GenericObject* item){
    data[nElements] = item;
    nElements++;
}
GenericObject* Stack::Pop(){
    nElements--;
    return data[nElements];
}
int Stack::Number(){
    return nElements;
}
int Stack::Empty(){
    return (nElements==0);
}
//generic인 것으로부터 유도된 정수 class를 정의
class IntObject : public GenericObject{
public:
    int data;
    IntObject(int num): data(num)  {}
};

class doubleObject : public GenericObject{
public:
    double data;
    doubleObject(double num): data(num) {}
};

class floatObject : public GenericObject{
public:
    float data;
    floatObject(float num):  data(num)  {}
};

void main(){
    //* 주석 1
    //generic stack을 정의
    Stack genericStack_1;

    genericStack_1.Push(new IntObject(500));
    genericStack_1.Push(new IntObject(1992));
    genericStack_1.Push(new IntObject(33));
    genericStack_1.Push(new IntObject(1024));
    //stack에서 하나씩 꺼내면서 출력한다.
    //Pop 함수가 GenericObject에 대한 pointer를 return하기 때문에
    //그 객체를 접근하기 위해서 타입 변환이 필요하다.
    cout<<"-----int type stack"<<endl;
    while(! genericStack_1.Empty()){
        cout<< ((IntObject*)genericStack_1.Pop())->data << endl;
    }
    //*/
      //main()에서 두 개 이상의 stack 생성이 가능하다
    //* 주석 2
    Stack genericStack_2;
    genericStack_2.Push(new doubleObject(500.812));
    genericStack_2.Push(new doubleObject(1992.835));
    genericStack_2.Push(new doubleObject(33.877));
    genericStack_2.Push(new doubleObject(1024.809));

    cout<<endl<<"-----double type stack"<<endl;
    while(! genericStack_2.Empty()){
        cout << ((doubleObject*)genericStack_2.Pop())->data << endl;
    }
   // */

    //* 주석 3
    Stack genericStack_3;
    genericStack_3.Push(new floatObject(500.887));
    genericStack_3.Push(new floatObject(1992.811));
    genericStack_3.Push(new floatObject(33.899));
	genericStack_3.Push(new IntObject(1024)); //type check가 수행되지 않음
    genericStack_3.Push(new floatObject(1024.851));
    // stack에 float와 double값이 섞이는 것을 막을 방법이 없다
    cout<<endl<<"-----float type stack"<<endl;
    while(! genericStack_3.Empty()){
        cout << ((floatObject*)genericStack_3.Pop())->data << endl;
    }
    //*/

    /* 주석 4
    cout<<endl<<"-----float type stack"<<endl;
    while(! genericStack_3.Empty()){
      //오류 발생 확인하고 수정된 code 작성하여 확인
       cout << genericStack_3.Pop()->data << endl; //cout<<GenericObject;이 정의되지 않았음
    }
    */
    system("pause");
}