//4장-12. Cascade.cpp   4.4.4 reference에 의한 함수 return 값
// return by reference의 전형적인 사례로서 6장 이후 학습할 주요 대상
//4장에서는 단순 실행하여 보는 것으로 실습함
#include <iostream>

using namespace std;
class Cascade{ 
private:
	float real;
	float image; 
public:
	Cascade() { real = 0.0; image = 0.0; }
	Cascade(float r, float i) : real(r), image(i) { }
	void OutCascade() const { cout<<real<<" + "<<image<<"i"<<endl; }
	Cascade& operator +(const Cascade &T);

};


//*
Cascade& Cascade::operator+(const Cascade &T){
	this->image = this->image + T.image;
	this->real = this->real + T.real; 
	cout << "operator+(const CasCade&):: ";

	this->OutCascade();
	return *this;
}
//*/
/*
// 다음 코드는 고의 오류가 있는 코드임 - 실행하여 값이 wrong인 것을 확인

    Cascade& Cascade::operator +(const Cascade& T) {
	Cascade C;
	C.image = image + T.image;
	C.real = real + T.real;
	cout << "operator+(const CasCade&):: "; C.OutCascade();
	return C;//return local variable?
}
*/

void main(void){
	Cascade C1(1.1,2.2);
	cout << "C1 = "; C1.OutCascade();
	Cascade C2(3.3,4.4);
	cout << "C2 = "; C2.OutCascade();

	Cascade C3(7.7,9.9); 
	cout << "C3 = "; C3.OutCascade();
	Cascade C4;
	C4 = C1 + C2 + C3;
	cout << "C4 = "; C4.OutCascade();
	system("pause");
}