#include <iostream>
//º¹¼Ò¼ö¿¡ ´ëÇÑ »çÄ¢¿¬»êÀÌ °¡´ÉÇÏµµ·Ï ±¸ÇöÇÑ´Ù. main() ÇÔ¼ö´Â ¼öÁ¤ÇÏ¸é ¾ÈµÈ´Ù
using namespace std;
class ComplexNumber {
private:
	float real;
	float imaginary;
public:
	ComplexNumber(float real, float imaginary) {
		this->real = real;
		this->imaginary = imaginary;
	}
	~ComplexNumber() {};

	friend ostream& operator<<(ostream& stream, const ComplexNumber& p);
	
	ComplexNumber add(const ComplexNumber& other);
	ComplexNumber subtract(const ComplexNumber& other);
	ComplexNumber multiply(const ComplexNumber& other);
	ComplexNumber divide(const ComplexNumber& other);
	//assignment
	ComplexNumber& operator=(const ComplexNumber& other);
	//cascading add
	ComplexNumber operator+(const ComplexNumber& other);
	
};

ostream& operator<<(ostream& stream, const ComplexNumber& p) {
	stream << p.real << " + " << p.imaginary << "i";
	return stream;
}

ComplexNumber ComplexNumber::add(const ComplexNumber& other) {
	this->real += other.real;
	this->imaginary += other.imaginary;

	return *this;
}

ComplexNumber ComplexNumber::subtract(const ComplexNumber& other) {
	cout << endl << *this << " - " << other << endl;

	this->real -= other.real;
	this->imaginary -= other.imaginary;

	return *this;
}

// (a+bi) * (c+di) = ac+adi+bci-bd = (ac-bd)+(ad+bc)i
ComplexNumber ComplexNumber::multiply(const ComplexNumber& other) {
	float a = this->real;
	float b = this->imaginary;
	float c = other.real;
	float d = other.imaginary;

	this->real = a * c - b * d;
	this->imaginary = a * d + b * c;

	return *this;
}

// (a+bi) / (c+di) = (a+bi)(c-di)/(c^2+d^2) 
//                 = (ac-adi+bci+bd)/(c^2+d^2)
//                 = ((ac+bd)+(bc-ad)i)/(c^2+d^2)
//                 = (ac+bd)/(c^2+d^2)+(bc-ad)/(c^2+d^2)i
ComplexNumber ComplexNumber::divide(const ComplexNumber& other) {
	cout << endl << *this << " / " << other << endl;

	float a = this->real;
	float b = this->imaginary;
	float c = other.real;
	float d = other.imaginary;

	this->real = (a * c + b * d) / (c * c + d * d);
	this->imaginary = (b * c - a * d) / (c * c + d * d);

	return *this;
}
//assignment
ComplexNumber& ComplexNumber::operator=(const ComplexNumber& other) {
	if (this != &other) {
		this->real = other.real;
		this->imaginary = other.imaginary;

		return *this;
	}
}
//cascading add
ComplexNumber ComplexNumber::operator+(const ComplexNumber& other) {
	cout << endl << *this << " + " << other << endl;
	ComplexNumber result(0, 0);
	result.real = this->real + other.real;
	result.imaginary = this->imaginary + other.imaginary;

	return result;
}

int main(void) {
	while (1)
	{
		ComplexNumber a(1, 1), b(2, 2), c(3, 3), d(4, 4);
		int select;	
		cout << "\nSelect command 1: µ¡¼À, 2: »¬¼À, 3. °ö¼À, 4: ³ª´°¼À, 5. ¿¬¼âµ¡¼À, 6. quit => ";
		cin >> select;
		switch (select) {
		case 1:
			cout << endl << "µ¡¼À d = a + b + c" << endl;
			cout << endl << "a = " << a << ", b = " << b << ", c = " << c << endl;
			d = a.add(b.add(c));
			cout << "d = " << d << endl;
			break;
		case 2:
			cout << endl << "»¬¼À d = a - b - c" << endl;
			cout << endl << "a = " << a << ", b = " << b << ", c = " << c << endl;
			d = a.subtract(b.subtract(c));
			cout << "d = " << d << endl;
			break;

		case 3:
			cout << endl << "°ö¼À d = a * b * c" << endl;
			cout << endl << "a = " << a << ", b = " << b << ", c = " << c << endl;
			d = a.multiply(b.multiply(c));
			cout << "d = " << d << endl;
			//e = a - b - c - d;
			break;
		case 4:
			cout << endl << "³ª´°¼À d = a / b / c" << endl;
			cout << endl << "a = " << a << ", b = " << b << ", c = " << c << endl;
			d = a.divide(b.divide(c));
			cout << "d = " << d << endl;
			cout << a;
			break;
		case 5:
			cout << endl << "cascading µ¡¼À d = a + b + c" << endl;
			cout << endl << "a = " << a << ", b = " << b << ", c = " << c << endl;
			d = a + b + c;
			cout << "d = " << d << endl;
			break;
		default:
			exit(0);
			break;
		}
	}
	system("pause");
	return 1;
}