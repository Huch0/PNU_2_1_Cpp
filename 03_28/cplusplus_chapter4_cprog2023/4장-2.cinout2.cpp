//4장-2. CINCOUT2.cpp  4.1 변수 scope와 표준 입출력
#include <iostream>
using namespace std;
int main() {
    int age;
    float weight;
	cout<<"Get age and weight: ";//enter key 또는 space key로 구분
    cin >> age >> weight; //age부터 입력받는다 => (cin >> age) >> weight;
    cout <<"age = "<<age<<'\n'<<"weight = "<<weight<<'\n'; // (cout <<"age = ")<<age으로 실행된다
    //operator <<의 cascading 구현 실습 - 6장
	system("pause");
    return 0;
}