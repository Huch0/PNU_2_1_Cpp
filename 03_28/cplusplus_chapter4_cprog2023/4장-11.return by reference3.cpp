//4장-11 return by reference3.cpp   4.4.4 reference에 의한 함수 return 값
#include <iostream>
using namespace std;
int& sub(int a, int b);

void main(){
    int c = 1, d = 2;
    int &result = sub(c,d);
    cout<<"main():: result = "<< result<<endl; //오류 값을 출력
    printf("main()::sub() = %d\n", sub(c, d));//올바른 값을 출력
	system("pause");
}
int& sub(int a, int b){
    int temp;
    temp = a+b;

	printf("int& sub(int,int)::&temp = %p   ", &temp);
    cout << " a = " << a << " b = " << b << " temp = " << temp << endl;
    return temp;//local variable의 주소가 return되는 것을 확인 - 나중에 stack에서 사라질수 있어 위험
}

